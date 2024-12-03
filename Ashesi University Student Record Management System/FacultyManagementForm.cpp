#include "FacultyManagementForm.h"
#include "DatabaseManager.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyManagementForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        // Validate input fields
        if (String::IsNullOrWhiteSpace(textBox1->Text) || String::IsNullOrWhiteSpace(textBox2->Text) ||
            String::IsNullOrWhiteSpace(textBox4->Text) || String::IsNullOrWhiteSpace(textBox5->Text))
        {
            MessageBox::Show("Please fill in all required fields.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        db->ConnectToDatabase();

        // Insert into Users table
        String^ insertUserQuery = R"(
        INSERT INTO Users (FirstName, LastName, Email, Password, UserType)
        VALUES (@FirstName, @LastName, @Email, 'password123', 'Faculty');
        SELECT LAST_INSERT_ID();
        )";

        MySqlCommand^ cmdInsertUser = gcnew MySqlCommand(insertUserQuery, db->GetConnection());
        cmdInsertUser->Parameters->AddWithValue("@FirstName", textBox1->Text);
        cmdInsertUser->Parameters->AddWithValue("@LastName", textBox2->Text);
        cmdInsertUser->Parameters->AddWithValue("@Email", textBox4->Text);

        // Execute the command and retrieve the new UserID
        Object^ userIDObj = cmdInsertUser->ExecuteScalar();
        if (userIDObj == nullptr)
        {
            MessageBox::Show("Failed to add user to the Users table.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            db->CloseConnection();
            return;
        }

        int userID = Convert::ToInt32(userIDObj);

        // Get the DepartmentID from the department name
        String^ getDepartmentIDQuery = R"(
        SELECT DepartmentID FROM Departments
        WHERE DepartmentName = @DepartmentName;
        )";

        MySqlCommand^ departmentCmd = gcnew MySqlCommand(getDepartmentIDQuery, db->GetConnection());
        departmentCmd->Parameters->AddWithValue("@DepartmentName", textBox3->Text);

        Object^ departmentIDObj = departmentCmd->ExecuteScalar();
        if (departmentIDObj == nullptr)
        {
            MessageBox::Show("Invalid department name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            db->CloseConnection();
            return;
        }

        int departmentID = Convert::ToInt32(departmentIDObj);

        // Insert into Faculty table
        String^ insertFacultyQuery = R"(
        INSERT INTO Faculty (UserID, DepartmentID, DateOfAppointment, FacultyID)
        VALUES (@UserID, @DepartmentID, @DateOfAppointment, @FacultyID);
        )";

        MySqlCommand^ cmdInsertFaculty = gcnew MySqlCommand(insertFacultyQuery, db->GetConnection());
        cmdInsertFaculty->Parameters->AddWithValue("@UserID", userID);
        cmdInsertFaculty->Parameters->AddWithValue("@DepartmentID", departmentID);
        cmdInsertFaculty->Parameters->AddWithValue("@DateOfAppointment", dateTimePicker1->Value.ToString("yyyy-MM-dd"));
        cmdInsertFaculty->Parameters->AddWithValue("@FacultyID", textBox5->Text);

        int rowsAffected = cmdInsertFaculty->ExecuteNonQuery();
        if (rowsAffected > 0)
        {
            MessageBox::Show("Faculty record created successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else
        {
            MessageBox::Show("Failed to add faculty to the Faculty table.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        db->CloseConnection();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error creating faculty: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
    }
	finally
	{
        LoadFaculty(db);
		db->CloseConnection();
	}
}

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyManagementForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();
    try
    {
        LoadFaculty(db);
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error loading faculty records: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
	finally
	{
		db->CloseConnection();
	}

    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyManagementForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
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
            UserType = 'Faculty';
    )";

        // Create a MySQL command using the query and the database connection
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());

        // Execute the query and get the results in a data reader
        MySqlDataReader^ reader = cmd->ExecuteReader();

        // Clear any existing rows and columns in the DataGridView
        dataGridViewFaculty->Rows->Clear();
        dataGridViewFaculty->Columns->Clear();

        // Add the columns to the DataGridView (match the SQL query)
        dataGridViewFaculty->Columns->Add("UserID", "User ID");
        dataGridViewFaculty->Columns->Add("FirstName", "First Name");
        dataGridViewFaculty->Columns->Add("LastName", "Last Name");
        dataGridViewFaculty->Columns->Add("Email", "Email");
        dataGridViewFaculty->Columns->Add("UserType", "User Type");

        // Iterate through the result set and populate the DataGridView
        while (reader->Read())
        {
            dataGridViewFaculty->Rows->Add(
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
	finally
	{
		db->CloseConnection();
	}

    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyManagementForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Delete faculty record
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        db->ConnectToDatabase();

        // Retrieve selected row data
        if (dataGridViewFaculty->SelectedRows->Count == 0)
        {
            MessageBox::Show("Please select a faculty to delete.", "No Selection", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        DataGridViewRow^ selectedRow = dataGridViewFaculty->SelectedRows[0];
        int userID = Convert::ToInt32(selectedRow->Cells["UserID"]->Value);

        // SQL query to delete from the Faculty table
        String^ deleteFacultyQuery = R"(
        UPDATE Faculty
        SET IsDeleted = 1
        WHERE UserID = @UserID;
        )";

        // Create and execute MySQL command for Faculty table
        MySqlCommand^ deleteFacultyCmd = gcnew MySqlCommand(deleteFacultyQuery, db->GetConnection());
        deleteFacultyCmd->Parameters->AddWithValue("@UserID", userID);

        int facultyRowsAffected = deleteFacultyCmd->ExecuteNonQuery();

        // If faculty record was deleted, proceed to delete from Users table
        if (facultyRowsAffected > 0)
        {
            // SQL query to delete from the Users table
            String^ deleteUserQuery = R"(
            UPDATE Users
            SET IsDeleted = 1
            WHERE UserID = @UserID;
            )";

            // Create and execute MySQL command for Users table
            MySqlCommand^ deleteUserCmd = gcnew MySqlCommand(deleteUserQuery, db->GetConnection());
            deleteUserCmd->Parameters->AddWithValue("@UserID", userID);

            int userRowsAffected = deleteUserCmd->ExecuteNonQuery();

            if (userRowsAffected > 0)
            {
                MessageBox::Show("Faculty deleted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                button1_Click(sender, e); // Refresh the DataGridView
            }
            else
            {
                MessageBox::Show("Failed to delete the user from the Users table.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        else
        {
            MessageBox::Show("Failed to delete the faculty from the Faculty table.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        db->CloseConnection();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error deleting faculty: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
    }
	finally
	{
		db->CloseConnection();
	}
}
System::Void AshesiUniversityStudentRecordManagementSystem::FacultyManagementForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        // Ensure all necessary fields are filled before updating
        if (String::IsNullOrWhiteSpace(textBox1->Text) ||
            String::IsNullOrWhiteSpace(textBox2->Text) ||
            String::IsNullOrWhiteSpace(textBox4->Text) ||
            String::IsNullOrWhiteSpace(textBox5->Text))
        {
            MessageBox::Show("Please fill in all required fields.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Retrieve updated data from the form
        String^ facultyID = textBox5->Text;

        String^ firstName = textBox1->Text;
        String^ lastName = textBox2->Text;
        String^ email = textBox4->Text;
        String^ dateOfAppointment = dateTimePicker1->Value.ToString("yyyy-MM-dd");
        String^ departmentName = textBox3->Text;

        db->ConnectToDatabase();

        // Get the DepartmentID from the department name
        String^ getDepartmentIDQuery = R"(
        SELECT DepartmentID FROM Departments
        WHERE DepartmentName = @DepartmentName;
        )";

        MySqlCommand^ departmentCmd = gcnew MySqlCommand(getDepartmentIDQuery, db->GetConnection());
        departmentCmd->Parameters->AddWithValue("@DepartmentName", departmentName);

        Object^ departmentIDObj = departmentCmd->ExecuteScalar();
        if (departmentIDObj == nullptr)
        {
            MessageBox::Show("Invalid department name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            db->CloseConnection();
            return;
        }

        int departmentID = (int)departmentIDObj;

        // Update the Users table
        String^ updateUserQuery = R"(
        UPDATE Users
        SET
            FirstName = @FirstName,
            LastName = @LastName,
            Email = @Email
        WHERE
            UserID = (
                SELECT UserID FROM Faculty WHERE FacultyID = @FacultyID AND IsDeleted = 0
            );
        )";

        MySqlCommand^ updateUserCmd = gcnew MySqlCommand(updateUserQuery, db->GetConnection());
        updateUserCmd->Parameters->AddWithValue("@FirstName", firstName);
        updateUserCmd->Parameters->AddWithValue("@LastName", lastName);
        updateUserCmd->Parameters->AddWithValue("@Email", email);
        updateUserCmd->Parameters->AddWithValue("@FacultyID", facultyID);

        int rowsAffectedUsers = updateUserCmd->ExecuteNonQuery();

        // Update the Faculty table
        String^ updateFacultyQuery = R"(
        UPDATE Faculty
        SET
            DepartmentID = @DepartmentID,
            DateOfAppointment = @DateOfAppointment
        WHERE
            FacultyID = @FacultyID AND IsDeleted = 0;
        )";

        MySqlCommand^ updateFacultyCmd = gcnew MySqlCommand(updateFacultyQuery, db->GetConnection());
        updateFacultyCmd->Parameters->AddWithValue("@DepartmentID", departmentID);
        updateFacultyCmd->Parameters->AddWithValue("@DateOfAppointment", dateOfAppointment);
        updateFacultyCmd->Parameters->AddWithValue("@FacultyID", facultyID);

        int rowsAffectedFaculty = updateFacultyCmd->ExecuteNonQuery();

        // Check the results of the updates
        if (rowsAffectedUsers > 0 && rowsAffectedFaculty > 0)
        {
            MessageBox::Show("Faculty record updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            button1_Click(sender, e); // Refresh the DataGridView
        }
        else if (rowsAffectedUsers == 0)
        {
            MessageBox::Show("No changes were made to the Users table.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
        else if (rowsAffectedFaculty == 0)
        {
            MessageBox::Show("No changes were made to the Faculty table.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }

        db->CloseConnection();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error updating faculty: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
    }
	finally
	{
		db->CloseConnection();
	}
}

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyManagementForm::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    // Ensure the user has selected a row (row index should be >= 0)
    if (e->RowIndex >= 0)
    {
        // Get the selected row from the DataGridView
        DataGridViewRow^ selectedRow = dataGridViewFaculty->Rows[e->RowIndex];

        // Check if the columns are present and fill the corresponding TextBoxes with values
        if (selectedRow->Cells["FacultyID"] != nullptr)
            textBox5->Text = selectedRow->Cells["FacultyID"]->Value->ToString();

        if (selectedRow->Cells["FirstName"] != nullptr)
            textBox1->Text = selectedRow->Cells["FirstName"]->Value->ToString();

        if (selectedRow->Cells["LastName"] != nullptr)
            textBox2->Text = selectedRow->Cells["LastName"]->Value->ToString();

        if (selectedRow->Cells["Email"] != nullptr)
            textBox4->Text = selectedRow->Cells["Email"]->Value->ToString();

        if (selectedRow->Cells["DateOfAppointment"] != nullptr)
        {
            // Assuming the value from the DataGridView cell is a DateTime
            String^ dateOfAppointmentString = selectedRow->Cells["DateOfAppointment"]->Value->ToString();
            dateTimePicker1->Value = System::DateTime::Parse(dateOfAppointmentString);  // Assuming a different DateTimePicker (dateTimePicker2) for Date of Appointment
        }

        try
        {
            db->ConnectToDatabase();

            String^ query = R"(
    SELECT DepartmentName FROM Departments
    WHERE DepartmentID = @DepartmentID;
    )";

            // Get the DepartmentID from the selected row
            String^ departmentID = selectedRow->Cells["DepartmentID"]->Value->ToString();

            // Create MySQL command and add the parameter
            MySqlCommand^ sqlCmd = gcnew MySqlCommand(query, db->GetConnection());
            sqlCmd->Parameters->AddWithValue("@DepartmentID", departmentID);

            // Execute the query and get the result
            MySqlDataReader^ reader = sqlCmd->ExecuteReader();

            // Check if the query returned any result
            if (reader->Read())
            {
                // Get the DepartmentName from the reader
                String^ departmentName = reader["DepartmentName"]->ToString();

                // Display the department name in textBox3
                textBox3->Text = departmentName;
            }

            reader->Close();
            db->CloseConnection();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error retrieving department name: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
		finally
		{
			db->CloseConnection();
		}
    }

    return;  // Return void, not System::Void()
}

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyManagementForm::LoadFaculty(DatabaseManager^ db)
{
    db->ConnectToDatabase();

    // SQL query to retrieve user and faculty details by joining Users and Faculty tables
    String^ query = R"(
        SELECT
            Users.UserID,
            Users.FirstName,
            Users.LastName,
            Users.Email,
            Users.UserType,
            Faculty.FacultyID,
            Faculty.DepartmentID,
            Faculty.DateOfAppointment
        FROM
            Faculty
        INNER JOIN
            Users ON Faculty.UserID = Users.UserID
        WHERE Users.IsDeleted = 0;
        )";

    // Create a MySQL command using the query and the database connection
    MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());

    // Execute the query and get the results in a data reader
    MySqlDataReader^ reader = cmd->ExecuteReader();

    // Clear any existing rows and columns in the DataGridView
    dataGridViewFaculty->Rows->Clear();
    dataGridViewFaculty->Columns->Clear();

    // Add the columns to the DataGridView (match the SQL query)
    dataGridViewFaculty->Columns->Add("UserID", "User ID");
    dataGridViewFaculty->Columns->Add("FirstName", "First Name");
    dataGridViewFaculty->Columns->Add("LastName", "Last Name");
    dataGridViewFaculty->Columns->Add("Email", "Email");
    dataGridViewFaculty->Columns->Add("UserType", "User Type");
    dataGridViewFaculty->Columns->Add("FacultyID", "Faculty ID");
    dataGridViewFaculty->Columns->Add("DepartmentID", "Department ID");
    dataGridViewFaculty->Columns->Add("DateOfAppointment", "Date of Appointment");

    // Iterate through the result set and populate the DataGridView
    while (reader->Read())
    {
        dataGridViewFaculty->Rows->Add(
            reader["UserID"]->ToString(),
            reader["FirstName"]->ToString(),
            reader["LastName"]->ToString(),
            reader["Email"]->ToString(),
            reader["UserType"]->ToString(),
            reader["FacultyID"]->ToString(),
            reader["DepartmentID"]->ToString(),
            reader["DateOfAppointment"]->ToString()
        );
    }

    reader->Close();
    db->CloseConnection();
}


