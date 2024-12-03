#include "LoginForm.h"
#include "MainApplicationForm.h"
#include "DatabaseManager.h"
#include "Student.h"
#include "ForgotPasswordForm.h"
#include "PasswordManager.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

System::Void LoginForm::btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
    // Get the email and password from the textboxes
    String^ email = txtEmail->Text;
    String^ password = txtPassword->Text;
	String^ hashedPassword = PasswordManager::HashPassword(password);

    // Validate the inputs (e.g., check for empty fields)
    if (String::IsNullOrWhiteSpace(email) || String::IsNullOrWhiteSpace(password)) {
        lblError->Text = "Please fill in both email and password.";
        return;
    }

    DatabaseManager^ db = DatabaseManager::GetInstance();
    MySqlCommand^ sqlCmd = gcnew MySqlCommand();
    MySqlDataReader^ sqlRd = nullptr;

    try {
        // Open the database connection
        db->ConnectToDatabase();

        // Create the SQL query
        String^ query = "SELECT u.UserID, u.FirstName, u.LastName, u.Email, u.UserType " +
            "FROM Users u " +
            "WHERE u.Email = @Email AND u.Password = @Password";

        // Prepare the SQL command
        sqlCmd->Connection = db->GetConnection();
        sqlCmd->CommandText = query;

        // Add parameters to avoid SQL injection
        sqlCmd->Parameters->AddWithValue("@Email", email);
        sqlCmd->Parameters->AddWithValue("@Password", hashedPassword);

        // Execute the query
        sqlRd = safe_cast<MySqlDataReader^>(sqlCmd->ExecuteReader());

        // Check if the query returns any data
        if (sqlRd->Read()) {
            // Fetch user details from the database
            int^ userID = (int)sqlRd["UserID"];
            String^ firstName = sqlRd["FirstName"]->ToString();
            String^ lastName = sqlRd["LastName"]->ToString();
            String^ userType = sqlRd["UserType"]->ToString();

            // Close the current reader before executing another query
            sqlRd->Close();

            if (userType == "Student") {
                // Query for student details
                String^ studentQuery = "SELECT s.StudentID, s.DepartmentID " +
                    "FROM Students s " +
                    "WHERE s.UserID = @userID";

                // Update the command and parameters
                sqlCmd->CommandText = studentQuery;
                sqlCmd->Parameters->Clear();
                sqlCmd->Parameters->AddWithValue("@userID", userID);

                // Execute the query for student details
                sqlRd = safe_cast<MySqlDataReader^>(sqlCmd->ExecuteReader());

                if (sqlRd->Read()) {
                    // Extract StudentID and DepartmentID
                    int studentID = (int)sqlRd["StudentID"];
                    String^ major = sqlRd["DepartmentID"]->ToString();

                    // Create the Student object
                    Student^ currentStudent = gcnew Student(
                        userID, firstName, lastName, email, studentID, major);

					currentStudent->setPassword(password);

                    // Show a success message
                    MessageBox::Show("Login successful! Welcome, " + firstName + ".",
                        "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                    // Navigate to the student dashboard
                    MainApplicationForm^ studentDashboard = gcnew MainApplicationForm(currentStudent);
                    studentDashboard->Show();
                    this->Hide();
                }
                else {
                    MessageBox::Show("No student record found for the provided user ID.",
                        "Login Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }

                sqlRd->Close();
            }
            else if (userType == "Administrator") {
                // Handle Administrator login
                Admin^ admin = gcnew Admin(userID, firstName, lastName, email);

                admin->setPassword(password);

                MessageBox::Show("Login successful! Welcome, " + firstName + ".",
                    "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                MainApplicationForm^ adminDashboard = gcnew MainApplicationForm(admin);
                adminDashboard->Show();
                this->Hide();
            }
            else if (userType == "Faculty") {
                // Query for student details
                String^ studentQuery = "SELECT f.FacultyID, f.DepartmentID " +
                    "FROM Faculty f " +
                    "WHERE f.UserID = @userID";

                // Update the command and parameters
                sqlCmd->CommandText = studentQuery;
                sqlCmd->Parameters->Clear();
                sqlCmd->Parameters->AddWithValue("@userID", userID);

                // Execute the query for student details
                sqlRd = safe_cast<MySqlDataReader^>(sqlCmd->ExecuteReader());

                if (sqlRd->Read()) {
                    // Extract StudentID and DepartmentID
                    int facultyID = (int)sqlRd["FacultyID"];
                    int^ departmentID = (int)sqlRd["DepartmentID"];

                    // Create the Student object
                    Faculty^ faculty = gcnew Faculty(
                        userID, firstName, lastName, email, facultyID, departmentID);

                    faculty->setPassword(password);

                    // Show a success message
                    MessageBox::Show("Login successful! Welcome, " + firstName + ".",
                        "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                    // Navigate to the student dashboard
                    MainApplicationForm^ studentDashboard = gcnew MainApplicationForm(faculty);
                    studentDashboard->Show();
                    this->Hide();
                }
                else {
                    MessageBox::Show("No Faculty record found for the provided user ID.",
                        "Login Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }

                sqlRd->Close();
            }
            else {
                MessageBox::Show("User type not recognized.",
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        else {
            // Invalid login
            MessageBox::Show("Invalid email or password.",
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (Exception^ ex) {
        // Handle any database errors
        MessageBox::Show("An error occurred while logging in: " + ex->Message,
            "Connection Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        // Ensure the reader is closed and resources are released
        if (sqlRd != nullptr && !sqlRd->IsClosed) {
            sqlRd->Close();
        }

        // Close the database connection
        db->CloseConnection();
    }
}

System::Void LoginForm::LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
    txtEmail->Text = "";
    txtPassword->Text = "";
    lblError->Text = "";
}

System::Void AshesiUniversityStudentRecordManagementSystem::LoginForm::lnklblPasswordReset_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
    ForgotPasswordForm^ passwordReset = gcnew ForgotPasswordForm(txtEmail->Text);
    passwordReset->ShowDialog();
}

System::Void AshesiUniversityStudentRecordManagementSystem::LoginForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
