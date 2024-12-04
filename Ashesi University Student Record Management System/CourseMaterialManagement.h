#pragma once
#include "Faculty.h"
#include "User.h"

namespace AshesiUniversityStudentRecordManagementSystem {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;
using namespace MySql::Data::MySqlClient;

public ref class CourseMaterialManagement : public System::Windows::Forms::Form {
public:

    User^ globalUser;
    Faculty^ faculty;
    String^ userRole;

    CourseMaterialManagement(void)
    {
        InitializeComponent();
        LoadMaterialsData();
    }

    CourseMaterialManagement(User^ user)
    {
        if (Faculty^ f = dynamic_cast<Faculty^>(user)) {
            this->faculty = f;
            this->globalUser = f;  // Assigning user to globalUser
            userRole = "Faculty";
        }
        else {
            throw gcnew System::ArgumentException("Unsupported user type.");
        }

        InitializeComponent();
        LoadMaterialsData();
    }

protected:
    ~CourseMaterialManagement()
    {
        if (components)
        {
            delete components;
        }
    }

private:
    System::Windows::Forms::TreeView^ treeViewMaterials;
    System::Windows::Forms::Panel^ panelMaterialDetails;
    System::Windows::Forms::TextBox^ txtBookTitle;
private: System::Windows::Forms::TextBox^ txtmaterialLink;


    System::Windows::Forms::RichTextBox^ txtDescription;
    System::Windows::Forms::Button^ btnAddMaterial;
    System::Windows::Forms::Button^ btnUpdateMaterial;
    System::Windows::Forms::Button^ btnDeleteMaterial;
    System::Windows::Forms::ComboBox^ comboMaterialType;

    System::Windows::Forms::Label^ lblTitle;

    System::Windows::Forms::Label^ lblISBN;
    System::Windows::Forms::Label^ lblDescription;
    System::Windows::Forms::Label^ lblType;
    System::ComponentModel::Container^ components;

    void InitializeComponent(void)
    {
        this->treeViewMaterials = (gcnew System::Windows::Forms::TreeView());
        this->panelMaterialDetails = (gcnew System::Windows::Forms::Panel());
        this->lblType = (gcnew System::Windows::Forms::Label());
        this->comboMaterialType = (gcnew System::Windows::Forms::ComboBox());
        this->lblTitle = (gcnew System::Windows::Forms::Label());
        this->txtBookTitle = (gcnew System::Windows::Forms::TextBox());
        this->lblISBN = (gcnew System::Windows::Forms::Label());
        this->txtmaterialLink = (gcnew System::Windows::Forms::TextBox());
        this->lblDescription = (gcnew System::Windows::Forms::Label());
        this->txtDescription = (gcnew System::Windows::Forms::RichTextBox());
        this->btnAddMaterial = (gcnew System::Windows::Forms::Button());
        this->btnUpdateMaterial = (gcnew System::Windows::Forms::Button());
        this->btnDeleteMaterial = (gcnew System::Windows::Forms::Button());
        this->panelMaterialDetails->SuspendLayout();
        this->SuspendLayout();
        // 
        // treeViewMaterials
        // 
        this->treeViewMaterials->Location = System::Drawing::Point(12, 12);
        this->treeViewMaterials->Name = L"treeViewMaterials";
        this->treeViewMaterials->Size = System::Drawing::Size(309, 497);
        this->treeViewMaterials->TabIndex = 0;
        this->treeViewMaterials->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &CourseMaterialManagement::treeViewMaterials_AfterSelect);
        // 
        // panelMaterialDetails
        // 
        this->panelMaterialDetails->Controls->Add(this->lblType);
        this->panelMaterialDetails->Controls->Add(this->comboMaterialType);
        this->panelMaterialDetails->Controls->Add(this->lblTitle);
        this->panelMaterialDetails->Controls->Add(this->txtBookTitle);
        this->panelMaterialDetails->Controls->Add(this->lblISBN);
        this->panelMaterialDetails->Controls->Add(this->txtmaterialLink);
        this->panelMaterialDetails->Controls->Add(this->lblDescription);
        this->panelMaterialDetails->Controls->Add(this->txtDescription);
        this->panelMaterialDetails->Controls->Add(this->btnAddMaterial);
        this->panelMaterialDetails->Controls->Add(this->btnUpdateMaterial);
        this->panelMaterialDetails->Controls->Add(this->btnDeleteMaterial);
        this->panelMaterialDetails->Location = System::Drawing::Point(324, 12);
        this->panelMaterialDetails->Name = L"panelMaterialDetails";
        this->panelMaterialDetails->Size = System::Drawing::Size(509, 497);
        this->panelMaterialDetails->TabIndex = 1;
        // 
        // lblType
        // 
        this->lblType->Location = System::Drawing::Point(10, 20);
        this->lblType->Name = L"lblType";
        this->lblType->Size = System::Drawing::Size(100, 20);
        this->lblType->TabIndex = 2;
        this->lblType->Text = L"Material Type:";
        // 
        // comboMaterialType
        // 
        this->comboMaterialType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->comboMaterialType->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Video", L"Assignment", L"Reading", L"" });
        this->comboMaterialType->Location = System::Drawing::Point(120, 20);
        this->comboMaterialType->Name = L"comboMaterialType";
        this->comboMaterialType->Size = System::Drawing::Size(200, 24);
        this->comboMaterialType->TabIndex = 7;
        // 
        // lblTitle
        // 
        this->lblTitle->Location = System::Drawing::Point(10, 70);
        this->lblTitle->Name = L"lblTitle";
        this->lblTitle->Size = System::Drawing::Size(100, 20);
        this->lblTitle->TabIndex = 3;
        this->lblTitle->Text = L"Title:";
        // 
        // txtBookTitle
        // 
        this->txtBookTitle->Location = System::Drawing::Point(120, 70);
        this->txtBookTitle->Name = L"txtBookTitle";
        this->txtBookTitle->Size = System::Drawing::Size(350, 22);
        this->txtBookTitle->TabIndex = 8;
        // 
        // lblISBN
        // 
        this->lblISBN->Location = System::Drawing::Point(3, 119);
        this->lblISBN->Name = L"lblISBN";
        this->lblISBN->Size = System::Drawing::Size(100, 20);
        this->lblISBN->TabIndex = 5;
        this->lblISBN->Text = L"Material Link";
        this->lblISBN->TextAlign = System::Drawing::ContentAlignment::TopCenter;
        // 
        // txtmaterialLink
        // 
        this->txtmaterialLink->Location = System::Drawing::Point(120, 116);
        this->txtmaterialLink->Name = L"txtmaterialLink";
        this->txtmaterialLink->Size = System::Drawing::Size(200, 22);
        this->txtmaterialLink->TabIndex = 10;
        // 
        // lblDescription
        // 
        this->lblDescription->Location = System::Drawing::Point(10, 166);
        this->lblDescription->Name = L"lblDescription";
        this->lblDescription->Size = System::Drawing::Size(100, 20);
        this->lblDescription->TabIndex = 6;
        this->lblDescription->Text = L"Description:";
        // 
        // txtDescription
        // 
        this->txtDescription->Location = System::Drawing::Point(120, 163);
        this->txtDescription->Name = L"txtDescription";
        this->txtDescription->Size = System::Drawing::Size(350, 100);
        this->txtDescription->TabIndex = 11;
        this->txtDescription->Text = L"";
        // 
        // btnAddMaterial
        // 
        this->btnAddMaterial->Location = System::Drawing::Point(120, 292);
        this->btnAddMaterial->Name = L"btnAddMaterial";
        this->btnAddMaterial->Size = System::Drawing::Size(100, 30);
        this->btnAddMaterial->TabIndex = 12;
        this->btnAddMaterial->Text = L"Add Material";
        this->btnAddMaterial->UseVisualStyleBackColor = true;
        this->btnAddMaterial->Click += gcnew System::EventHandler(this, &CourseMaterialManagement::btnAddMaterial_Click);
        // 
        // btnUpdateMaterial
        // 
        this->btnUpdateMaterial->Location = System::Drawing::Point(230, 292);
        this->btnUpdateMaterial->Name = L"btnUpdateMaterial";
        this->btnUpdateMaterial->Size = System::Drawing::Size(100, 30);
        this->btnUpdateMaterial->TabIndex = 13;
        this->btnUpdateMaterial->Text = L"Update";
        this->btnUpdateMaterial->UseVisualStyleBackColor = true;
        this->btnUpdateMaterial->Click += gcnew System::EventHandler(this, &CourseMaterialManagement::btnUpdateMaterial_Click);
        // 
        // btnDeleteMaterial
        // 
        this->btnDeleteMaterial->Location = System::Drawing::Point(340, 292);
        this->btnDeleteMaterial->Name = L"btnDeleteMaterial";
        this->btnDeleteMaterial->Size = System::Drawing::Size(100, 30);
        this->btnDeleteMaterial->TabIndex = 14;
        this->btnDeleteMaterial->Text = L"Delete";
        this->btnDeleteMaterial->UseVisualStyleBackColor = true;
        this->btnDeleteMaterial->Click += gcnew System::EventHandler(this, &CourseMaterialManagement::btnDeleteMaterial_Click);
        // 
        // CourseMaterialManagement
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(844, 521);
        this->Controls->Add(this->treeViewMaterials);
        this->Controls->Add(this->panelMaterialDetails);
        this->MaximizeBox = false;
        this->MinimizeBox = false;
        this->MinimumSize = System::Drawing::Size(860, 568);
        this->Name = L"CourseMaterialManagement";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"Manage Course Materials";
        this->panelMaterialDetails->ResumeLayout(false);
        this->panelMaterialDetails->PerformLayout();
        this->ResumeLayout(false);

    }

    void LoadMaterialsData(void);

    void ClearForm(void);

    System::Void treeViewMaterials_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e);

    System::Void btnAddMaterial_Click(System::Object^ sender, System::EventArgs^ e);

    System::Void btnDeleteMaterial_Click(System::Object^ sender, System::EventArgs^ e);

private:
       TreeNode^ AshesiUniversityStudentRecordManagementSystem::CourseMaterialManagement::GetOrCreateNode(TreeNodeCollection^ nodes, String^ nodeName)
{
    for each (TreeNode ^ node in nodes) {
        if (node->Text == nodeName) {
            return node;
        }
    }
    return nodes->Add(nodeName);
}


private: System::Void btnUpdateMaterial_Click(System::Object^ sender, System::EventArgs^ e);
};
}

