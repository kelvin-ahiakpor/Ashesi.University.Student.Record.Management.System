#include "EnrollmentHistory.h"
#include "DatabaseManager.h"

System::Void AshesiUniversityStudentRecordManagementSystem::EnrollmentHistory::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try {
        // Open the database connection
        db->ConnectToDatabase();

        // Updated SQL query to fetch enrollment history
        String^ query = R"(
            SELECT 
                c.CourseName, 
                e.EnrollmentDate,
                eo.Schedule, 
                eo.Year,
                e.Status
            FROM 
                Enrollments e
            JOIN 
                Students s ON e.StudentID = s.StudentID
            JOIN 
                CourseOfferings eo ON e.OfferingID = eo.OfferingID
            JOIN 
                Courses c ON eo.CourseID = c.CourseID
            WHERE 
                s.StudentID = @studentID
            ORDER BY 
                eo.Year DESC;
        )";

        // Create the command
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@studentID", studentid); // Bind the student ID parameter

        MySqlDataReader^ reader = cmd->ExecuteReader();
        if (!reader->HasRows) {
            MessageBox::Show("No enrollment history found for the given Student ID.", "Not Found", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            // Clear the RichTextBox
            richTxtTranscript->Clear();

            // Loop through the results and display them
            while (reader->Read()) {
                String^ courseName = reader["CourseName"]->ToString();
                String^ enrollmentDate = Convert::ToDateTime(reader["EnrollmentDate"]).ToString("yyyy-MM-dd");
                String^ schedule = reader["Schedule"]->ToString();
                String^ year = reader["Year"]->ToString();
                String^ status = reader["Status"]->ToString();

                // Append the enrollment details to the RichTextBox
                richTxtTranscript->AppendText("Course: " + courseName + "\n");
                richTxtTranscript->AppendText("Enrollment Date: " + enrollmentDate + "\n");
                richTxtTranscript->AppendText("Schedule: " + schedule + "\n");
                richTxtTranscript->AppendText("Year: " + year + "\n");
                richTxtTranscript->AppendText("Status: " + status + "\n");
                richTxtTranscript->AppendText("-------------------------------\n");
            }
        }

        // Close the reader
        reader->Close();
    }
    catch (Exception^ ex) {
        // Handle errors
        MessageBox::Show("Error retrieving enrollment history: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        // Ensure the database connection is closed
        db->CloseConnection();
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::EnrollmentHistory::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}
