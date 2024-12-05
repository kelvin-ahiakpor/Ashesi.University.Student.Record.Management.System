#include "ManageAvailableCourses.h"
#include "DatabaseManager.h"


System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCourses::savecourses_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Validate input fields
    if (String::IsNullOrEmpty(cboxCourses->Text))
    {
        MessageBox::Show("Please enter the course name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    if (cboxDeptName->SelectedItem == nullptr)
    {
        MessageBox::Show("Please select a department.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Get input values
    String^ courseName = cboxCourses->Text;
    String^ selectedDepartmentName = cboxDeptName->SelectedItem->ToString();
    String^ semester = comboBox1->SelectedItem->ToString();  // Assuming textBoxSemester for Semester
    String^ year = textBox4->Text;      // Assuming textBoxYear for Year
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
    String^ facultyName = cboxFaculty->SelectedItem->ToString(); // Assuming comboBoxFacultyID for Faculty Name
    String^ getFacultyIDQuery = "SELECT f.FacultyID FROM Faculty f JOIN Users u ON f.UserID = u.UserID WHERE CONCAT(u.FirstName, ' ', u.LastName) = @FacultyName;";
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

    // Ensure a row is selected
    if (dataGridViewCourse->SelectedCells->Count > 0)
    {
        DataGridViewCell^ selectedCell = dataGridViewCourse->SelectedCells[0];
        DataGridViewRow^ selectedRow = selectedCell->OwningRow;

        // Get the CourseID from the selected row
        if (selectedRow->Cells["CourseID"] != nullptr)
        {
            int CourseID = Convert::ToInt32(selectedRow->Cells["CourseID"]->Value);

            // SQL query for insert or update into CourseOffering table
            String^ query = R"(
                INSERT INTO CourseOfferings (CourseID, Semester, FacultyID, Year, MaxCapacity, Status)
                VALUES (@CourseID, @Semester, @FacultyID, @Year, @MaxCapacity, @Status);
            )";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
            cmd->Parameters->AddWithValue("@CourseID", CourseID);
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
        }
        else
        {
            MessageBox::Show("Course ID is missing from the selected row.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    else
    {
        MessageBox::Show("Please select a row from the DataGridView to proceed.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    db->CloseConnection();
}


System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCourses::btnviewcourses_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ selectedDepartmentName;
    
    if (cboxDeptName->SelectedItem == nullptr) {
        selectedDepartmentName = cboxDeptName->Text;
    }else{
		selectedDepartmentName = cboxDeptName->SelectedItem->ToString();
	}
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

System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCourses::btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Ensure a row is selected in the DataGridView
    if (dataGridViewCourse->SelectedCells->Count > 0)
    {
        DataGridViewCell^ selectedCell = dataGridViewCourse->SelectedCells[0];
        DataGridViewRow^ selectedRow = selectedCell->OwningRow;

        // Get the CourseID from the selected row
        int courseID = Convert::ToInt32(selectedRow->Cells["CourseID"]->Value);

        // Confirm deletion (custom message box)
        if (MessageBox::Show("Are you sure you want to delete this course?", "Confirm Deletion", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == Windows::Forms::DialogResult::OK)
        {
            // Proceed with the deletion logic
            DatabaseManager^ db = gcnew DatabaseManager();
            db->ConnectToDatabase();

            String^ query = "DELETE FROM CourseOfferings WHERE CourseID = @CourseID;";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
            cmd->Parameters->AddWithValue("@CourseID", courseID);

            try
            {
                int rowsAffected = cmd->ExecuteNonQuery();
                if (rowsAffected > 0)
                {
                    MessageBox::Show("Course deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    // Optionally, reload courses to reflect changes
                    btnviewcourses_Click(sender, e);
                }
                else
                {
                    MessageBox::Show("No such course exists to delete.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("An error occurred while deleting the course: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }

            db->CloseConnection();
        }
    }
    else
    {
        MessageBox::Show("Please select a course to delete.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCourses::btnEdit_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Ensure a row is selected
    if (dataGridViewCourse->SelectedCells->Count > 0)
    {
        DataGridViewCell^ selectedCell = dataGridViewCourse->SelectedCells[0];
        DataGridViewRow^ selectedRow = selectedCell->OwningRow;

        // Get the CourseID from the selected row
        int CourseID = Convert::ToInt32(selectedRow->Cells["CourseID"]->Value);

        // Get the values from TextBoxes and ComboBoxes
        String^ courseName = cboxCourses->Text;
        String^ selectedDepartmentName = cboxDeptName->SelectedItem->ToString();
        String^ semester = comboBox1->SelectedItem->ToString();
        String^ year = textBox4->Text;
        int maxCapacity = Convert::ToInt32(textBox3->Text);
        String^ status = comboBox3->SelectedItem->ToString();

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

        // SQL query for updating the CourseOffering table
        String^ updateQuery = R"(
            UPDATE CourseOffering
            SET CourseName = @CourseName, Semester = @Semester, Year = @Year,
                MaxCapacity = @MaxCapacity, Status = @Status
            WHERE CourseID = @CourseID;
        )";

        MySqlCommand^ updateCmd = gcnew MySqlCommand(updateQuery, db->GetConnection());
        updateCmd->Parameters->AddWithValue("@CourseID", CourseID);
        updateCmd->Parameters->AddWithValue("@CourseName", courseName);
        updateCmd->Parameters->AddWithValue("@Semester", semester);
        updateCmd->Parameters->AddWithValue("@Year", year);
        updateCmd->Parameters->AddWithValue("@MaxCapacity", maxCapacity);
        updateCmd->Parameters->AddWithValue("@Status", status);

        try
        {
            int rowsAffected = updateCmd->ExecuteNonQuery();
            if (rowsAffected > 0)
            {
                MessageBox::Show("Course offering updated successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
            MessageBox::Show("An error occurred while updating the course offering: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        db->CloseConnection();
    }
    else
    {
        MessageBox::Show("Please select a course from the DataGridView to edit.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCourses::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    // Ensure the user has selected a row (row index should be >= 0)
    if (e->RowIndex >= 0)
    {
        // Get the selected row from the DataGridView
        DataGridViewRow^ selectedRow = dataGridViewCourse->Rows[e->RowIndex];

        // Check if the columns are present and fill the corresponding TextBoxes with values
        if (selectedRow->Cells["CourseName"] != nullptr)
            cboxCourses->Text = selectedRow->Cells["CourseName"]->Value->ToString();



    }
    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCourses::LoadCourses(DatabaseManager^ db)
{
    db->ConnectToDatabase();

    String^ deleteStudentQuery = R"(
        SELECT DepartmentName FROM Departments;
		)";

    MySqlCommand^ cmd = gcnew MySqlCommand(deleteStudentQuery, db->GetConnection());
    MySqlDataReader^ reader = cmd->ExecuteReader();

    cboxDeptName->Items->Clear();

    while (reader->Read())
    {
        cboxDeptName->Items->Add(reader["DepartmentName"]->ToString());
    }

    reader->Close();
    db->CloseConnection();
}

System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCourses::LoadFacultyForSelectedDepartment(Object^ sender, EventArgs^ e)
{
    // Ensure a department is selected
    if (cboxDeptName->SelectedItem == nullptr)
    {
        MessageBox::Show("Please select a department to load its faculty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Retrieve the DepartmentID corresponding to the selected department name
    String^ selectedDepartmentName = cboxDeptName->SelectedItem->ToString();
    DatabaseManager^ db = gcnew DatabaseManager();
    db->ConnectToDatabase();

    String^ query = "SELECT DepartmentID FROM Departments WHERE DepartmentName = @DepartmentName;";
    MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
    cmd->Parameters->AddWithValue("@DepartmentName", selectedDepartmentName);

    Object^ departmentIDObj = cmd->ExecuteScalar();
    if (departmentIDObj == nullptr)
    {
        MessageBox::Show("Department not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
        return;
    }

    int departmentID = Convert::ToInt32(departmentIDObj);

    // Retrieve faculty for the selected department
    String^ queryFaculty = R"(
    SELECT 
        u.FirstName, 
        u.LastName 
    FROM 
        Users u 
    JOIN 
        Faculty f ON u.UserID = f.UserID 
    WHERE 
        f.DepartmentID = @DepartmentID AND f.IsDeleted = 0;
)";

    MySqlCommand^ cmdFaculty = gcnew MySqlCommand(queryFaculty, db->GetConnection());
    cmdFaculty->Parameters->AddWithValue("@DepartmentID", departmentID);

    MySqlDataReader^ readerFaculty = cmdFaculty->ExecuteReader();

    // Clear previous items in the ComboBox
    cboxFaculty->Items->Clear();

    // Populate the faculty ComboBox with full names (FirstName + LastName)
    while (readerFaculty->Read())
    {
        String^ facultyFullName = readerFaculty["FirstName"]->ToString() + " " + readerFaculty["LastName"]->ToString();
        cboxFaculty->Items->Add(facultyFullName);
    }

    readerFaculty->Close();
    db->CloseConnection();

}

System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCourses::cboxDeptName_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    LoadFacultyForSelectedDepartment(sender, e);
	LoadCoursesForSelectedDepartment(sender, e);
}

System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCourses::ManageAvailableCourses_Load(System::Object^ sender, System::EventArgs^ e)
{
	DatabaseManager^ db = gcnew DatabaseManager();
	LoadCourses(db);
}

System::Void AshesiUniversityStudentRecordManagementSystem::ManageAvailableCourses::LoadCoursesForSelectedDepartment(Object^ sender, System::EventArgs^ e)
{
    // Ensure a department is selected
    if (cboxDeptName->SelectedItem == nullptr)
    {
        MessageBox::Show("Please select a department to load its faculty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Retrieve the DepartmentID corresponding to the selected department name
    String^ selectedDepartmentName = cboxDeptName->SelectedItem->ToString();
    DatabaseManager^ db = gcnew DatabaseManager();
    db->ConnectToDatabase();

    String^ query = "SELECT DepartmentID FROM Departments WHERE DepartmentName = @DepartmentName;";
    MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
    cmd->Parameters->AddWithValue("@DepartmentName", selectedDepartmentName);

    Object^ departmentIDObj = cmd->ExecuteScalar();
    if (departmentIDObj == nullptr)
    {
        MessageBox::Show("Department not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
        return;
    }

    int departmentID = Convert::ToInt32(departmentIDObj);

    // Retrieve faculty for the selected department
    String^ queryFaculty = R"(
    SELECT 
        c.CourseName
    FROM 
        Courses c 
    WHERE 
        c.DepartmentID = @DepartmentID;
    )";

    MySqlCommand^ cmdFaculty = gcnew MySqlCommand(queryFaculty, db->GetConnection());
    cmdFaculty->Parameters->AddWithValue("@DepartmentID", departmentID);

    MySqlDataReader^ readerFaculty = cmdFaculty->ExecuteReader();

    // Clear previous items in the ComboBox
    cboxCourses->Items->Clear();

    // Populate the faculty ComboBox with full names (FirstName + LastName)
    while (readerFaculty->Read())
    {
        String^ courseName = readerFaculty["CourseName"]->ToString();
        cboxCourses->Items->Add(courseName);
    }

    readerFaculty->Close();
    db->CloseConnection();
}
