#include "ClassRoster.h"
#include "DatabaseManager.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

System::Void AshesiUniversityStudentRecordManagementSystem::ClassRoster::ClassRoster_Load(System::Object^ sender, System::EventArgs^ e)
{
	DatabaseManager^ db = DatabaseManager::GetInstance();

	try {
		// Load the courses taught by the faculty
		LoadLecturerCourses(db);
	}
	catch (Exception^ ex) {
		// Display error message
		MessageBox::Show("Error loading class roster: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		// Ensure the database connection is closed
		db->CloseConnection();
	}

	return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::ClassRoster::btnClassRoster_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();
	String^ course = cboxCourses->Text;

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
				AND c.CourseName = @course
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
		cmd->Parameters->AddWithValue("@course", course);

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

System::Void AshesiUniversityStudentRecordManagementSystem::ClassRoster::LoadLecturerCourses(DatabaseManager^ db)
{
    db->ConnectToDatabase();

    // Fetch courses taught by the faculty
    int^ facultyid = faculty->getFacultyID();
    String^ queryCourses = R"(
    SELECT 
        c.CourseID, 
        c.CourseName
    FROM 
        Courses c
    INNER JOIN 
        CourseOfferings co ON c.CourseID = co.CourseID
    WHERE
        co.FacultyID = @facultyID;
    )";

    MySqlCommand^ commandCourses = gcnew MySqlCommand(queryCourses, db->GetConnection());
    commandCourses->Parameters->AddWithValue("@facultyID", facultyid);

    MySqlDataReader^ readerCourses = commandCourses->ExecuteReader();

    cboxCourses->Items->Clear();

    while (readerCourses->Read())
    {
        String^ courseName = readerCourses["CourseName"]->ToString();
        cboxCourses->Items->Add(courseName);
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::ClassRoster::cboxCourses_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    btnClassRoster_Click(sender, e);
}

