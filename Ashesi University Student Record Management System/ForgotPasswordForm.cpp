#include "ForgotPasswordForm.h"
#include "DatabaseManager.h"
#include "PasswordManager.h"

String^ AshesiUniversityStudentRecordManagementSystem::ForgotPasswordForm::GetSecurityAnswerFromDB()
{
    String^ securityAnswer = "";
    try
    {
        DatabaseManager^ db = DatabaseManager::GetInstance();
        db->ConnectToDatabase();

        // Query to fetch the security answer
        String^ query = "SELECT SecurityAnswer FROM Users WHERE Email = @Email";
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@Email", userEmail);

        MySqlDataReader^ reader = cmd->ExecuteReader();
        if (reader->Read())
        {
            securityAnswer = reader["SecurityAnswer"]->ToString();  // Fetch the stored hashed answer
        }
        reader->Close();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error while fetching security answer: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
	finally
	{
		DatabaseManager^ db = DatabaseManager::GetInstance();
		db->CloseConnection();
	}
    return securityAnswer;
}

bool AshesiUniversityStudentRecordManagementSystem::ForgotPasswordForm::VerifySecurityAnswer(String^ enteredAnswer)
{
    // Fetch the stored answer from the database
    String^ storedAnswer = GetSecurityAnswerFromDB();

    // Hash the entered answer and compare it to the stored security answer
    String^ hashedEnteredAnswer = PasswordManager::HashPassword(enteredAnswer);

    // Compare the answers (hashed)
    return hashedEnteredAnswer == storedAnswer;
}

System::Void AshesiUniversityStudentRecordManagementSystem::ForgotPasswordForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void AshesiUniversityStudentRecordManagementSystem::ForgotPasswordForm::btnChangePassword_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Check if both the answer and new password fields are filled
    if (String::IsNullOrWhiteSpace(textBox1->Text) || String::IsNullOrWhiteSpace(textBox2->Text))
    {
        MessageBox::Show("Please enter both the security answer and the new password.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Verify the entered security answer
    if (VerifySecurityAnswer(textBox1->Text))
    {
        // Answer is correct, now update the password
        String^ newPassword = textBox2->Text;

        // Hash the new password before updating it
        String^ hashedNewPassword = PasswordManager::HashPassword(newPassword);

        try
        {
            // Update the password in the database
            DatabaseManager^ db = DatabaseManager::GetInstance();
            db->ConnectToDatabase();

            String^ query = "UPDATE Users SET Password = @Password WHERE Email = @Email";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
            cmd->Parameters->AddWithValue("@Password", hashedNewPassword);
            cmd->Parameters->AddWithValue("@Email", userEmail);

            cmd->ExecuteNonQuery();
            MessageBox::Show("Password reset successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

            this->Close(); // Close the form after successful password reset
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error while resetting the password: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
		finally
		{
			DatabaseManager^ db = DatabaseManager::GetInstance();
			db->CloseConnection();
		}
    }
    else
    {
        // Incorrect security answer
        MessageBox::Show("Incorrect answer to the security question.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
