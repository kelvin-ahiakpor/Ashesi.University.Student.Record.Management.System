#include "ViewGrades.h"
#include "DatabaseManager.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

System::Void AshesiUniversityStudentRecordManagementSystem::ViewGrades::btnViewGrades_Click(System::Object^ sender, System::EventArgs^ e)
{
    studentid;

    DatabaseManager^ db = DatabaseManager::GetInstance();

    try {
        // Open the database connection
        db->ConnectToDatabase();

        // Create the SQL query with JOIN (fixed missing comma and added space)
        String^ query = R"(
            SELECT 
                c.CourseName, 
                e.Grade
            FROM 
                Enrollments e
            JOIN 
                Students s ON e.StudentID = s.StudentID
            JOIN 
                CourseOfferings eo ON e.OfferingID = eo.OfferingID
            JOIN 
                Courses c ON eo.CourseID = c.CourseID
            WHERE 
                s.StudentID = @userID
            ORDER BY 
                eo.Year DESC;
        )";

        // Create the command
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@userID", studentid); // Bind the student ID parameter

        MySqlDataReader^ reader = cmd->ExecuteReader();
        if (!reader->HasRows) {
            MessageBox::Show("No grades found for the given Student ID.", "Not Found", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            // Clear the RichTextBox
            richTxtTranscript->Clear();

            // Loop through the results and display them
            while (reader->Read()) {
                String^ courseName = reader["CourseName"]->ToString();
                String^ grade = reader["Grade"]->ToString();

                // Append the grade details to the RichTextBox
                richTxtTranscript->AppendText("Course: " + courseName + "\n");
                richTxtTranscript->AppendText("Grade: " + grade + "\n");
                richTxtTranscript->AppendText("-------------------------------\n");
            }
        }

        // Close the reader
        reader->Close();
    }
    catch (Exception^ ex) {
        // Handle errors
        MessageBox::Show("Error retrieving grades: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::ViewGrades::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
