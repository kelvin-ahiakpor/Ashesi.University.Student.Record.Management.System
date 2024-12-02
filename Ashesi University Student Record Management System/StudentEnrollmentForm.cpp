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
                   o.Year, o.Schedule, o.MaxCapacity, o.Status, o.OfferingID
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
        dataGridView1->Columns->Add("OfferingID", "OfferingID");
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
                reader["OfferingID"]->ToString(),
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

System::Void AshesiUniversityStudentRecordManagementSystem::StudentEnrollmentForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    DatabaseManager^ db = DatabaseManager::GetInstance();

    try
    {
        // Additional null check for StudentID
        if (StudentID == nullptr)
        {
            MessageBox::Show("Student ID is not set. Please log in again.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        db->ConnectToDatabase();

        // Validate inputs
        if (String::IsNullOrWhiteSpace(textBox2->Text) ||
            String::IsNullOrWhiteSpace(textBox4->Text) ||
            dataGridView1->SelectedRows->Count == 0)
        {
            MessageBox::Show("Please select a course offering to enroll in.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        // Convert OfferingID to int
        int offeringID;
        if (!Int32::TryParse(
            dataGridView1->SelectedRows[0]->Cells["OfferingID"]->Value->ToString(),
            offeringID))
        {
            MessageBox::Show("Invalid Course Offering ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        String^ enrollmentDate = DateTime::Now.ToString("yyyy-MM-dd");
        double defaultGradePoints = 0.0;

        // Check for duplicate enrollment
        String^ checkQuery = R"(
            SELECT COUNT(*) AS Count 
            FROM Enrollments 
            WHERE StudentID = @StudentID AND OfferingID = @OfferingID
        )";

        MySqlCommand^ checkCmd = gcnew MySqlCommand(checkQuery, db->GetConnection());
        checkCmd->Parameters->AddWithValue("@StudentID", StudentID);
        checkCmd->Parameters->AddWithValue("@OfferingID", offeringID);

        Object^ countResult = checkCmd->ExecuteScalar();
        int enrollmentCount = countResult != nullptr ? Convert::ToInt32(countResult) : 0;

        if (enrollmentCount > 0)
        {
            MessageBox::Show("You are already enrolled in this course offering.", "Enrollment Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
            return;
        }

        // Insert the enrollment record
        String^ insertQuery = R"(
    INSERT INTO Enrollments (StudentID, OfferingID, EnrollmentDate,GradePoints)
    VALUES (@StudentID, @OfferingID, @EnrollmentDate, @GradePoints)
)";

        MySqlCommand^ insertCmd = gcnew MySqlCommand(insertQuery, db->GetConnection());
        insertCmd->Parameters->AddWithValue("@StudentID", StudentID);
        insertCmd->Parameters->AddWithValue("@OfferingID", offeringID);
        insertCmd->Parameters->AddWithValue("@EnrollmentDate", enrollmentDate);
        insertCmd->Parameters->AddWithValue("@GradePoints", defaultGradePoints);

        int rowsAffected = insertCmd->ExecuteNonQuery();
        if (rowsAffected > 0)
        {
            MessageBox::Show("Enrollment successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else
        {
            MessageBox::Show("Enrollment failed. No rows were affected.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (MySqlException^ ex)
    {
        // More specific MySQL error handling
        MessageBox::Show(
            "MySQL Error [" + ex->Number + "]: " + ex->Message,
            "Database Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Error
        );
    }
    catch (Exception^ ex)
    {
        MessageBox::Show(
            "Unexpected error enrolling in course: " + ex->Message,
            "Error",
            MessageBoxButtons::OK,
            MessageBoxIcon::Error
        );
    }
    finally
    {
        db->CloseConnection(); // Ensure the database connection is closed
    }
}
