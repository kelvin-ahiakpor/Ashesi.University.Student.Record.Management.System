// DatabaseManager.h// DatabaseConnection.h
#pragma once

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

public ref class DatabaseManager
{
protected:
    static DatabaseManager^ instance = nullptr;
    MySqlConnection^ sqlConn;

public:
    // Constructor

    DatabaseManager()
    {
        sqlConn = gcnew MySqlConnection();
    }

    static DatabaseManager^ GetInstance() {
        if (instance == nullptr) {
            instance = gcnew DatabaseManager();
        }
        return instance;
    }


    // Method to connect to the database
    System::Void ConnectToDatabase()
    {
        try {
            // Set up the connection string
            this->sqlConn->ConnectionString = "datasource=sql8.freesqldatabase.com; port=3306; username=sql8744026; password=4ussz7Rekc; database=sql8744026";

            // Open the connection
            this->sqlConn->Open();

            // Show success message
            //MessageBox::Show("Database connection successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

        }
        catch (Exception^ ex) {
            // Show error message if connection fails
            MessageBox::Show("Failed to connect to database: " + ex->Message, "Connection Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    // Method to close the connection
    System::Void CloseConnection()
    {
        if (sqlConn->State == System::Data::ConnectionState::Open) {
            sqlConn->Close();
        }
    }

    // Get the connection object
    MySqlConnection^ GetConnection()
    {
        return sqlConn;
    }
};
