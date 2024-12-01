#include "ViewGradesAdmin.h"
#include "DatabaseManager.h"

System::Void AshesiUniversityStudentRecordManagementSystem::ViewGradesAdmin::btnViewGrades_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dgvStudentList->SelectedRows->Count == 0) {
        MessageBox::Show("Please select a student from the list.", "Selection Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return System::Void();
    }

    // Get the selected student's StudentID
    String^ studentID = dgvStudentList->SelectedRows[0]->Cells["StudentID"]->Value->ToString();

    DatabaseManager^ db = DatabaseManager::GetInstance();

    try {
        // Connect to the database
        db->ConnectToDatabase();

        String^ query = R"(
            SELECT 
                c.CourseName, 
                e.Grade, 
                eo.Year, 
                eo.Semester
            FROM 
                Enrollments e
            JOIN 
                CourseOfferings eo ON e.OfferingID = eo.OfferingID
            JOIN 
                Courses c ON eo.CourseID = c.CourseID
            WHERE 
                e.StudentID = @studentID
            ORDER BY 
                eo.Year DESC, eo.Semester DESC;
        )";

        MySqlCommand^ command = gcnew MySqlCommand(query, db->GetConnection());
        command->Parameters->AddWithValue("@studentID", studentID);

        MySqlDataReader^ reader = command->ExecuteReader();

        // Clear the RichTextBox
        richTxtGrades->Clear();

        // Populate the RichTextBox with grades
        String^ gradesText = "Grades for Student ID: " + studentID + "\n\n";
        gradesText += "Course Name\tGrade\tYear\tSemester\n";
        gradesText += "-------------------------------------------\n";

        while (reader->Read()) {
            gradesText += reader["CourseName"]->ToString() + "\t" +
                reader["Grade"]->ToString() + "\t" +
                reader["Year"]->ToString() + "\t" +
                reader["Semester"]->ToString() + "\n";
        }

        reader->Close();

        // Display the grades in the RichTextBox
        richTxtGrades->Text = gradesText;
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        db->CloseConnection();
    }

    return System::Void();
}


System::Void AshesiUniversityStudentRecordManagementSystem::ViewGradesAdmin::btnSearch_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ firstName = txtFirstName->Text;
	String^ lastName = txtLastName->Text;

	DatabaseManager^ db = DatabaseManager::GetInstance();

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
                eo.Year DESC, eo.Semester DESC;
        )";

	try {
		// Open the database connection
		db->ConnectToDatabase();

		String^ query = "SELECT s.StudentID, u.FirstName, u.LastName, d.DepartmentName "
			"FROM Students s "
			"JOIN Users u ON s.UserID = u.UserID "
			"JOIN Departments d ON s.DepartmentID = d.DepartmentID "
			"WHERE u.FirstName = @firstName AND u.LastName = @lastName";


		MySqlCommand^ command = gcnew MySqlCommand(query, db->GetConnection());
		command->Parameters->AddWithValue("@firstName", firstName);
		command->Parameters->AddWithValue("@lastName", lastName);

		MySqlDataReader^ reader = command->ExecuteReader();

		dgvStudentList->Rows->Clear();
		dgvStudentList->Columns->Clear();
		dgvStudentList->Columns->Add("StudentID", "Student ID");
		dgvStudentList->Columns->Add("FirstName", "First Name");
		dgvStudentList->Columns->Add("LastName", "Last Name");
		dgvStudentList->Columns->Add("DepartmentName", "DepartmentName");

		while (reader->Read())
		{
			dgvStudentList->Rows->Add(reader["StudentID"], reader["FirstName"], reader["LastName"], reader["DepartmentName"]);
		}

		reader->Close();
		db->CloseConnection();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	return System::Void();
}

