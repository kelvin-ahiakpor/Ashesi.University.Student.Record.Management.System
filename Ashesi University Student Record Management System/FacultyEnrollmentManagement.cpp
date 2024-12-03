#include "FacultyEnrollmentManagement.h"
#include "DatabaseManager.h"

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyEnrollmentManagement::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
            DatabaseManager^ db = DatabaseManager::GetInstance();

            if (e->RowIndex >= 0)
            {
                DataGridViewRow^ selectedRow = dataGridView1->Rows[e->RowIndex];
                textBox1->Text = selectedRow->Cells["StudentName"]->Value->ToString();
                textBox2->Text = selectedRow->Cells["CourseName"]->Value->ToString();
                textBox5->Text = selectedRow->Cells["DepartmentName"]->Value->ToString();
                textBox4->Text = selectedRow->Cells["Semester"]->Value->ToString();
                String^ enrollString = selectedRow->Cells["EnrollmentDate"]->Value->ToString();
                dateTimePicker3->Value = System::DateTime::Parse(enrollString);

                DatabaseManager^ db = DatabaseManager::GetInstance();

                try {
                    // Connect to the database
                    db->ConnectToDatabase();

                    // SQL query to fetch ENUM values
                    String^ query = R"(
            SELECT COLUMN_TYPE
            FROM INFORMATION_SCHEMA.COLUMNS
            WHERE TABLE_NAME = 'Enrollment '
            AND COLUMN_NAME = 'Status';
        )";

                    MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
                    MySqlDataReader^ reader = cmd->ExecuteReader();

                    if (reader->Read()) {
                        String^ columnType = reader["COLUMN_TYPE"]->ToString(); // e.g., "enum('Active','Graduated','Suspended','Withdrawn')"

                        // Parse the ENUM values using regex
                        System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex("'([^']+)'");
                        System::Text::RegularExpressions::MatchCollection^ matches = regex->Matches(columnType);

                        // Clear existing items in the ComboBox
                        statusBox1->Items->Clear();

                        // Add each value to the ComboBox
                        for each (System::Text::RegularExpressions::Match ^ match in matches) {
                            statusBox1->Items->Add(match->Groups[1]->Value); // Extract and add the value
                        }
                    }

                    reader->Close();
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error fetching status values: " + ex->Message);
                }
                finally {
                    // Close the database connection
                    db->CloseConnection();
                }

            }
    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyEnrollmentManagement::ViewEnroll_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try {
        // Connect to the database
        db->ConnectToDatabase();

        // Check if the database connection is open
        if (db->GetConnection()->State != System::Data::ConnectionState::Open) {
            MessageBox::Show("Database connection failed.");
            return;
        }

        // SQL query to retrieve the necessary details using JOIN
        String^ query = R"(
            SELECT 
                e.EnrollmentID,
                c.CourseName,
                d.DepartmentName,
                c.Credits,
                c.Description,
                c.Prerequisites,
                co.Semester,
                e.EnrollmentDate,
                e.Status
            FROM 
                Enrollments e
            INNER JOIN 
                CourseOfferings co ON e.CourseID = co.CourseID
            INNER JOIN 
                Courses c ON co.CourseID = c.CourseID
            INNER JOIN 
                Departments d ON c.DepartmentID = d.DepartmentID
            INNER JOIN 
                Faculty f ON co.FacultyID = f.FacultyID
            INNER JOIN 
                Students s ON s.StudentID = s.StudentID
            WHERE 
                f.FacultyID = @facultyid;
        )";

        // Execute the query
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@facultyid", faculty->getFacultyID());

        MySqlDataReader^ reader = cmd->ExecuteReader();

        // Check if any data was returned
        if (!reader->HasRows) {
            MessageBox::Show("No enrollments found for the given faculty.");
            return;
        }

        // Prepare the DataGridView (add columns if not already added)
        if (dataGridView1->Columns->Count == 0) {
            dataGridView1->Columns->Add("EnrollmentID", "Enrollment ID");
            dataGridView1->Columns->Add("CourseName", "Course Name");
            dataGridView1->Columns->Add("StudentName", "Student Name");
            dataGridView1->Columns->Add("DepartmentName", "Department Name");
            dataGridView1->Columns->Add("Credits", "Credits");
            dataGridView1->Columns->Add("Description", "Description");
            dataGridView1->Columns->Add("Prerequisites", "Prerequisites");
            dataGridView1->Columns->Add("Semester", "Semester");
            dataGridView1->Columns->Add("EnrollmentDate", "EnrollmentDate");
            dataGridView1->Columns->Add("Status", "Status");
        }

        // Read results and populate the DataGridView
        while (reader->Read()) {
            dataGridView1->Rows->Add(
                reader["EnrollmentID"] != DBNull::Value ? reader["EnrollmentID"]->ToString() : "",
                reader["CourseName"] != DBNull::Value ? reader["CourseName"]->ToString() : "",
                reader["DepartmentName"] != DBNull::Value ? reader["DepartmentName"]->ToString() : "",
                reader["Credits"] != DBNull::Value ? reader["Credits"]->ToString() : "",
                reader["Description"] != DBNull::Value ? reader["Description"]->ToString() : "",
                reader["Prerequisites"] != DBNull::Value ? reader["Prerequisites"]->ToString() : "",
                reader["Semester"] != DBNull::Value ? reader["Semester"]->ToString() : "",
                reader["EnrollmentDate"] != DBNull::Value ? reader["EnrollmentDate"]->ToString() : "",
                reader["Status"] != DBNull::Value ? reader["Status"]->ToString() : ""
            );
        }

        // Close the reader
        reader->Close();

        // Refresh the DataGridView to display the new data
        dataGridView1->Refresh();
    }
    catch (Exception^ ex) {
        MessageBox::Show("An error occurred while fetching enrollment data: " + ex->Message);
    }
    finally {
        // Disconnect from the database
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

    try {
        // Connect to the database
        db->ConnectToDatabase();

        // Check if the database connection is open
        if (db->GetConnection()->State != System::Data::ConnectionState::Open) {
            MessageBox::Show("Database connection failed.");
            return;
        }

        // Validate that a row is selected in the DataGridView
        if (dataGridView1->SelectedRows->Count == 0) {
            MessageBox::Show("Please select a record to update.");
            return;
        }

        // Get the selected row and EnrollmentID
        DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];
        String^ enrollmentID = selectedRow->Cells["EnrollmentID"]->Value->ToString();

        // Get the new status from the ComboBox
        if (String::IsNullOrEmpty(statusBox1->Text)) {
            MessageBox::Show("Please select a valid status.");
            return;
        }
        String^ newStatus = statusBox1->Text;

        // SQL query to update the status
        String^ query = "UPDATE Enrollments SET Status = @newStatus WHERE EnrollmentID = @enrollmentID;";

        // Execute the query
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@newStatus", newStatus);
        cmd->Parameters->AddWithValue("@enrollmentID", enrollmentID);

        int rowsAffected = cmd->ExecuteNonQuery();

        if (rowsAffected > 0) {
            MessageBox::Show("Status updated successfully.");
        }
        else {
            MessageBox::Show("Failed to update status. Please try again.");
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("An error occurred while updating the status: " + ex->Message);
    }
    finally {
        // Disconnect from the database
        db->CloseConnection();
    }
}
