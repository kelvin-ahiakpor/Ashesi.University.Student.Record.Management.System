#include "CourseManagementForm.h"
#include "DatabaseManager.h"

void AshesiUniversityStudentRecordManagementSystem::CourseManagementForm::LoadCourse()
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        db->ConnectToDatabase();

        // SQL query to retrieve course details
        String^ query = R"(
            SELECT
                CourseID,
                CourseName,
                DepartmentID,
                Credits,
                Description,
                Prerequisites
            FROM
                Courses;
        )";

        // Create a MySQL command using the query and the database connection
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());

        // Execute the query and get the results in a data reader
        MySqlDataReader^ reader = cmd->ExecuteReader();

        // Clear any existing rows and columns in the DataGridView
        dgvCourses->Rows->Clear();
        dgvCourses->Columns->Clear();

        // Add the columns to the DataGridView
        dgvCourses->Columns->Add("CourseID", "Course ID");
        dgvCourses->Columns->Add("CourseName", "Course Name");
        dgvCourses->Columns->Add("DepartmentID", "Department ID");
        dgvCourses->Columns->Add("Credits", "Credits");
        dgvCourses->Columns->Add("Description", "Description");
        dgvCourses->Columns->Add("Prerequisites", "Prerequisites");

        // Iterate through the result set and populate the DataGridView
        while (reader->Read())
        {
            dgvCourses->Rows->Add(
                reader["CourseID"]->ToString(),
                reader["CourseName"]->ToString(),
                reader["DepartmentID"]->ToString(),
                reader["Credits"]->ToString(),
                reader["Description"]->ToString(),
                reader["Prerequisites"]->ToString()
            );
        }

        reader->Close();
        db->CloseConnection();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error loading courses: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::CourseManagementForm::btnSaveCourse_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Validate the input fields
    if (txtCourseName->Text->Trim()->Length == 0 || txtCredits->Text->Trim()->Length == 0 || textBox1->Text->Trim()->Length == 0)
    {
        MessageBox::Show("Please fill in all required fields.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        db->ConnectToDatabase();

        // SQL query to fetch the DepartmentID based on DepartmentName
        String^ query = R"(
            SELECT DepartmentID 
            FROM Departments 
            WHERE DepartmentName = @DepartmentName;
        )";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@DepartmentName", textBox1->Text);

        MySqlDataReader^ reader = cmd->ExecuteReader();

        String^ departmentID;
        if (reader->Read())
        {
            departmentID = reader["DepartmentID"]->ToString();
        }

        reader->Close();

        // Check if the department was found
        if (departmentID == "")
        {
            MessageBox::Show("Department not found. Please enter a valid department name.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // SQL query for inserting a new course
        query = R"(
            INSERT INTO Courses (CourseName, DepartmentID, Credits, Description, Prerequisites)
            VALUES (@CourseName, @DepartmentID, @Credits, @Description, @Prerequisites);
        )";

        // Prepare command with parameters
        cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@CourseName", txtCourseName->Text);
        cmd->Parameters->AddWithValue("@DepartmentID", departmentID); // Use the fetched DepartmentID
        cmd->Parameters->AddWithValue("@Credits", txtCredits->Text);
        cmd->Parameters->AddWithValue("@Description", richTextBox1->Text);
        cmd->Parameters->AddWithValue("@Prerequisites", txtPrerequisites->Text);

        cmd->ExecuteNonQuery(); // Execute the insert query

        db->CloseConnection();

        MessageBox::Show("Course saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        LoadCourse(); // Refresh the DataGridView
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error saving course: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


System::Void AshesiUniversityStudentRecordManagementSystem::CourseManagementForm::btnDeleteCourse_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dgvCourses->SelectedRows->Count == 0)
    {
        MessageBox::Show("Please select a course to delete.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    String^ courseID = dgvCourses->SelectedRows[0]->Cells["CourseID"]->Value->ToString();

    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        db->ConnectToDatabase();

        // SQL query for deleting a course
        String^ query = "DELETE FROM Courses WHERE CourseID = @CourseID;";
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@CourseID", courseID);

        cmd->ExecuteNonQuery();

        db->CloseConnection();

        MessageBox::Show("Course deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        LoadCourse();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error deleting course: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::CourseManagementForm::btnEditCourse_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dgvCourses->SelectedRows->Count == 0)
    {
        MessageBox::Show("Please select a course to edit.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    String^ courseID = dgvCourses->SelectedRows[0]->Cells["CourseID"]->Value->ToString();

    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        db->ConnectToDatabase();

        // SQL query to fetch the DepartmentID based on DepartmentName
        String^ query = R"(
            SELECT DepartmentID 
            FROM Departments 
            WHERE DepartmentName = @DepartmentName;
        )";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@DepartmentName", textBox1->Text);

        MySqlDataReader^ reader = cmd->ExecuteReader();

        String^ departmentID; // Default to -1 if not found
        if (reader->Read())
        {
            departmentID = reader["DepartmentID"]->ToString();
        }

        reader->Close();

        // Check if the department was found
        if (departmentID == "")
        {
            MessageBox::Show("Department not found. Please enter a valid department name.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // SQL query for updating a course
        query = R"(
            UPDATE Courses
            SET CourseName = @CourseName, 
                DepartmentID = @DepartmentID, 
                Credits = @Credits, 
                Description = @Description, 
                Prerequisites = @Prerequisites
            WHERE CourseID = @CourseID;
        )";

        cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@CourseID", courseID);
        cmd->Parameters->AddWithValue("@CourseName", txtCourseName->Text);
        cmd->Parameters->AddWithValue("@DepartmentID", departmentID); // Use the fetched DepartmentID
        cmd->Parameters->AddWithValue("@Credits", txtCredits->Text);
        cmd->Parameters->AddWithValue("@Description", richTextBox1->Text);
        cmd->Parameters->AddWithValue("@Prerequisites", txtPrerequisites->Text);

        cmd->ExecuteNonQuery();

        db->CloseConnection();

        MessageBox::Show("Course updated successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        LoadCourse();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error updating course: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

void AshesiUniversityStudentRecordManagementSystem::CourseManagementForm::dgvCourses_CellClick(
    System::Object^ sender,
    System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dgvCourses->Rows[e->RowIndex];
        txtCourseName->Text = selectedRow->Cells["CourseName"]->Value->ToString();
        txtCredits->Text = selectedRow->Cells["Credits"]->Value->ToString();
        txtPrerequisites->Text = selectedRow->Cells["Prerequisites"]->Value->ToString();
        richTextBox1->Text = selectedRow->Cells["Description"]->Value->ToString();
    }
}
