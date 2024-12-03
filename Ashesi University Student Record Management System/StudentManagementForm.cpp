#include "StudentManagementForm.h"
#include "PasswordManager.h"
#include "DatabaseManager.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::btnCreateStudent_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
	{
		CreateStudents(db, sender, e);
        
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error creating student: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
    }
	finally {
        LoadStudents(db);
		db->CloseConnection();
	}
}


//View all students
System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();
    
    try
    {
        LoadStudents(db);
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error loading users: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
	finally {
		db->CloseConnection();
	}
    return System::Void();
}

//Delete student
System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Delete student record
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
		DeleteStudent(db, sender, e);
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error deleting student: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
    }
	finally {
		db->CloseConnection();
	}
}

//Edit Student
System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::btnEdit_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
		EditStudent(db, sender, e);
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error updating student: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        db->CloseConnection();
    }
	finally {
		db->CloseConnection();
	}
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
            dateTimePicker3->Value = System::DateTime::Parse(graduationDateString);
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
		finally
		{
			db->CloseConnection();
		}
    }

    return;  // Return void, not System::Void()
}

//Helper methods for Student Management
//To ensure clean manageable code
System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::LoadStudents(DatabaseManager^ db)
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
            Users ON Students.UserID = Users.UserID
        WHERE Users.IsDeleted = 0;
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

