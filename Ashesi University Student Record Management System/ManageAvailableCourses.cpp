#include "ManageAvailableCourses.h"
#include "DatabaseManager.h"

System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCoursesForm::LoadCourseCell(DatabaseManager^ db, DataGridViewCellEventArgs^ e)
{
    // Ensure the user has selected a row (row index should be >= 0)
    if (e->RowIndex >= 0)
    {
        // Get the selected row from the DataGridView
        DataGridViewRow^ selectedRow = dataGridViewCourse->Rows[e->RowIndex];

        // Check if the columns are present and fill the corresponding TextBoxes with values
        if (selectedRow->Cells["CourseName"] != nullptr)
            textBox1->Text = selectedRow->Cells["CourseName"]->Value->ToString();

        

    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCoursesForm::savecourses_Click(System::Object^ sender, System::EventArgs^ e, DataGridViewCellEventArgs^ g)
{
    // Validate input fields
    if (String::IsNullOrEmpty(textBox1->Text))
    {
        MessageBox::Show("Please enter the course name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    if (comboBox1->SelectedItem == nullptr)
    {
        MessageBox::Show("Please select a department.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Get input values
    String^ courseName = textBox1->Text;
    String^ selectedDepartmentName = comboBox1->SelectedItem->ToString();
    String^ semester = textBox2->Text;  // Assuming textBoxSemester for Semester
    String^ year = textBox4->Text;          // Assuming textBoxYear for Year
    int maxCapacity = Convert::ToInt32(textBox3->Text); // Assuming numericUpDownMaxCapacity for Max Capacity
    String^ status = comboBox3->SelectedItem->ToString(); // Assuming comboBoxStatus for Status (e.g., "Active", "Inactive")

    // Retrieve the Department ID corresponding to the selected department name
    DatabaseManager^ db = gcnew DatabaseManager();
    db->ConnectToDatabase();

    String^ getDepartmentIDQuery = "SELECT DepartmentID FROM Departments WHERE DepartmentName = @DepartmentName;";
    MySqlCommand^ getDeptIDCmd = gcnew MySqlCommand(getDepartmentIDQuery, db->GetConnection());
    getDeptIDCmd->Parameters->AddWithValue("@DepartmentName", selectedDepartmentName);

    Object^ departmentIDObj = getDeptIDCmd->ExecuteScalar();
    if (departmentIDObj == nullptr)
    {
        MessageBox::Show("Department not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
        return;
    }

    int departmentID = Convert::ToInt32(departmentIDObj);

    // Retrieve the Faculty ID based on the selected faculty name
    String^ facultyName = comboBox2->SelectedItem->ToString(); // Assuming comboBoxFacultyID for Faculty Name
    String^ getFacultyIDQuery = "SELECT FacultyID FROM Faculty WHERE FacultyName = @FacultyName;";
    MySqlCommand^ getFacultyIDCmd = gcnew MySqlCommand(getFacultyIDQuery, db->GetConnection());
    getFacultyIDCmd->Parameters->AddWithValue("@FacultyName", facultyName);

    Object^ facultyIDObj = getFacultyIDCmd->ExecuteScalar();
    if (facultyIDObj == nullptr)
    {
        MessageBox::Show("Faculty not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
        return;
    }

    int facultyID = Convert::ToInt32(facultyIDObj);

    int^ CourseID;
    if (g->RowIndex >= 0)
    {
        // Get the selected row from the DataGridView
        DataGridViewRow^ selectedRow = dataGridViewCourse->Rows[g->RowIndex];

        if (selectedRow->Cells["CourseID"] != nullptr)
            CourseID = Convert::ToInt32(selectedRow->Cells["CourseID"]->Value);
    }

    // SQL query for insert or update into CourseOffering table
    String^ query = R"(
        INSERT INTO CourseOffering (CourseID, DepartmentID, Semester, FacultyID, Year, MaxCapacity, Status)
        VALUES (@CourseID, @DepartmentID, @Semester, @FacultyID, @Year, @MaxCapacity, @Status);
    )";

    MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
    cmd->Parameters->AddWithValue("@CourseID", CourseID);
    cmd->Parameters->AddWithValue("@DepartmentID", departmentID);
    cmd->Parameters->AddWithValue("@Semester", semester);
    cmd->Parameters->AddWithValue("@FacultyID", facultyID);
    cmd->Parameters->AddWithValue("@Year", year);
    cmd->Parameters->AddWithValue("@MaxCapacity", maxCapacity);
    cmd->Parameters->AddWithValue("@Status", status);

    // Execute the query
    try
    {
        int rowsAffected = cmd->ExecuteNonQuery();
        if (rowsAffected > 0)
        {
            MessageBox::Show("Course offering saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            // Optionally reload courses to reflect changes
            btnviewcourses_Click(sender, e);
        }
        else
        {
            MessageBox::Show("No changes were made to the database.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("An error occurred while saving the course offering: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    db->CloseConnection();
}

System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCoursesForm::btnviewcourses_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ selectedDepartmentName = comboBox1->SelectedItem->ToString();
    if (String::IsNullOrEmpty(selectedDepartmentName))
    {
        MessageBox::Show("Please select a department to view its courses.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Retrieve the Department ID corresponding to the selected department name
    DatabaseManager^ db = gcnew DatabaseManager();
    db->ConnectToDatabase();

    String^ getDepartmentIDQuery = "SELECT DepartmentID FROM Departments WHERE DepartmentName = @DepartmentName;";
    MySqlCommand^ getDeptIDCmd = gcnew MySqlCommand(getDepartmentIDQuery, db->GetConnection());
    getDeptIDCmd->Parameters->AddWithValue("@DepartmentName", selectedDepartmentName);

    Object^ departmentIDObj = getDeptIDCmd->ExecuteScalar();
    if (departmentIDObj == nullptr)
    {
        MessageBox::Show("Department not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
        return;
    }

    int departmentID = Convert::ToInt32(departmentIDObj);

    // Load the courses based on the Department ID
    String^ query = R"(
        SELECT
            CourseID,
            CourseName,
            DepartmentID,
            IsActive
        FROM
            Courses
        WHERE
            DepartmentID = @DepartmentID AND IsActive = 1;
    )";

    MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
    cmd->Parameters->AddWithValue("@DepartmentID", departmentID);

    MySqlDataReader^ reader = cmd->ExecuteReader();

    // Clear any existing rows and columns in the DataGridView
    dataGridViewCourse->Rows->Clear();
    dataGridViewCourse->Columns->Clear();

    // Add the columns to the DataGridView
    dataGridViewCourse->Columns->Add("CourseID", "Course ID");
    dataGridViewCourse->Columns->Add("CourseName", "Course Name");
    dataGridViewCourse->Columns->Add("DepartmentID", "Department ID");
    dataGridViewCourse->Columns->Add("IsActive", "Is Active");

    // Iterate through the result set and populate the DataGridView
    while (reader->Read())
    {
        dataGridViewCourse->Rows->Add(
            reader["CourseID"]->ToString(),
            reader["CourseName"]->ToString(),
            reader["DepartmentID"]->ToString(),
            reader["IsActive"]->ToString()
        );
    }

    reader->Close();
    db->CloseConnection();
}

