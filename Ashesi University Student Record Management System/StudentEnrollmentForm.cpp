#include "StudentEnrollmentForm.h"
#include "DatabaseManager.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

System::Void AshesiUniversityStudentRecordManagementSystem::StudentEnrollmentForm::SearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();
    try
    {
        db->ConnectToDatabase();

        // Get user input
        String^ courseName = textBox1->Text;
        int currentYear = DateTime::Now.Year; // Get the current year 

        // Clear the DataGridView
        dataGridView1->Rows->Clear();
        dataGridView1->Columns->Clear();

        // Define SQL query to fetch course offerings
        String^ query = R"(
            SELECT c.CourseName, c.Credits, c.Prerequisites, c.Description, 
                   o.Year, o.Schedule, o.MaxCapacity, o.Status
            FROM Courses c
            INNER JOIN CourseOfferings o ON c.CourseID = o.CourseID
            WHERE c.CourseName LIKE @CourseName
              AND c.IsActive = 1
              AND o.Status = 'Open'
              AND o.Year = @Year
        )";

        // Prepare the SQL command
        MySqlCommand^ cmd = gcnew MySqlCommand(query, db->GetConnection());
        cmd->Parameters->AddWithValue("@CourseName", "%" + courseName + "%"); // Use LIKE for partial matches
        cmd->Parameters->AddWithValue("@Year", currentYear);

        // Execute the query
        MySqlDataReader^ reader = cmd->ExecuteReader();

        // Set up DataGridView columns
        dataGridView1->Columns->Add("CourseName", "Course Name");
        dataGridView1->Columns->Add("Credits", "Credits");
        dataGridView1->Columns->Add("Prerequisites", "Prerequisites");
        dataGridView1->Columns->Add("Description", "Description");
        dataGridView1->Columns->Add("Year", "Year");
        dataGridView1->Columns->Add("Schedule", "Schedule");
        dataGridView1->Columns->Add("MaxCapacity", "Max Capacity");
        dataGridView1->Columns->Add("Status", "Status");

        // Populate DataGridView rows with query results
        while (reader->Read())
        {
            dataGridView1->Rows->Add(
                reader["CourseName"]->ToString(),
                reader["Credits"]->ToString(),
                reader["Prerequisites"] != DBNull::Value ? reader["Prerequisites"]->ToString() : "None",
                reader["Description"] != DBNull::Value ? reader["Description"]->ToString() : "No description available",
                reader["Year"]->ToString(),
                reader["Schedule"]->ToString(),
                reader["MaxCapacity"]->ToString(),
                reader["Status"]->ToString()
            );
        }

        reader->Close(); // Close the reader
    }
    catch (Exception^ ex)
    {
        MessageBox::Show(
            "Error fetching courses: " + ex->Message,
            "Database Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Error
        );
    }
    finally
    {
        db->CloseConnection(); // Ensure the database connection is closed
    }
}

void AshesiUniversityStudentRecordManagementSystem::StudentEnrollmentForm::dataGridView1_CellClick(
    System::Object^ sender,
    System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dataGridView1->Rows[e->RowIndex];
        textBox2->Text = selectedRow->Cells["CourseName"]->Value != nullptr
            ? selectedRow->Cells["CourseName"]->Value->ToString()
            : "";
        textBox3->Text = selectedRow->Cells["Credits"]->Value != nullptr
            ? selectedRow->Cells["Credits"]->Value->ToString()
            : "";
        richTextBox2->Text = selectedRow->Cells["Prerequisites"]->Value != nullptr
            ? selectedRow->Cells["Prerequisites"]->Value->ToString()
            : "None";
        richTextBox1->Text = selectedRow->Cells["Description"]->Value != nullptr
            ? selectedRow->Cells["Description"]->Value->ToString()
            : "No description available";
        textBox4->Text = selectedRow->Cells["MaxCapacity"]->Value != nullptr
            ? selectedRow->Cells["MaxCapacity"]->Value->ToString()
            : "";
        textBox5->Text = selectedRow->Cells["Status"]->Value != nullptr
            ? selectedRow->Cells["Status"]->Value->ToString()
            : "";
    }
}

