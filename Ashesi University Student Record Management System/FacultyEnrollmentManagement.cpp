#include "FacultyEnrollmentManagement.h"
#include "DatabaseManager.h"

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyEnrollmentManagement::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dataGridView1->Rows[e->RowIndex];

        textBox1->Text = (selectedRow->Cells["FirstName"]->Value ? selectedRow->Cells["FirstName"]->Value->ToString() : "")
            + " " + (selectedRow->Cells["LastName"]->Value ? selectedRow->Cells["LastName"]->Value->ToString() : "");
        textBox2->Text = selectedRow->Cells["CourseName"]->Value ? selectedRow->Cells["CourseName"]->Value->ToString() : "";
        textBox5->Text = selectedRow->Cells["DepartmentName"]->Value ? selectedRow->Cells["DepartmentName"]->Value->ToString() : "";
        textBox4->Text = selectedRow->Cells["Semester"]->Value ? selectedRow->Cells["Semester"]->Value->ToString() : "";

        String^ enrollString = selectedRow->Cells["EnrollmentDate"]->Value ? selectedRow->Cells["EnrollmentDate"]->Value->ToString() : "";
        dateTimePicker3->Value = String::IsNullOrEmpty(enrollString) ? System::DateTime::Now : System::DateTime::Parse(enrollString);

        String^ status = selectedRow->Cells["Status"]->Value ? selectedRow->Cells["Status"]->Value->ToString() : "";
        textBoxStatus->Text = status; 
    }
}


System::Void AshesiUniversityStudentRecordManagementSystem::FacultyEnrollmentManagement::ViewEnroll_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
		ViewEnrollments(db, sender, e);
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error fetching enrollment data: " + ex->Message);
    }
    finally
    {
        db->CloseConnection();
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyEnrollmentManagement::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyEnrollmentManagement::btnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        db->ConnectToDatabase();

        if (db->GetConnection()->State != System::Data::ConnectionState::Open)
        {
            MessageBox::Show("Database connection failed.");
            return;
        }

        // Validate that a row is selected in the DataGridView
        if (dataGridView1->SelectedRows->Count == 0)
        {
            MessageBox::Show("Please select a record to update.");
            return;
        }

        // Get the selected row and EnrollmentID
        DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];
        String^ enrollmentID = selectedRow->Cells["EnrollmentID"]->Value->ToString();

        // Get the new status from the TextBox instead of the ComboBox
        String^ newStatus = textBoxStatus->Text; // Assuming textBoxStatus holds the status value

        if (String::IsNullOrEmpty(newStatus))
        {
            MessageBox::Show("Please enter a valid status.");
            return;
        }

        // SQL query to update the status
        String^ query = "UPDATE Enrollments SET Status = @newStatus WHERE EnrollmentID = @enrollmentID;";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@newStatus", newStatus);
        cmd->Parameters->AddWithValue("@enrollmentID", enrollmentID);

        int rowsAffected = cmd->ExecuteNonQuery();
        if (rowsAffected > 0)
        {
            MessageBox::Show("Status updated successfully!");
            db->CloseConnection();
            ViewEnroll_Click(sender, e); // Refresh the enrollment view
        }
        else
        {
            MessageBox::Show("Error updating status.");
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error: " + ex->Message);
    }
    finally
    {
        db->CloseConnection();
    }
}

//helper method to view enrollments
System::Void AshesiUniversityStudentRecordManagementSystem::FacultyEnrollmentManagement::ViewEnrollments(DatabaseManager^ db, System::Object^ sender, System::EventArgs^ e)
{
    db->ConnectToDatabase();

    // Ensure the database connection is open
    if (db->GetConnection()->State != System::Data::ConnectionState::Open)
    {
        MessageBox::Show("Database connection failed.");
        return;
    }

    // SQL query to retrieve enrollment data
    String^ query = R"(
    SELECT e.EnrollmentID, c.CourseName, d.DepartmentName, u.FirstName, u.LastName, c.Credits, c.Description, c.Prerequisites, co.Semester, e.EnrollmentDate, e.Status 
    FROM Enrollments e
    INNER JOIN CourseOfferings co ON e.CourseID = co.CourseID
    INNER JOIN Courses c ON co.CourseID = c.CourseID
    INNER JOIN Departments d ON c.DepartmentID = d.DepartmentID
    INNER JOIN Faculty f ON co.FacultyID = f.FacultyID
    INNER JOIN Students s ON e.StudentID = s.StudentID
    INNER JOIN Users u ON s.UserID = u.UserID
    WHERE f.FacultyID = @facultyid;
)";


    MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
    cmd->Parameters->AddWithValue("@facultyid", faculty->getFacultyID());

    MySqlDataReader^ reader = cmd->ExecuteReader();

    if (!reader->HasRows)
    {
        MessageBox::Show("No enrollments found for the given faculty.");
        return;
    }

    // Add columns if not already added
    if (dataGridView1->Columns->Count == 0)
    {
        dataGridView1->Columns->Add("EnrollmentID", "Enrollment ID");
        dataGridView1->Columns->Add("CourseName", "Course Name");
        dataGridView1->Columns->Add("FirstName", "First Name");
        dataGridView1->Columns->Add("LastName", "Last Name");
        dataGridView1->Columns->Add("DepartmentName", "Department Name");
        dataGridView1->Columns->Add("Credits", "Credits");
        dataGridView1->Columns->Add("Description", "Description");
        dataGridView1->Columns->Add("Prerequisites", "Prerequisites");
        dataGridView1->Columns->Add("Semester", "Semester");
        dataGridView1->Columns->Add("EnrollmentDate", "EnrollmentDate");
        dataGridView1->Columns->Add("Status", "Status");
    }

    // Populate DataGridView with data
    while (reader->Read())
    {
        dataGridView1->Rows->Add(
            reader["EnrollmentID"] != DBNull::Value ? reader["EnrollmentID"]->ToString() : "",
            reader["CourseName"] != DBNull::Value ? reader["CourseName"]->ToString() : "",
            reader["FirstName"] != DBNull::Value ? reader["FirstName"]->ToString() : "",
            reader["LastName"] != DBNull::Value ? reader["LastName"]->ToString() : "",
            reader["DepartmentName"] != DBNull::Value ? reader["DepartmentName"]->ToString() : "",
            reader["Credits"] != DBNull::Value ? reader["Credits"]->ToString() : "",
            reader["Description"] != DBNull::Value ? reader["Description"]->ToString() : "",
            reader["Prerequisites"] != DBNull::Value ? reader["Prerequisites"]->ToString() : "",
            reader["Semester"] != DBNull::Value ? reader["Semester"]->ToString() : "",
            reader["EnrollmentDate"] != DBNull::Value ? reader["EnrollmentDate"]->ToString() : "",
            reader["Status"] != DBNull::Value ? reader["Status"]->ToString() : ""
        );
    }

    reader->Close();
    dataGridView1->Refresh();
}

