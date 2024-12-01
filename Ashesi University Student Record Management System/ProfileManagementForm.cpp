#pragma once
#include "ProfileManagementForm.h"
#include "DatabaseManager.h"

System::Void AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::LoadAdminProfile()
{
	try
	{
		// Obtain database manager instance
		DatabaseManager^ db = DatabaseManager::GetInstance();

		// Open the database connection
		db->ConnectToDatabase();

		// Define the SQL query
		String^ query = R"(
                    SELECT 
                        u.FirstName,
                        u.LastName,
                        u.Email,
                        u.Password
                    FROM 
                        Users u
                    WHERE 
                        u.UserID = @userID
                )";

		// Create SQL command
		MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());

		// Assuming userID is a member variable of the class
		cmd->Parameters->AddWithValue("@userID", userID);

		// Execute the query and read results
		MySqlDataReader^ reader = cmd->ExecuteReader();
		if (reader->Read())
		{
			// Retrieve data from the result set
			String^ firstName = reader["FirstName"]->ToString();
			String^ lastName = reader["LastName"]->ToString();
			String^ email = reader["Email"]->ToString();
			String^ password = reader["Password"]->ToString();

			// Assign the retrieved values to the appropriate UI fields or variables
			this->textBox1->Text = firstName;
			this->textBox2->Text = lastName;
			this->textBox3->Text = email;
			this->textBox4->Text = password;
		}
		else
		{
			MessageBox::Show("No profile found for the specified user ID.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		// Close the reader
		reader->Close();
	}
	catch (Exception^ ex)
	{
		// Handle any exceptions that occur
		MessageBox::Show("An error occurred while loading the admin profile: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally
	{
		// Ensure the database connection is closed
		DatabaseManager^ db = DatabaseManager::GetInstance();
		db->CloseConnection();
	}
    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::btnSaveProfile_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		DatabaseManager^ db = DatabaseManager::GetInstance();
		db->ConnectToDatabase();

		String^ query = R"(
            UPDATE Users
            SET FirstName = @firstName,
                LastName = @lastName,
                Email = @Email,
                Password = @Password
            WHERE UserID = @userID
        )";

		MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
		cmd->Parameters->AddWithValue("@firstName", this->textBox1->Text);
		cmd->Parameters->AddWithValue("@lastName", this->textBox2->Text);
		cmd->Parameters->AddWithValue("@Email", this->textBox3->Text);
		cmd->Parameters->AddWithValue("@Password", this->textBox4->Text); 
		cmd->Parameters->AddWithValue("@userID", userID);

		cmd->ExecuteNonQuery();
		MessageBox::Show("Profile updated successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Failed to save profile: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		DatabaseManager^ db = DatabaseManager::GetInstance();
		db->CloseConnection();
	}
	return System::Void();
}
