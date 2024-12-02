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
        // Establish a connection to the database
        db->ConnectToDatabase();

        // Assuming facultyID is stored in a variable or passed into the form
        int^ facultyid = faculty->getFacultyID(); // Replace with actual faculty ID (e.g., from the logged-in session)

        // SQL query to check if a student is enrolled in the course, if a grade exists, and only show courses for the faculty
        String^ query = R"(
    SELECT
        c.CourseName
    FROM
        Courses c
    INNER JOIN
        Enrollments e ON c.CourseID = e.CourseID
    INNER JOIN
        CourseOfferings co ON e.CourseID = co.CourseID
    WHERE
        co.facultyID = @facultyID;
)";


        // Create a command and set the facultyID parameter
        MySqlCommand^ command = gcnew MySqlCommand(query, db->GetConnection());
        command->Parameters->AddWithValue("@facultyID", facultyid);

        MySqlDataReader^ reader = command->ExecuteReader();
        if (reader->Read())
        {
            String^ courseName = reader["CourseName"]->ToString();

            // Populate ComboBox with grade options
            cboxGrades->Items->Clear();  // Clear existing items (if any)
            cboxGrades->Items->Add("A");  // Example grade options, add more if needed
            cboxGrades->Items->Add("B");
            cboxGrades->Items->Add("C");
            cboxGrades->Items->Add("D");
            cboxGrades->Items->Add("F");

            this->CourseNameBox->Text = courseName;
        }
        else
        {
            MessageBox::Show("No profile found for the specified user ID.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        // Close the reader after processing the data
        reader->Close();
    }
    catch (Exception^ ex) {
        // Handle any exceptions that may occur
        MessageBox::Show("Error: " + ex->Message);
    }
}


System::Void AshesiUniversityStudentRecordManagementSystem::GradeManagementForm::btnSubmitGrade_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try {
        String^ updatedGrade = cboxGrades->SelectedItem->ToString();
        String^ studentID = txtStudentID->Text; 
        String^ courseName = CourseNameBox->Text; 

        String^ query = R"(
    UPDATE Enrollments
    SET Grade = @grade
    WHERE studentID = @studentID AND courseID = (
        SELECT c.CourseID 
        FROM Courses c 
        INNER JOIN CourseOfferings co ON c.CourseID = co.CourseID 
        WHERE c.CourseName = @courseName AND co.facultyID = @facultyID
    );
)";


        MySqlCommand^ command = gcnew MySqlCommand(query, db->GetConnection());
        command->Parameters->AddWithValue("@grade", updatedGrade);
        command->Parameters->AddWithValue("@studentID", studentID);
        command->Parameters->AddWithValue("@courseName", courseName);
        command->Parameters->AddWithValue("@facultyID", faculty->getFacultyID()); 

        int result = command->ExecuteNonQuery();

        if (result > 0) {
            MessageBox::Show("Grade updated successfully.");
        }
        else {
            MessageBox::Show("No changes made, or grade already assigned.");
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
}
