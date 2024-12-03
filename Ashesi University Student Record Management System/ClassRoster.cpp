#include "ClassRoster.h"
#include "DatabaseManager.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

System::Void AshesiUniversityStudentRecordManagementSystem::ClassRoster::btnClassRoster_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try {
        // Open the database connection
        db->ConnectToDatabase();

        // Define the SQL query
        String^ query = R"(
            SELECT 
                s.StudentID, 
                u.FirstName, 
                u.LastName,
                c.CourseName
            FROM 
                Enrollments e
            JOIN 
                Students s ON e.StudentID = s.StudentID
            JOIN 
                CourseOfferings eo ON e.OfferingID = eo.OfferingID
            JOIN 
                Courses c ON eo.CourseID = c.CourseID
            JOIN 
                Users u ON s.UserID = u.UserID
            JOIN 
                Faculty f ON eo.FacultyID = f.FacultyID
            WHERE 
                f.FacultyID = @facultyID
            ORDER BY 
                u.FirstName ASC;
        )";

        // Create the command
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());

        // Ensure `faculty` is properly initialized before using it
        if (faculty == nullptr) {
            MessageBox::Show("Faculty object is not initialized.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return System::Void();
        }

        // Bind the faculty ID parameter
        cmd->Parameters->AddWithValue("@facultyID", faculty->getFacultyID());

        // Execute the query
        MySqlDataReader^ reader = cmd->ExecuteReader();

        // Check if results exist
        if (!reader->HasRows) {
            MessageBox::Show("No students found for the selected faculty member.", "Not Found", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            // Clear the RichTextBox
            richTxtTranscript->Clear();

            // Loop through the results and display them
            while (reader->Read()) {
                String^ studentID = reader["StudentID"]->ToString();
                String^ studentName = reader["FirstName"]->ToString() + reader["LastName"]->ToString();
                String^ courseName = reader["CourseName"]->ToString();

                // Append the student details to the RichTextBox
                richTxtTranscript->AppendText("Student ID: " + studentID + "\n");
                richTxtTranscript->AppendText("Student Name: " + studentName + "\n");
                richTxtTranscript->AppendText("Course: " + courseName + "\n");
                richTxtTranscript->AppendText("-------------------------------\n");
            }
        }

        // Close the reader
        reader->Close();
    }
    catch (Exception^ ex) {
        // Display error message
        MessageBox::Show("Error retrieving class roster: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        // Ensure the database connection is closed
        db->CloseConnection();
    }

    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::ClassRoster::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

