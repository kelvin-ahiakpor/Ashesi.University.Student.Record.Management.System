#include "FacultyEnrollmentManagement.h"
#include "DatabaseManager.h"

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
                c.Prerequisites
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
            dataGridView1->Columns->Add("DepartmentName", "Department Name");
            dataGridView1->Columns->Add("Credits", "Credits");
            dataGridView1->Columns->Add("Description", "Description");
            dataGridView1->Columns->Add("Prerequisites", "Prerequisites");
        }

        // Read results and populate the DataGridView
        while (reader->Read()) {
            dataGridView1->Rows->Add(
                reader["EnrollmentID"] != DBNull::Value ? reader["EnrollmentID"]->ToString() : "",
                reader["CourseName"] != DBNull::Value ? reader["CourseName"]->ToString() : "",
                reader["DepartmentName"] != DBNull::Value ? reader["DepartmentName"]->ToString() : "",
                reader["Credits"] != DBNull::Value ? reader["Credits"]->ToString() : "",
                reader["Description"] != DBNull::Value ? reader["Description"]->ToString() : "",
                reader["Prerequisites"] != DBNull::Value ? reader["Prerequisites"]->ToString() : ""
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

