#include "StudentManagementForm.h"
#include "DatabaseManager.h"



System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{

    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();
    try
    {
        db->ConnectToDatabase();

        // SQL query to retrieve user and student details by joining Users and Students tables
        String^ query = R"(
        SELECT
            Users.UserID,
            Users.FirstName,
            Users.LastName,
            Users.Email,
            Users.UserType,
            Students.StudentID,
            Students.DateOfBirth,
            Students.DepartmentID,
            Students.EnrollmentDate,
            Students.ExpectedGraduation
        FROM
            Students
        INNER JOIN
            Users ON Students.UserID = Users.UserID;
        )";

        // Create a MySQL command using the query and the database connection
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());

        // Execute the query and get the results in a data reader
        MySqlDataReader^ reader = cmd->ExecuteReader();

        // Clear any existing rows and columns in the DataGridView
        dataGridView1->Rows->Clear();
        dataGridView1->Columns->Clear();

        // Add the columns to the DataGridView (match the SQL query)
        dataGridView1->Columns->Add("UserID", "User ID");
        dataGridView1->Columns->Add("FirstName", "First Name");
        dataGridView1->Columns->Add("LastName", "Last Name");
        dataGridView1->Columns->Add("Email", "Email");
        dataGridView1->Columns->Add("UserType", "User Type");
        dataGridView1->Columns->Add("StudentID", "Student ID");
        dataGridView1->Columns->Add("DateOfBirth", "Date of Birth");
        dataGridView1->Columns->Add("DepartmentID", "Department ID");
        dataGridView1->Columns->Add("EnrollmentDate", "Enrollment Date");
        dataGridView1->Columns->Add("ExpectedGraduation", "Expected Graduation");

        // Iterate through the result set and populate the DataGridView
        while (reader->Read())
        {
            dataGridView1->Rows->Add(
                reader["UserID"]->ToString(),
                reader["FirstName"]->ToString(),
                reader["LastName"]->ToString(),
                reader["Email"]->ToString(),
                reader["UserType"]->ToString(),
                reader["StudentID"]->ToString(),
                reader["DateOfBirth"]->ToString(),
                reader["DepartmentID"]->ToString(),
                reader["EnrollmentDate"]->ToString(),
                reader["ExpectedGraduation"]->ToString()
            );
        }

        reader->Close();
        db->CloseConnection();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error loading users: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    return System::Void();
}


