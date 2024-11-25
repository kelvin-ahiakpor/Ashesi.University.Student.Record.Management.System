#include "TranscriptForm.h"
#include "DatabaseManager.h"
using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;


System::Void btnViewTranscript_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        // Get the database manager instance
        DatabaseManager^ db = DatabaseManager::GetInstance();
        db->ConnectToDatabase();

        // Get the UserID from the input field
        String^ userID = txtStudentID->Text;

        // Check if the UserID field is empty
        if (String::IsNullOrWhiteSpace(userID)) {
            MessageBox::Show("Please enter a valid Student ID.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Define the SQL query
        String^ query = "SELECT * FROM Transcripts WHERE UserID = @userID";

        // Create the command
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@userID", userID);

        // Execute the query
        MySqlDataReader^ reader = cmd->ExecuteReader();

        // Check if the reader has any data
        if (!reader->HasRows) {
            MessageBox::Show("No transcript found for the given Student ID.", "Not Found", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            // Clear the RichTextBox
            richTxtTranscript->Clear();

            // Loop through the results and display them
            while (reader->Read()) {
                String^ transcriptID = reader["TranscriptID"]->ToString();
                String^ courseName = reader["CourseName"]->ToString();
                String^ grade = reader["Grade"]->ToString();
                String^ term = reader["Term"]->ToString();

                // Append the transcript details to the RichTextBox
                richTxtTranscript->AppendText("Transcript ID: " + transcriptID + "\n");
                richTxtTranscript->AppendText("Course: " + courseName + "\n");
                richTxtTranscript->AppendText("Grade: " + grade + "\n");
                richTxtTranscript->AppendText("Term: " + term + "\n");
                richTxtTranscript->AppendText("-------------------------------\n");
            }
        }

        // Close the reader and database connection
        reader->Close();
        db->CloseConnection();
    }
    catch (Exception^ ex) {
        // Handle errors
        MessageBox::Show("Error retrieving transcript: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
