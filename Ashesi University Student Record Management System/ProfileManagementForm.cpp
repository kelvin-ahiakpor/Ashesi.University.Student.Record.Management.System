#pragma once
#include "ProfileManagementForm.h"
#include "DatabaseManager.h"
#include "PasswordManager.h"
#include "SecurityQuestionForm.h"

using namespace System::IO; // For file and directory operations



bool AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::isProfileChanged()
{
	// Check if any text fields have changed
	bool textChanged = (this->textBox1->Text != globalUser->getFirstName() ||
		this->textBox2->Text != globalUser->getLastName() ||
		this->textBox3->Text != globalUser->getEmail() ||
		this->textBox4->Text != globalUser->getPassword());

	// Check if the image has changed (if a new image is selected and its path differs from the current one)
	bool imageChanged = (this->openFileDialogUserImage->FileName != globalUser->getProfilePicturePath());

	// Return true if either the text fields or the image path has changed
	return textChanged || imageChanged;
}

System::Void AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::LoadAdminProfile()
{
	if (isProfileUpdated) {
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
	}
	else {
		this->textBox1->Text = globalUser->getFirstName();
		this->textBox2->Text = globalUser->getLastName();
		this->textBox3->Text = globalUser->getEmail();
		this->textBox4->Text = globalUser->getPassword();
	}
   
}

System::Void AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::btnSaveProfile_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!isProfileChanged()) {
		MessageBox::Show("No changes detected. Please make changes to update profile.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}

	try
	{
		DatabaseManager^ db = DatabaseManager::GetInstance();
		db->ConnectToDatabase();

		// Hash the new password before updating
		String^ hashedPassword = PasswordManager::HashPassword(this->textBox4->Text);

		// Handle image saving if one was uploaded
		String^ newImagePath = String::Empty;
		if (!String::IsNullOrEmpty(selectedImagePath)) // If an image is selected
		{
			newImagePath = SaveProfileImage(selectedImagePath); // Save the image to the folder
		}

		// Update the user profile (including image path if selected)
		String^ query = R"(
            UPDATE Users
            SET FirstName = @firstName,
                LastName = @lastName,
                Email = @Email,
                Password = @Password,
                Image = @ProfilePicturePath
            WHERE UserID = @userID
        )";

		MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
		cmd->Parameters->AddWithValue("@firstName", this->textBox1->Text);
		cmd->Parameters->AddWithValue("@lastName", this->textBox2->Text);
		cmd->Parameters->AddWithValue("@Email", this->textBox3->Text);
		cmd->Parameters->AddWithValue("@Password", hashedPassword);
		cmd->Parameters->AddWithValue("@userID", userID);

		// If an image path is set, update it; otherwise, pass DBNull::Value
		if (String::IsNullOrEmpty(newImagePath))
		{
			cmd->Parameters->AddWithValue("@ProfilePicturePath", DBNull::Value);
		}
		else
		{
			cmd->Parameters->AddWithValue("@ProfilePicturePath", newImagePath);
		}

		cmd->ExecuteNonQuery();
		MessageBox::Show("Profile updated successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Update the global user object with new values
		globalUser->setFirstName(this->textBox1->Text);
		globalUser->setLastName(this->textBox2->Text);
		globalUser->setEmail(this->textBox3->Text);
		globalUser->setPassword(this->textBox4->Text);
		globalUser->setProfilePicturePath(newImagePath); // Update the global user's profile picture path

		isProfileUpdated = true;
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Failed to save profile: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally
	{
		DatabaseManager^ db = DatabaseManager::GetInstance();
		db->CloseConnection();
	}
}


System::Void AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

System::Void AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::ProfileManagementForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrEmpty(globalUser->getSecurityAnswer()))
	{
		MessageBox::Show("Please set your security question and answer.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		SecurityQuestionForm^ securityForm = gcnew SecurityQuestionForm(globalUser);
		securityForm->ShowDialog(); // Show the form and wait for the user to complete it
		this->Close();  // Close the profile form until the question is set
	}
	pictureBox1->ImageLocation = globalUser->getProfilePicturePath();
}

System::Void AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::SetSecurityQuestion(String^ userId, String^ question, String^ answer)
{
	// Hash the answer before storing it
	String^ hashedAnswer = PasswordManager::HashPassword(answer);

	try
	{
		DatabaseManager^ db = DatabaseManager::GetInstance();
		db->ConnectToDatabase();

		// SQL query to update the user's security question and answer
		String^ query = R"(
            UPDATE Users
            SET SecurityQuestion = @question,
                SecurityAnswer = @answer
            WHERE UserID = @userID
        )";

		MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
		cmd->Parameters->AddWithValue("@question", question);
		cmd->Parameters->AddWithValue("@answer", hashedAnswer);
		cmd->Parameters->AddWithValue("@userID", userId);

		cmd->ExecuteNonQuery();
		MessageBox::Show("Security question set successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Failed to set security question: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		DatabaseManager^ db = DatabaseManager::GetInstance();
		db->CloseConnection();
	}
}

System::Void AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::openFileDialogUserImage_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
	return System::Void();
}

System::String^ AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::SaveProfileImage(String^ imagePath)
{
	try
	{
		// Get the path to the user's Documents folder
		String^ userDocumentsPath = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments);

		// Combine the path with a specific folder for your app
		String^ targetDirectory = Path::Combine(userDocumentsPath, "AshesiUniversity", "ProfileImages");

		// Check if the directory exists, create it if it doesn't
		if (!Directory::Exists(targetDirectory)) {
			Directory::CreateDirectory(targetDirectory);
		}

		// Get the file name from the selected image path
		String^ fileName = Path::GetFileName(imagePath);

		// Define the target file path
		String^ targetFilePath = Path::Combine(targetDirectory, fileName);

		// Copy the selected image to the target path
		File::Copy(imagePath, targetFilePath, true);  // true to overwrite if the file already exists

		return targetFilePath; // Return the path where the image is stored
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error saving image: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return String::Empty; // Return empty if an error occurs
	}
}

System::Void AshesiUniversityStudentRecordManagementSystem::ProfileManagementForm::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ openFileDialogUserImage = gcnew OpenFileDialog();
	openFileDialogUserImage->Filter = "Image Files(*.jpg; *.jpeg; *.gif; *.bmp; *.png)|*.jpg; *.jpeg; *.gif; *.bmp; *.png";
	openFileDialogUserImage->Title = "Select an Image File";

	// Show the OpenFileDialog and check if the user selects an image
	if (openFileDialogUserImage->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// Store the selected image path
		selectedImagePath = openFileDialogUserImage->FileName;

		// Optionally display the selected image in a PictureBox (if you want)
		pictureBox1->ImageLocation = selectedImagePath;
	}
}



