#include "TranscriptForm.h"
#include "DatabaseManager.h"
using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;


System::Void TranscriptForm::btnViewTranscript_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        // Get the database manager instance
        DatabaseManager^ db = DatabaseManager::GetInstance();

        // Get the UserID from the input field
        String^ userID = txtStudentID->Text;

        // Check if the UserID field is empty
        if (String::IsNullOrWhiteSpace(userID)) {
            MessageBox::Show("Please enter a valid Student ID.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Define the SQL query to retrieve the transcript information
        String^ query = R"(
            SELECT 
        s.StudentID, 
        c.CourseName, 
        eo.Semester, 
        eo.Year, 
        eo.Schedule, 
        eo.Room, 
        eo.Status AS OfferingStatus, 
        f.FacultyName, 
        e.Grade
    FROM 
        Enrollments e
    JOIN 
        Students s ON e.StudentID = s.StudentID
    JOIN 
        CourseOfferings eo ON e.OfferingID = eo.OfferingID
    JOIN 
        Courses c ON eo.CourseID = c.CourseID
    JOIN 
        Faculty f ON eo.FacultyID = f.FacultyID
    WHERE 
        s.StudentID = @userID
    ORDER BY 
        eo.Year DESC, eo.Semester DESC;
        )";

        // Create the command
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@userID", userID); // Bind the student ID parameter

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
                String^ studentid = reader["StudentID"]->ToString();
                String^ courseName = reader["CourseName"]->ToString();
                String^ semester = reader["Semester"]->ToString();
                String^ year = reader["Year"]->ToString();
                String^ schedule = reader["Schedule"]->ToString();
                String^ room = reader["Room"]->ToString();
                String^ offeringStatus = reader["OfferingStatus"]->ToString();
                String^ facultyName = reader["FacultyName"]->ToString();
                String^ grade = reader["Grade"]->ToString();

                // Append the transcript details to the RichTextBox
                richTxtTranscript->AppendText("Student: " + studentid + "\n");
                richTxtTranscript->AppendText("Course: " + courseName + "\n");
                richTxtTranscript->AppendText("Semester: " + semester + ", Year: " + year + "\n");
                richTxtTranscript->AppendText("Schedule: " + schedule + ", Room: " + room + "\n");
                richTxtTranscript->AppendText("Offering Status: " + offeringStatus + "\n");
                richTxtTranscript->AppendText("Faculty: " + facultyName + "\n");
                richTxtTranscript->AppendText("Grade: " + grade + "\n");
                richTxtTranscript->AppendText("-------------------------------\n");
            }
        }

        // Close the reader
        reader->Close();
    }
    catch (Exception^ ex) {
        // Handle errors
        MessageBox::Show("Error retrieving transcript: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

