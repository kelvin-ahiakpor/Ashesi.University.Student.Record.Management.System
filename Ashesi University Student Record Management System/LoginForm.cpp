#include "LoginForm.h"
#include "MainApplicationForm.h"
#include "DatabaseManager.h"
#include "StudentDashboardForm.h"
#include "FacultyDashboardForm.h"
#include "DatabaseManager.h"
#include "Student.h"

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


        // Create the SQL query to check for valid login
        String^ query = "SELECT UserID, UserType FROM Users WHERE Email = @Email AND Password = @Password";

        // Prepare the SQL command
        sqlCmd->Connection = db->GetConnection();
        sqlCmd->CommandText = query;

        // Add parameters to avoid SQL injection
        sqlCmd->Parameters->AddWithValue("@Email", email);
        sqlCmd->Parameters->AddWithValue("@Password", password);
        // Execute the query
        sqlRd = sqlCmd->ExecuteReader();

        // Check if the query returns any data
        if (sqlRd->Read()) {
            String^ userID = sqlRd["UserID"]->ToString();
            String^ userType = sqlRd["UserType"]->ToString();
            if(userType == "Student") {
                // Navigate to student dashboard
                MessageBox::Show("Login successful! Welcome Student.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                // Replace with your student dashboard form
                //Student newStudent = new Student();

                MainApplicationForm^ studentDashboard = gcnew MainApplicationForm();
                studentDashboard->Show();

            }
            else if (userType == "Faculty") {
                // Navigate to faculty dashboard
                MessageBox::Show("Login successful! Welcome Faculty Member.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                // Replace with your faculty dashboard form
                MainApplicationForm^ facultyDashboard = gcnew MainApplicationForm();
                facultyDashboard->Show();
            }
            else {
                MessageBox::Show("Unknown user type.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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