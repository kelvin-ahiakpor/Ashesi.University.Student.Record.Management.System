#include "GradeManagementForm.h"
#include "DatabaseManager.h"



System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::GradeManagementForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try {
		LoadGrades(db, sender, e); 
    }
    catch (Exception^ ex) {
        // Handle any exceptions that may occur
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        // Close the database connection
        db->CloseConnection();
    }

    try {
		LoadStudentsToCache(db, sender, e);
	}
	catch (Exception^ ex) {
		// Handle any exceptions that may occur
		MessageBox::Show("Error: " + ex->Message);
	}
    finally {
        // Close the database connection
        db->CloseConnection();
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::btnSubmitGrade_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (cboxCourses->SelectedIndex == -1 || cboxStudentName->SelectedIndex == -1 || cboxGrades->SelectedIndex == -1)
	{
		MessageBox::Show("Please select a course, student, and grade.");
		return;
	}
    DatabaseManager^ db = DatabaseManager::GetInstance();

    db->ConnectToDatabase();

    try {
        SubmitGrade(db, sender, e);
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        db->CloseConnection();
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::LoadGrades(DatabaseManager^ db, Object^ sender, EventArgs^ e)
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

    readerCourses->Close();

    // Hardcoded grades (if they are not fetched from the DB)
    cboxGrades->Items->Clear();
    array<String^>^ grades = { "A+", "A", "B+", "B", "C+", "C", "D+", "D", "E", "F" };
    cboxGrades->Items->AddRange(grades);
}


System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::SubmitGrade(DatabaseManager^ db, Object^ sender, EventArgs^ e)
{
    String^ updatedGrade = cboxGrades->SelectedItem->ToString();
    String^ studentName = cboxStudentName->Text;
    String^ courseName = cboxCourses->SelectedItem->ToString();

    // Find the student in the list by matching full name
    Student^ selectedStudent = nullptr;
    for each (Student ^ student in cachedStudents)
    {
        if (student->getFullName()->ToLower() == studentName->ToLower())
        {
            selectedStudent = student;
            break;
        }
    }

    if (selectedStudent == nullptr)
    {
        MessageBox::Show("Student not found.");
        return;
    }

    // Use the student's ID for the update query
    String^ query = R"(
    UPDATE Enrollments
    SET Grade = @grade
    WHERE StudentID = @studentID 
      AND CourseID = (
        SELECT c.CourseID 
        FROM Courses c 
        INNER JOIN CourseOfferings co ON c.CourseID = co.CourseID 
        WHERE c.CourseName = @courseName 
          AND co.FacultyID = @facultyID
    );
)";

    MySqlCommand^ command = gcnew MySqlCommand(query, db->GetConnection());
    command->Parameters->AddWithValue("@grade", updatedGrade);
    command->Parameters->AddWithValue("@studentID", selectedStudent->getStudentID());
    command->Parameters->AddWithValue("@courseName", courseName);
    command->Parameters->AddWithValue("@facultyID", faculty->getFacultyID());

    try {
        int result = command->ExecuteNonQuery();
        if (result > 0) {
            MessageBox::Show("Grade updated successfully.");
        }
        else {
            MessageBox::Show("No changes made, or grade already assigned.");
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error updating grade: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::cboxStudentName_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    // Disable event handlers temporarily
    cboxStudentName->TextChanged -= gcnew System::EventHandler(this, &GradeManagementForm::cboxStudentName_TextChanged);

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
    cboxStudentName->TextChanged += gcnew System::EventHandler(this, &GradeManagementForm::cboxStudentName_TextChanged);

}

System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::LoadStudentsToCache(DatabaseManager^ db, Object^ sender, EventArgs^ e)
{
    db->ConnectToDatabase();

    int^ facultyid = faculty->getFacultyID();

    // Update query to filter students where the departmentID matches the faculty's department
    String^ queryStudents = R"(
    SELECT 
        s.StudentID,
        u.UserID, 
        u.FirstName, 
        u.LastName, 
        u.Email,
        s.DepartmentID  -- Fetch the DepartmentID
    FROM 
        Students s
    INNER JOIN 
        Enrollments e ON s.StudentID = e.StudentID
    INNER JOIN 
        CourseOfferings co ON e.OfferingID = co.OfferingID
    INNER JOIN 
        Users u ON s.UserID = u.UserID
    WHERE 
        co.FacultyID = @facultyID
        AND s.IsDeleted = 0
        AND s.DepartmentID = (SELECT DepartmentID FROM Faculty WHERE FacultyID = @facultyID)  -- Matching the department
    )";

    MySqlCommand^ commandStudents = gcnew MySqlCommand(queryStudents, db->GetConnection());
    commandStudents->Parameters->AddWithValue("@facultyID", facultyid);

    MySqlDataReader^ readerStudents = commandStudents->ExecuteReader();

    cachedStudents->Clear();
    cboxStudentName->Items->Clear();

    while (readerStudents->Read())
    {
        int^ studentID = Convert::ToInt32(readerStudents["StudentID"]);
		int^ userID = Convert::ToInt32(readerStudents["UserID"]);
        String^ firstName = readerStudents["FirstName"]->ToString();
        String^ lastName = readerStudents["LastName"]->ToString();
		String^ email = readerStudents["Email"]->ToString();
        int^ departmentID = Convert::ToInt32(readerStudents["DepartmentID"]);  // Get the department ID

        // Create student object, note that the major is no longer needed, so we can leave it out
        Student^ student = gcnew Student(userID, firstName, lastName, email, studentID, departmentID);
        cachedStudents->Add(student);
        cboxStudentName->Items->Add(firstName + " " + lastName);  // Add the full name to the ComboBox
    }

    readerStudents->Close();
}

System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::cboxStudentName_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (cboxStudentName->SelectedIndex != -1)
    {
        String^ selectedName = cboxStudentName->SelectedItem->ToString();
        for each (Student ^ student in cachedStudents)
        {
            if (student->getFullName() == selectedName)
            {
                // Process selected student
                break;
            }
        }
    }
}