System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{

    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        db->ConnectToDatabase();

        // SQL query to retrieve user details
        String^ query = R"(
        SELECT
            UserID,
            FirstName,
            LastName,
            Email,
            UserType
        FROM
            Users
        WHERE
            UserType = 'Student';
    )";

        // Create a MySQL command using the query and the database connection
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());

        // Execute the query and get the results in a data reader
        MySqlDataReader^ reader = cmd->ExecuteReader();

        // Clear any existing rows and columns in the DataGridView
        dataGridView1->Rows->Clear();
        dataGridView1->Columns->Clear();

        // Add the columns to the DataGridView (match the SQL query)
        dataGridView1->Columns->Add("UserID", "User ID");
        dataGridView1->Columns->Add("FirstName", "First Name");
        dataGridView1->Columns->Add("LastName", "Last Name");
        dataGridView1->Columns->Add("Email", "Email");
        dataGridView1->Columns->Add("UserType", "User Type");

        // Iterate through the result set and populate the DataGridView
        while (reader->Read())
        {
            dataGridView1->Rows->Add(
                reader["UserID"]->ToString(),
                reader["FirstName"]->ToString(),
                reader["LastName"]->ToString(),
                reader["Email"]->ToString(),
                reader["UserType"]->ToString()
            );
        }

        reader->Close();
        db->CloseConnection();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error loading users: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Delete student record
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        db->ConnectToDatabase();

        // Start a database transaction to ensure atomic operations
        MySqlTransaction^ transaction = db->GetConnection()->BeginTransaction();

        // Retrieve selected row data
        if (dataGridView1->SelectedRows->Count == 0)
        {
            MessageBox::Show("Please select a student to delete.", "No Selection", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];
        String^ userID = selectedRow->Cells["UserID"]->Value->ToString();

        // SQL query to delete from the Students table
        String^ deleteStudentQuery = R"(
        DELETE FROM Students
        WHERE UserID = @UserID;
        )";

        // Create and execute MySQL command for Students table
        MySqlCommand^ deleteStudentCmd = gcnew MySqlCommand(deleteStudentQuery, db->GetConnection());
        deleteStudentCmd->Parameters->AddWithValue("@UserID", userID);
        deleteStudentCmd->Transaction = transaction;

        int studentRowsAffected = deleteStudentCmd->ExecuteNonQuery();

        // If student record was deleted, proceed to delete from Users table
        if (studentRowsAffected > 0)
        {
            // SQL query to delete from the Users table
            String^ deleteUserQuery = R"(
            DELETE FROM Users
            WHERE UserID = @UserID;
            )";



            // Create and execute MySQL command for Users table
            MySqlCommand^ deleteUserCmd = gcnew MySqlCommand(deleteUserQuery, db->GetConnection());
            deleteUserCmd->Parameters->AddWithValue("@UserID", userID);
            deleteUserCmd->Transaction = transaction;

            int userRowsAffected = deleteUserCmd->ExecuteNonQuery();

            if (userRowsAffected > 0)
            {
                // Commit the transaction if both deletions are successful
                transaction->Commit();
                MessageBox::Show("Student deleted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                button1_Click(sender, e); // Refresh the DataGridView
            }
            else
            {
                // Rollback if the user deletion fails
                transaction->Rollback();
                MessageBox::Show("Failed to delete the user from the Users table.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        else
        {
            // Rollback if the student deletion fails
            transaction->Rollback();
            MessageBox::Show("Failed to delete the student from the Students table.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        db->CloseConnection();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error deleting student: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}


System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    // Ensure the user has selected a row (row index should be >= 0)
    if (e->RowIndex >= 0)
    {
        // Get the selected row from the DataGridView
        DataGridViewRow^ selectedRow = dataGridView1->Rows[e->RowIndex];

        // Check if the columns are present and fill the corresponding TextBoxes with values
        if (selectedRow->Cells["StudentID"] != nullptr)
            textBox5->Text = selectedRow->Cells["StudentID"]->Value->ToString();

        if (selectedRow->Cells["FirstName"] != nullptr)
            textBox1->Text = selectedRow->Cells["FirstName"]->Value->ToString();

        if (selectedRow->Cells["LastName"] != nullptr)
            textBox2->Text = selectedRow->Cells["LastName"]->Value->ToString();

        if (selectedRow->Cells["Email"] != nullptr)
            textBox4->Text = selectedRow->Cells["Email"]->Value->ToString();

        // Assign DateTimePicker values based on different fields
        if (selectedRow->Cells["DateOfBirth"] != nullptr)
        {
            // Assuming the value from the DataGridView cell is a DateTime
            String^ dobString = selectedRow->Cells["DateOfBirth"]->Value->ToString();
            dateTimePicker1->Value = System::DateTime::Parse(dobString);
        }

        if (selectedRow->Cells["EnrollmentDate"] != nullptr)
        {
            // Assuming the value from the DataGridView cell is a DateTime
            String^ enrollmentDateString = selectedRow->Cells["EnrollmentDate"]->Value->ToString();
            dateTimePicker2->Value = System::DateTime::Parse(enrollmentDateString);  // Assuming a different DateTimePicker (dateTimePicker2) for Enrollment Date
        }

        if (selectedRow->Cells["ExpectedGraduation"] != nullptr)
        {
            // Assuming the value from the DataGridView cell is a DateTime
            String^ graduationDateString = selectedRow->Cells["ExpectedGraduation"]->Value->ToString();
            dateTimePicker3->Value = System::DateTime::Parse(graduationDateString);  // Assuming a different DateTimePicker (dateTimePicker3) for Expected Graduation Date
        }

        try
        {
            db->ConnectToDatabase();

            String^ query = R"(
    SELECT DepartmentName FROM Departments
    WHERE DepartmentID = @DepartmentID;
    )";

            // Get the DepartmentID from the selected row
            String^ DepartmentID = selectedRow->Cells["DepartmentID"]->Value->ToString();

            // Create MySQL command and add the parameter
            MySqlCommand^ sqlCmd = gcnew MySqlCommand(query, db->GetConnection());
            sqlCmd->Parameters->AddWithValue("@DepartmentID", DepartmentID);

            // Execute the query and get the result
            MySqlDataReader^ reader = sqlCmd->ExecuteReader();

            // Check if the query returned any result
            if (reader->Read())
            {
                // Get the DepartmentName from the reader
                String^ DepartmentName = reader["DepartmentName"]->ToString();

                // Display the department name in textBox3
                textBox3->Text = DepartmentName;
            }

            reader->Close();
            db->CloseConnection();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error retrieving department name: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    return;  // Return void, not System::Void()
}

