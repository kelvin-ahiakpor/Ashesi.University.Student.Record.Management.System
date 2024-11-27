#include "LoginForm.h"
#include "MainApplicationForm.h"
#include "DatabaseManager.h"
#include "StudentDashboardForm.h"
#include "FacultyDashboardForm.h"
#include "Student.h"
#include "ForgotPasswordForm.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

System::Void LoginForm::btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
    // Get the email and password from the textboxes
    String^ email = txtEmail->Text;
    String^ password = txtPassword->Text;

    // Validate the inputs (e.g., check for empty fields)
    if (String::IsNullOrWhiteSpace(email) || String::IsNullOrWhiteSpace(password)) {
        lblError->Text = "Please fill in both email and password.";
        return;
    }

    DatabaseManager^ db = DatabaseManager::GetInstance();

    try {
        // Open the database connection
        db->ConnectToDatabase();

        // Create the SQL query with JOIN (fixed missing comma and added space)
        String^ query = "SELECT s.StudentID, u.UserID, u.FirstName, u.LastName, u.Email, u.UserType, s.DepartmentID " +
            "FROM Users u " +
            "INNER JOIN Students s ON u.UserID = s.UserID " +
            "WHERE u.Email = @Email AND u.Password = @Password";

        // Prepare the SQL command (added initialization for sqlCmd and sqlRd)
        MySqlCommand^ sqlCmd = gcnew MySqlCommand();
        MySqlDataReader^ sqlRd;

        sqlCmd->Connection = db->GetConnection();
        sqlCmd->CommandText = query;

        // Add parameters to avoid SQL injection
        sqlCmd->Parameters->AddWithValue("@Email", email);
        sqlCmd->Parameters->AddWithValue("@Password", password);

        // Execute the query
        sqlRd = safe_cast<MySqlDataReader^>(sqlCmd->ExecuteReader());

        // Check if the query returns any data
        if (sqlRd->Read()) {
            // Fetch user details from the database
            String^ userID = sqlRd["UserID"]->ToString();
            String^ studentID = sqlRd["StudentID"]->ToString();
            String^ firstName = sqlRd["FirstName"]->ToString();
            String^ lastName = sqlRd["LastName"]->ToString();
            String^ userType = sqlRd["UserType"]->ToString();
            String^ major = sqlRd["DepartmentID"]->ToString();

            // Store user data in objects
            if (userType == "Student") {
                Student^ currentStudent = gcnew Student(
                    userID,  // These are managed String^ types
                    firstName,
                    lastName,
                    email,
                    studentID,
                    major
                );

     

                MessageBox::Show("Login successful! Welcome, " + firstName + ".", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                // Navigate to the student dashboard
                MainApplicationForm^ studentDashboard = gcnew MainApplicationForm(currentStudent);
                studentDashboard->Show();
            }
            else {
                MessageBox::Show("User type not recognized.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }

            // Hide the login form after successful login
            this->Hide();
        }
        else {
            // Invalid login
            MessageBox::Show("Invalid email or password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        // Close the data reader
        sqlRd->Close();
    }
    catch (Exception^ ex) {
        // Handle any database errors
        MessageBox::Show("Failed to connect to database: " + ex->Message, "Connection Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        // Close the connection
        db->CloseConnection();
    }
}

System::Void LoginForm::LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
    txtEmail->Text = "";
    txtPassword->Text = "";
    lblError->Text = "";
}

System::Void AshesiUniversityStudentRecordManagementSystem::LoginForm::lnklblPasswordReset_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
    ForgotPasswordForm^ passwordreset = gcnew ForgotPasswordForm(txtEmail->Text);
    return System::Void();
}
