#include "TranscriptForm.h"
#include "DatabaseManager.h"
using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;


void AshesiUniversityStudentRecordManagementSystem::TranscriptForm::DisablePrintButtonBasedOnUserRole()
{
    // Disable the 'Print Transcript' button for students and faculty
    if (userRole == "Student" || userRole == "Faculty") {
        btnPrintTranscript->Enabled = false;
    }
    else if (userRole == "Administrator") {
        btnPrintTranscript->Enabled = true;
    }
}

System::Void TranscriptForm::btnViewTranscript_Click(System::Object^ sender, System::EventArgs^ e) {
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try {
        GetTranscript(db);
    }
    catch (Exception^ ex) {
        // Handle errors
        MessageBox::Show("Error retrieving transcript: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
	finally {
		// Close the database connection
		db->CloseConnection();
	}
}

System::Void AshesiUniversityStudentRecordManagementSystem::TranscriptForm::btnPrintTranscript_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        // Check if the RichTextBox contains any text
        if (String::IsNullOrWhiteSpace(richTxtTranscript->Text)) {
            MessageBox::Show("No transcript data available to print.", "Print Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Open a SaveFileDialog to specify the output file
        SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
        saveFileDialog->Filter = "Text Files (*.txt)|*.txt|Word Documents (*.docx)|*.docx|PDF Files (*.pdf)|*.pdf|All Files (*.*)|*.*";
        saveFileDialog->Title = "Save Transcript As";
        saveFileDialog->FileName = "Transcript";

        // Check if the user selected a file
        if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            // Get the file path
            String^ filePath = saveFileDialog->FileName;

            // Write the transcript content to the file
            System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(filePath);
            writer->Write(richTxtTranscript->Text);
            writer->Close();

            // Notify the user
            MessageBox::Show("Transcript saved successfully to: " + filePath, "Print Successful", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }
    catch (Exception^ ex) {
        // Handle any errors during the process
        MessageBox::Show("Error saving transcript: " + ex->Message, "File Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::TranscriptForm::TranscriptForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    DisablePrintButtonBasedOnUserRole();
	LoadStudentsToCache();
    
}

// Helper function to retrieve the transcript information from the database
System::Void AshesiUniversityStudentRecordManagementSystem::TranscriptForm::GetTranscript(DatabaseManager^ db)
{
    // Get the database manager instance

    db->ConnectToDatabase();

    int userID;
    if (userRole == "Administrator") {
        // Get the UserID from the input field
        int userID = Convert::ToInt32(textStudentID->Text);
    }
    else {
        textStudentID->Text = student->getStudentID()->ToString();
        int userID = Convert::ToInt32(textStudentID->Text);
    }



    // Check if the UserID field is empty
    if (!Int32::TryParse(textStudentID->Text, userID)) {
        MessageBox::Show("Please enter a valid number for the Student ID.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
        eo.Status AS OfferingStatus, 
        u.FirstName, 
        u.LastName,
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
        Users u ON u.UserID = s.UserID
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
            int^ studentid = (int)reader["StudentID"];
            String^ courseName = reader["CourseName"]->ToString();
            String^ semester = reader["Semester"]->ToString();
            String^ year = reader["Year"]->ToString();
            String^ schedule = reader["Schedule"]->ToString();
            String^ offeringStatus = reader["OfferingStatus"]->ToString();
            String^ studentName = reader["FirstName"]->ToString() + " " + reader["LastName"]->ToString();
            String^ grade = reader["Grade"]->ToString();

            // Append the transcript details to the RichTextBox
            richTxtTranscript->AppendText("Student: " + studentid + "\n");
            richTxtTranscript->AppendText("Course: " + courseName + "\n");
            richTxtTranscript->AppendText("Semester: " + semester + ", Year: " + year + "\n");
            richTxtTranscript->AppendText("Schedule: " + schedule + "\n");
            richTxtTranscript->AppendText("Offering Status: " + offeringStatus + "\n");
            richTxtTranscript->AppendText("Student: " + studentName + "\n");
            richTxtTranscript->AppendText("Grade: " + grade + "\n");
            richTxtTranscript->AppendText("-------------------------------\n");
        }
    }

    // Close the reader
    reader->Close();
}

System::Void AshesiUniversityStudentRecordManagementSystem::TranscriptForm::cboxStudentName_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    // Disable event handlers temporarily
    cboxStudentName->TextChanged -= gcnew System::EventHandler(this, &TranscriptForm::cboxStudentName_TextChanged);

    String^ searchTerm = cboxStudentName->Text->ToLower();

    // Filter students manually by name
    List<Student^>^ filteredStudents = gcnew List<Student^>();
    for each (Student ^ student in cachedStudents)
    {
        if (student->getFullName()->ToLower()->Contains(searchTerm))
        {
            filteredStudents->Add(student);
        }
    }

    // Update the ComboBox items
    cboxStudentName->Items->Clear();
    for each (Student ^ student in filteredStudents)
    {
        cboxStudentName->Items->Add(student->getFullName());
    }

    // Preserve the user's input after repopulating
    cboxStudentName->Text = searchTerm;
    cboxStudentName->SelectionStart = cboxStudentName->Text->Length;

    // Re-enable event handlers
    cboxStudentName->TextChanged += gcnew System::EventHandler(this, &TranscriptForm::cboxStudentName_TextChanged);
}

System::Void AshesiUniversityStudentRecordManagementSystem::TranscriptForm::LoadStudentsToCache()
{
    DatabaseManager^ db = DatabaseManager::GetInstance();
    try
    {
        db->ConnectToDatabase();
        String^ query = R"(
            SELECT 
                s.StudentID, 
                u.UserID,
                u.FirstName, 
                u.LastName, 
                u.Email,
                s.DepartmentID
            FROM 
                Students s
            JOIN 
                Users u ON s.UserID = u.UserID
            WHERE 
                s.IsDeleted = 0
        )";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        MySqlDataReader^ reader = cmd->ExecuteReader();

        cachedStudents->Clear();
        cboxStudentName->Items->Clear();

        while (reader->Read())
        {
            int^ studentID = Convert::ToInt32(reader["StudentID"]);
            int^ userID = Convert::ToInt32(reader["UserID"]);
            String^ firstName = reader["FirstName"]->ToString();
            String^ lastName = reader["LastName"]->ToString();
            String^ email = reader["Email"]->ToString();
            int^ departmentID = Convert::ToInt32(reader["DepartmentID"]);

            Student^ student = gcnew Student(userID, firstName, lastName, email, studentID, departmentID);
            cachedStudents->Add(student);
            cboxStudentName->Items->Add(firstName + " " + lastName);
        }

        reader->Close();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error loading students: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally
    {
        db->CloseConnection();
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::TranscriptForm::cboxStudentName_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (cboxStudentName->SelectedIndex != -1)
    {
        String^ selectedName = cboxStudentName->SelectedItem->ToString();
        Student^ selectedStudent = nullptr;

        for each (Student ^ student in cachedStudents)
        {
            if (student->getFullName() == selectedName)
            {
                selectedStudent = student;
                textStudentID->Text = selectedStudent->getStudentID()->ToString();
                break;
            }
        }

        // Optional: Automatically retrieve transcript when a student is selected
        if (selectedStudent != nullptr)
        {   
			btnViewTranscript_Click(sender, e);
        }
    }
}


