#include "LoginForm.h"
#include "MainApplicationForm.h"

using namespace AshesiUniversityStudentRecordManagementSystem;

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

System::Void LoginForm::ConnectToDatabase() {
    try {
        // Set up the connection string
        this->sqlConn->ConnectionString = "datasource=sql8.freesqldatabase.com; port=3306; username=sql8744026; password=4ussz7Rekc; database=sql8744026";

        // Open the connection
        this->sqlConn->Open();

        // Show success message
        MessageBox::Show("Database connection successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

        // Close the connection
        this->sqlConn->Close();
    }
    catch (Exception^ ex) {
        // Show error message if connection fails
        MessageBox::Show("Failed to connect to database: " + ex->Message, "Connection Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::LoginForm::btnLogin_Click(System::Object^ sender, System::EventArgs^ e)
{
    
}

System::Void LoginForm::LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
    txtEmail->Text = "";
    txtPassword->Text = "";
    lblError->Text = "";
    ConnectToDatabase();
}