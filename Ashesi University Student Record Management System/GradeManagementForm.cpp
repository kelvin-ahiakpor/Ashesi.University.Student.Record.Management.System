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
}

System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::btnSubmitGrade_Click(System::Object^ sender, System::EventArgs^ e)
{
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
    // Establish a connection to the database
    db->ConnectToDatabase();

    // Assuming facultyID is stored in a variable or passed into the form
    int^ facultyid = faculty->getFacultyID();

    // SQL query to fetch courses taught by the faculty
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

    // SQL query to fetch all possible grades (you could hardcode them or fetch from a database if needed)
    List<String^>^ grades = gcnew List<String^>();
    grades->Add("A+");
    grades->Add("A");
    grades->Add("B+");
    grades->Add("B");
    grades->Add("C+");
    grades->Add("C");
    grades->Add("D+");
    grades->Add("D");
    grades->Add("E");
    grades->Add("F");

    // Create a command and set the facultyID parameter for courses taught
    MySqlCommand^ commandCourses = gcnew MySqlCommand(queryCourses, db->GetConnection());
    commandCourses->Parameters->AddWithValue("@facultyID", facultyid);

    MySqlDataReader^ readerCourses = commandCourses->ExecuteReader();

    // Clear ComboBox items before populating them
    cboxCourses->Items->Clear();

    // Populate the cboxCourses with course names
    while (readerCourses->Read())
    {
        String^ courseName = readerCourses["CourseName"]->ToString();
        cboxCourses->Items->Add(courseName);  // Adding each course taught by the lecturer
    }

    readerCourses->Close(); // Close the reader for courses

    // Populate the cboxGrades ComboBox with all available grades
    cboxGrades->Items->Clear();
    for each (String ^ grade in grades)
    {
        cboxGrades->Items->Add(grade); // Adding grades to ComboBox
    }
}


System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::SubmitGrade(DatabaseManager^ db, Object^ sender, EventArgs^ e)
{
    String^ updatedGrade = cboxGrades->SelectedItem->ToString();
    String^ studentID = cboxStudentName->Text;
    String^ courseName = cboxCourses->SelectedItem->ToString();  // Get course from ComboBox

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
    command->Parameters->AddWithValue("@studentID", studentID);
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


