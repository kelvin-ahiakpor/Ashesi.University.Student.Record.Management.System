#include "SecurityQuestionForm.h"
#include "PasswordManager.h"


bool AshesiUniversityStudentRecordManagementSystem::SecurityQuestionForm::VerifySecurityAnswer(String^ enteredHashedAnswer)
{
	// Fetch the stored answer from DB
	String^ storedHashedAnswer = GetSecurityAnswerFromDB(this->userID);

	// Compare the entered hashed answer with the stored answer
	return (enteredHashedAnswer == storedHashedAnswer);
}

String^ AshesiUniversityStudentRecordManagementSystem::SecurityQuestionForm::GetSecurityAnswerFromDB(int^ userID)
{
	String^ storedAnswer = "";
	try
	{
		// Connect to the database and query the stored answer
		DatabaseManager^ db = DatabaseManager::GetInstance();
		db->ConnectToDatabase();

		String^ query = "SELECT SecurityAnswer FROM Users WHERE UserID = @userID";
		MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
		cmd->Parameters->AddWithValue("@userID", userID);

		MySqlDataReader^ reader = cmd->ExecuteReader();
		if (reader->Read())
		{
			storedAnswer = reader["SecurityAnswer"]->ToString();  // Fetch the stored hashed answer
		}
		reader->Close();
		db->CloseConnection();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error while fetching security answer: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	return storedAnswer;
}

void AshesiUniversityStudentRecordManagementSystem::SecurityQuestionForm::SetSecurityQuestion(int^ userID, String^ answer)
{
	// Hash the answer before storing it
	String^ hashedAnswer = PasswordManager::HashPassword(answer);

	try
	{
		// Connect to the database and update the security question and answer
		DatabaseManager^ db = DatabaseManager::GetInstance();
		db->ConnectToDatabase();

		String^ query = "UPDATE Users SET SecurityAnswer = @answer WHERE UserID = @userID";
		MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
		cmd->Parameters->AddWithValue("@answer", hashedAnswer);
		cmd->Parameters->AddWithValue("@userID", userID);

		cmd->ExecuteNonQuery();
		MessageBox::Show("Security question set successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		db->CloseConnection();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error while setting security question: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void AshesiUniversityStudentRecordManagementSystem::SecurityQuestionForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void AshesiUniversityStudentRecordManagementSystem::SecurityQuestionForm::btnSubmit_Click(System::Object^ sender, System::EventArgs^ e)
{
		// Set the security question and answer
		String^ answer = this->txtAnswer->Text;
		SetSecurityQuestion(this->userID, answer);

		// Get the entered answer and hash it
		String^ enteredAnswer = this->txtAnswer->Text;
		String^ hashedAnswer = PasswordManager::HashPassword(enteredAnswer);

		// Store the hashed answer in the User object
		globalUser->setSecurityAnswer(hashedAnswer);

		// Close the form after setting the question
		this->Close();
}



