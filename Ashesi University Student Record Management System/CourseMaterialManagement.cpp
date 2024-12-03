#include "CourseMaterialManagement.h"
#include "DatabaseManager.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;

System::Void AshesiUniversityStudentRecordManagementSystem::CourseMaterialManagement::treeViewMaterials_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
    if (e->Node->Parent != nullptr && e->Node->Parent->Parent != nullptr) {
        txtBookTitle->Text = e->Node->Text;
        comboMaterialType->SelectedItem = e->Node->Parent->Text;
    }
    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::CourseMaterialManagement::btnAddMaterial_Click(System::Object^ sender, System::EventArgs^ e)
{
    
    if (String::IsNullOrEmpty(txtBookTitle->Text) || comboMaterialType->SelectedItem == nullptr) {
        MessageBox::Show("Please fill in all required fields.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    DatabaseManager^ db = DatabaseManager::GetInstance();
    try {

        
        db->ConnectToDatabase();

        // Query to fetch CourseID dynamically (you might need additional logic to determine the course)
        String^ fetchCourseQuery = "SELECT CourseID FROM CourseOfferings WHERE FacultyID = @facultyid";
        MySqlCommand^ fetchCommand = gcnew MySqlCommand(fetchCourseQuery, db->GetConnection());
        fetchCommand->Parameters->AddWithValue("@facultyid", faculty->getFacultyID()); 
        Object^ courseIDObj = fetchCommand->ExecuteScalar();

        if (courseIDObj == nullptr) {
            MessageBox::Show("Course not found for the specified faculty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        int courseID = Convert::ToInt32(courseIDObj);

        // Insert query for adding material
        String^ insertQuery = R"(
            INSERT INTO CourseMaterials (CourseID, Type, Title, Description, UploadDate, FilePath, FacultyID) 
            VALUES (@courseID, @type, @title, @description, @uploadDate, @filePath, @facultyid)
        )";

        MySqlCommand^ insertCommand = gcnew MySqlCommand(insertQuery, db->GetConnection());
        insertCommand->Parameters->AddWithValue("@courseID", courseID);
        insertCommand->Parameters->AddWithValue("@type", comboMaterialType->Text);
        insertCommand->Parameters->AddWithValue("@title", txtBookTitle->Text);
        insertCommand->Parameters->AddWithValue("@description", txtDescription->Text);
        insertCommand->Parameters->AddWithValue("@uploadDate", DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss")); // Current date and time
        insertCommand->Parameters->AddWithValue("@filePath", txtmaterialLink->Text);
        insertCommand->Parameters->AddWithValue("@facultyid", faculty->getFacultyID());

        // Execute the insert query
        insertCommand->ExecuteNonQuery();

        MessageBox::Show("Material added successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        //ClearForm();
        db->CloseConnection();
        LoadMaterialsData();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error adding material: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        db->CloseConnection();
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::CourseMaterialManagement::btnDeleteMaterial_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Ensure a material is selected in the tree view
    if (treeViewMaterials->SelectedNode == nullptr ||
        treeViewMaterials->SelectedNode->Parent == nullptr ||
        treeViewMaterials->SelectedNode->Parent->Parent == nullptr)
    {
        MessageBox::Show("Please select a material to delete.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // Confirm deletion
    System::Windows::Forms::DialogResult confirmation = MessageBox::Show(
        "Are you sure you want to delete this material?",
        "Confirm Delete",
        MessageBoxButtons::YesNo,
        MessageBoxIcon::Question
    );

    // Exit early if user cancels
    if (confirmation != System::Windows::Forms::DialogResult::Yes)
    {
        MessageBox::Show("Deletion cancelled.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return;
    }

    try {
        // Retrieve MaterialID from the selected node's Tag
        int materialID = Convert::ToInt32(treeViewMaterials->SelectedNode->Tag);

        // Database interaction
        DatabaseManager^ db = DatabaseManager::GetInstance();
        db->ConnectToDatabase();

        // Delete query
        String^ deleteQuery = "DELETE FROM CourseMaterials WHERE MaterialID = @materialID";
        MySqlCommand^ deleteCommand = gcnew MySqlCommand(deleteQuery, db->GetConnection());
        deleteCommand->Parameters->AddWithValue("@materialID", materialID);

        // Execute delete query
        int rowsAffected = deleteCommand->ExecuteNonQuery();
        db->CloseConnection();

        if (rowsAffected > 0) {
            // Remove node from the tree view
            treeViewMaterials->SelectedNode->Remove();
            MessageBox::Show("Material deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

            // Optionally clear the form
            ClearForm();
        }
        else {
            MessageBox::Show("The material could not be deleted. Please try again.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error deleting material: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}



System::Void AshesiUniversityStudentRecordManagementSystem::CourseMaterialManagement::btnUpdateMaterial_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Ensure a material is selected in the tree view
    if (treeViewMaterials->SelectedNode == nullptr ||
        treeViewMaterials->SelectedNode->Parent == nullptr ||
        treeViewMaterials->SelectedNode->Parent->Parent == nullptr)
    {
        MessageBox::Show("Please select a material to update.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // Retrieve MaterialID from the selected node's Tag
    int materialID = Convert::ToInt32(treeViewMaterials->SelectedNode->Tag);

    // Validate user input fields
    if (String::IsNullOrEmpty(txtBookTitle->Text) || comboMaterialType->SelectedItem == nullptr) {
        MessageBox::Show("Please fill in all required fields.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    DatabaseManager^ db = DatabaseManager::GetInstance();
    try {
        // Connect to the database
        db->ConnectToDatabase();

        // Update query to modify the course material
        String^ updateQuery = R"(
            UPDATE CourseMaterials 
            SET Type = @type, Title = @title, Description = @description, FilePath = @filePath
            WHERE MaterialID = @materialID
        )";

        MySqlCommand^ updateCommand = gcnew MySqlCommand(updateQuery, db->GetConnection());
        updateCommand->Parameters->AddWithValue("@type", comboMaterialType->Text);
        updateCommand->Parameters->AddWithValue("@title", txtBookTitle->Text);
        updateCommand->Parameters->AddWithValue("@description", txtDescription->Text);
        updateCommand->Parameters->AddWithValue("@filePath", txtmaterialLink->Text);
        updateCommand->Parameters->AddWithValue("@materialID", materialID);

        // Execute the update query
        int rowsAffected = updateCommand->ExecuteNonQuery();

        if (rowsAffected > 0) {
            MessageBox::Show("Material updated successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            db->CloseConnection();
            // Reload the materials in the tree view
            LoadMaterialsData();
        }
        else {
            MessageBox::Show("No material was updated. Please check the selected material.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error updating material: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        db->CloseConnection();
    }
}


//Helper functions for course material management
void AshesiUniversityStudentRecordManagementSystem::CourseMaterialManagement::LoadMaterialsData()
{
    try {
        // Clear existing nodes
        this->treeViewMaterials->Nodes->Clear();

        // Initialize database connection and query
        DatabaseManager^ db = DatabaseManager::GetInstance();
        db->ConnectToDatabase();

        // Modified query to join CourseMaterials and Courses tables to get the CourseName
        String^ query = "SELECT cm.MaterialID, cm.CourseID, cm.Type, cm.Title, cm.FilePath, c.CourseName "
            "FROM CourseMaterials cm "
            "INNER JOIN Courses c ON cm.CourseID = c.CourseID "
            "WHERE cm.FacultyID = @facultyId";

        MySqlCommand^ command = gcnew MySqlCommand(query, db->GetConnection());
        command->Parameters->AddWithValue("@facultyId", faculty->getFacultyID()); // Bind parameter

        // Execute the query
        MySqlDataReader^ reader = command->ExecuteReader();

        // Process each row in the result set
        while (reader->Read()) {
            int materialid = reader->GetInt32("MaterialID");
            int courseId = reader->GetInt32("CourseID");
            String^ materialType = reader->GetString("Type");
            String^ materialTitle = reader->GetString("Title");
            String^ materialLink = reader->GetString("FilePath");
            String^ courseName = reader->GetString("CourseName"); // Get CourseName

            // Retrieve or create the course node using CourseName
            TreeNode^ courseNode = GetOrCreateNode(this->treeViewMaterials->Nodes, courseName);

            // Retrieve or create the material type node
            TreeNode^ typeNode = GetOrCreateNode(courseNode->Nodes, materialType);

            // Create the material node with MaterialID stored in the Tag
            String^ materialDisplay = materialTitle + " (" + materialLink + ")";
            TreeNode^ materialNode = gcnew TreeNode(materialDisplay);
            materialNode->Tag = materialid;  // Store MaterialID in the Tag

            // Add the material node to the type node
            typeNode->Nodes->Add(materialNode);
        }

        // Clean up
        reader->Close();
        db->CloseConnection();

        // Optionally expand only top-level nodes (courses)
        for each (TreeNode ^ courseNode in this->treeViewMaterials->Nodes) {
            courseNode->Expand();
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("An error occurred while loading materials:\n" + ex->Message,
            "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

void AshesiUniversityStudentRecordManagementSystem::CourseMaterialManagement::ClearForm(void)
{
    this->txtBookTitle->Clear();
    this->txtBookTitle->Clear();
    this->txtDescription->Clear();
    this->txtmaterialLink->Clear();
    this->comboMaterialType->SelectedIndex = -1;
}