System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::CreateStudents(DatabaseManager^ db, Object^ sender, EventArgs^ e)
{
    // Validate input fields
    if (String::IsNullOrWhiteSpace(textBox1->Text) || String::IsNullOrWhiteSpace(textBox2->Text) ||
        String::IsNullOrWhiteSpace(textBox4->Text) || String::IsNullOrWhiteSpace(textBox3->Text))
    {
        MessageBox::Show("Please fill in all required fields.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    db->ConnectToDatabase();

    String^ hashedPassword = PasswordManager::HashPassword("password123");

    // Insert into Users table
    String^ insertUserQuery = R"(
        INSERT INTO Users (FirstName, LastName, Email, Password, UserType)
        VALUES (@FirstName, @LastName, @Email, @HashedPassword, 'Student');
        SELECT LAST_INSERT_ID();
        )";

    MySqlCommand^ cmdInsertUser = gcnew MySqlCommand(insertUserQuery, db->GetConnection());
    cmdInsertUser->Parameters->AddWithValue("@FirstName", textBox1->Text);
    cmdInsertUser->Parameters->AddWithValue("@LastName", textBox2->Text);
    cmdInsertUser->Parameters->AddWithValue("@Email", textBox4->Text);
    cmdInsertUser->Parameters->AddWithValue("@HashedPassword", hashedPassword);

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

    // Insert into Students table
    String^ insertStudentQuery = R"(
        INSERT INTO Students (UserID, DateOfBirth, DepartmentID, EnrollmentDate, ExpectedGraduation)
        VALUES (@UserID, @DateOfBirth, @DepartmentID, @EnrollmentDate, @ExpectedGraduation);
        )";

    MySqlCommand^ cmdInsertStudent = gcnew MySqlCommand(insertStudentQuery, db->GetConnection());
    cmdInsertStudent->Parameters->AddWithValue("@UserID", userID);
    cmdInsertStudent->Parameters->AddWithValue("@DateOfBirth", dateTimePicker1->Value.ToString("yyyy-MM-dd"));
    cmdInsertStudent->Parameters->AddWithValue("@DepartmentID", departmentID);
    cmdInsertStudent->Parameters->AddWithValue("@EnrollmentDate", dateTimePicker2->Value.ToString("yyyy-MM-dd"));
    cmdInsertStudent->Parameters->AddWithValue("@ExpectedGraduation", dateTimePicker3->Value.ToString("yyyy-MM-dd"));

    int rowsAffected = cmdInsertStudent->ExecuteNonQuery();
    if (rowsAffected > 0)
    {
        MessageBox::Show("Student record created successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else
    {
        MessageBox::Show("Failed to add student to the Students table.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    db->CloseConnection();
}

System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::EditStudent(DatabaseManager^ db, Object^ sender, EventArgs^ e)
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
    int^ studentID = Convert::ToInt32(textBox5->Text);

    String^ firstName = textBox1->Text;
    String^ lastName = textBox2->Text;
    String^ email = textBox4->Text;
    String^ dateOfBirth = dateTimePicker1->Value.ToString("yyyy-MM-dd");
    String^ enrollmentDate = dateTimePicker2->Value.ToString("yyyy-MM-dd");
    String^ expectedGraduation = dateTimePicker3->Value.ToString("yyyy-MM-dd");
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

    int^ departmentID = (int)departmentIDObj;

    // Update the Users table
    String^ updateUserQuery = R"(
        UPDATE Users
        SET
            FirstName = @FirstName,
            LastName = @LastName,
            Email = @Email
        WHERE
            UserID = (
                SELECT UserID FROM Students WHERE StudentID = @StudentID
            );
        )";

    MySqlCommand^ updateUserCmd = gcnew MySqlCommand(updateUserQuery, db->GetConnection());
    updateUserCmd->Parameters->AddWithValue("@FirstName", firstName);
    updateUserCmd->Parameters->AddWithValue("@LastName", lastName);
    updateUserCmd->Parameters->AddWithValue("@Email", email);
    updateUserCmd->Parameters->AddWithValue("@StudentID", studentID);

    int rowsAffectedUsers = updateUserCmd->ExecuteNonQuery();

    // Update the Students table
    String^ updateStudentQuery = R"(
        UPDATE Students
        SET
            DateOfBirth = @DateOfBirth,
            DepartmentID = @DepartmentID,
            EnrollmentDate = @EnrollmentDate,
            ExpectedGraduation = @ExpectedGraduation
        WHERE
            StudentID = @StudentID;
        )";

    MySqlCommand^ updateStudentCmd = gcnew MySqlCommand(updateStudentQuery, db->GetConnection());
    updateStudentCmd->Parameters->AddWithValue("@DateOfBirth", dateOfBirth);
    updateStudentCmd->Parameters->AddWithValue("@DepartmentID", departmentID);
    updateStudentCmd->Parameters->AddWithValue("@EnrollmentDate", enrollmentDate);
    updateStudentCmd->Parameters->AddWithValue("@ExpectedGraduation", expectedGraduation);
    updateStudentCmd->Parameters->AddWithValue("@StudentID", studentID);

    int rowsAffectedStudents = updateStudentCmd->ExecuteNonQuery();

    // Check the results of the updates
    if (rowsAffectedUsers > 0 && rowsAffectedStudents > 0)
    {
        MessageBox::Show("Student record updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        LoadStudents(db); // Refresh the DataGridView
    }
    else if (rowsAffectedUsers == 0)
    {
        MessageBox::Show("No changes were made to the Users table.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
    else if (rowsAffectedStudents == 0)
    {
        MessageBox::Show("No changes were made to the Students table.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }

    db->CloseConnection();
}

System::Void AshesiUniversityStudentRecordManagementSystem::StudentManagementForm::DeleteStudent(DatabaseManager^ db, Object^ sender, EventArgs^ e)
{
    db->ConnectToDatabase();

    // Retrieve selected row data
    if (dataGridView1->SelectedRows->Count == 0)
    {
        MessageBox::Show("Please select a student to delete.", "No Selection", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];
    int userID = Convert::ToInt32(selectedRow->Cells["UserID"]->Value);

    // SQL query to delete from the Students table
    String^ deleteStudentQuery = R"(
        UPDATE Students
        SET IsDeleted = 1
        WHERE UserID = @UserID;
        )";

    // Create and execute MySQL command for Students table
    MySqlCommand^ deleteStudentCmd = gcnew MySqlCommand(deleteStudentQuery, db->GetConnection());
    deleteStudentCmd->Parameters->AddWithValue("@UserID", userID);

    int studentRowsAffected = deleteStudentCmd->ExecuteNonQuery();

    // If student record was deleted, proceed to delete from Users table
    if (studentRowsAffected > 0)
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
            MessageBox::Show("Student deleted successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            LoadStudents(db);
        }
        else
        {
            MessageBox::Show("Failed to delete the user from the Users table.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    else
    {
        MessageBox::Show("Failed to delete the student from the Students table.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    db->CloseConnection();
}



