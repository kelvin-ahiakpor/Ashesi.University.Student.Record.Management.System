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
private: System::Windows::Forms::Label^ lblProfile;
private: System::Windows::Forms::PictureBox^ pboxLogo;
public:

public:
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
        System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CourseMaterialManagement::typeid));
        this->treeViewMaterials = (gcnew System::Windows::Forms::TreeView());
        this->panelMaterialDetails = (gcnew System::Windows::Forms::Panel());
        this->pboxLogo = (gcnew System::Windows::Forms::PictureBox());
        this->lblProfile = (gcnew System::Windows::Forms::Label());
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
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboxLogo))->BeginInit();
        this->SuspendLayout();
        // 
        // treeViewMaterials
        // 
        this->treeViewMaterials->Location = System::Drawing::Point(12, 11);
        this->treeViewMaterials->Margin = System::Windows::Forms::Padding(2);
        this->treeViewMaterials->Name = L"treeViewMaterials";
        this->treeViewMaterials->Size = System::Drawing::Size(233, 345);
        this->treeViewMaterials->TabIndex = 0;
        this->treeViewMaterials->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &CourseMaterialManagement::treeViewMaterials_AfterSelect);
        // 
        // panelMaterialDetails
        // 
        this->panelMaterialDetails->Controls->Add(this->pboxLogo);
        this->panelMaterialDetails->Controls->Add(this->lblProfile);
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
        this->panelMaterialDetails->Location = System::Drawing::Point(249, 11);
        this->panelMaterialDetails->Margin = System::Windows::Forms::Padding(2);
        this->panelMaterialDetails->Name = L"panelMaterialDetails";
        this->panelMaterialDetails->Size = System::Drawing::Size(390, 345);
        this->panelMaterialDetails->TabIndex = 1;
        // 
        // pboxLogo
        // 
        this->pboxLogo->BackColor = System::Drawing::Color::Transparent;
        this->pboxLogo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboxLogo.BackgroundImage")));
        this->pboxLogo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
        this->pboxLogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboxLogo.Image")));
        this->pboxLogo->Location = System::Drawing::Point(329, 20);
        this->pboxLogo->Name = L"pboxLogo";
        this->pboxLogo->Size = System::Drawing::Size(30, 30);
        this->pboxLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
        this->pboxLogo->TabIndex = 16;
        this->pboxLogo->TabStop = false;
        // 
        // lblProfile
        // 
        this->lblProfile->AutoSize = true;
        this->lblProfile->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->lblProfile->Location = System::Drawing::Point(91, 20);
        this->lblProfile->Name = L"lblProfile";
        this->lblProfile->Size = System::Drawing::Size(186, 23);
        this->lblProfile->TabIndex = 15;
        this->lblProfile->Text = L"COURSE MATERIALS";
        // 
        // lblType
        // 
        this->lblType->Location = System::Drawing::Point(16, 87);
        this->lblType->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
        this->lblType->Name = L"lblType";
        this->lblType->Size = System::Drawing::Size(75, 16);
        this->lblType->TabIndex = 2;
        this->lblType->Text = L"Material Type";
        // 
        // comboMaterialType
        // 
        this->comboMaterialType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->comboMaterialType->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Video", L"Assignment", L"Reading", L"" });
        this->comboMaterialType->Location = System::Drawing::Point(95, 82);
        this->comboMaterialType->Margin = System::Windows::Forms::Padding(2);
        this->comboMaterialType->Name = L"comboMaterialType";
        this->comboMaterialType->Size = System::Drawing::Size(264, 21);
        this->comboMaterialType->TabIndex = 7;
        // 
        // lblTitle
        // 
        this->lblTitle->Location = System::Drawing::Point(16, 127);
        this->lblTitle->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
        this->lblTitle->Name = L"lblTitle";
        this->lblTitle->Size = System::Drawing::Size(32, 16);
        this->lblTitle->TabIndex = 3;
        this->lblTitle->Text = L"Title";
        // 
        // txtBookTitle
        // 
        this->txtBookTitle->Location = System::Drawing::Point(95, 123);
        this->txtBookTitle->Margin = System::Windows::Forms::Padding(2);
        this->txtBookTitle->Name = L"txtBookTitle";
        this->txtBookTitle->Size = System::Drawing::Size(264, 20);
        this->txtBookTitle->TabIndex = 8;
        // 
        // lblISBN
        // 
        this->lblISBN->Location = System::Drawing::Point(16, 163);
        this->lblISBN->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
        this->lblISBN->Name = L"lblISBN";
        this->lblISBN->Size = System::Drawing::Size(72, 16);
        this->lblISBN->TabIndex = 5;
        this->lblISBN->Text = L"Material Link";
        this->lblISBN->TextAlign = System::Drawing::ContentAlignment::TopCenter;
        // 
        // txtmaterialLink
        // 
        this->txtmaterialLink->Location = System::Drawing::Point(95, 160);
        this->txtmaterialLink->Margin = System::Windows::Forms::Padding(2);
        this->txtmaterialLink->Name = L"txtmaterialLink";
        this->txtmaterialLink->Size = System::Drawing::Size(264, 20);
        this->txtmaterialLink->TabIndex = 10;
        // 
        // lblDescription
        // 
        this->lblDescription->Location = System::Drawing::Point(16, 201);
        this->lblDescription->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
        this->lblDescription->Name = L"lblDescription";
        this->lblDescription->Size = System::Drawing::Size(75, 16);
        this->lblDescription->TabIndex = 6;
        this->lblDescription->Text = L"Description";
        // 
        // txtDescription
        // 
        this->txtDescription->Location = System::Drawing::Point(95, 198);
        this->txtDescription->Margin = System::Windows::Forms::Padding(2);
        this->txtDescription->Name = L"txtDescription";
        this->txtDescription->Size = System::Drawing::Size(264, 82);
        this->txtDescription->TabIndex = 11;
        this->txtDescription->Text = L"";
        // 
        // btnAddMaterial
        // 
        this->btnAddMaterial->Location = System::Drawing::Point(95, 306);
        this->btnAddMaterial->Margin = System::Windows::Forms::Padding(2);
        this->btnAddMaterial->Name = L"btnAddMaterial";
        this->btnAddMaterial->Size = System::Drawing::Size(75, 24);
        this->btnAddMaterial->TabIndex = 12;
        this->btnAddMaterial->Text = L"Add Material";
        this->btnAddMaterial->UseVisualStyleBackColor = true;
        this->btnAddMaterial->Click += gcnew System::EventHandler(this, &CourseMaterialManagement::btnAddMaterial_Click);
        // 
        // btnUpdateMaterial
        // 
        this->btnUpdateMaterial->Location = System::Drawing::Point(177, 306);
        this->btnUpdateMaterial->Margin = System::Windows::Forms::Padding(2);
        this->btnUpdateMaterial->Name = L"btnUpdateMaterial";
        this->btnUpdateMaterial->Size = System::Drawing::Size(75, 24);
        this->btnUpdateMaterial->TabIndex = 13;
        this->btnUpdateMaterial->Text = L"Update";
        this->btnUpdateMaterial->UseVisualStyleBackColor = true;
        this->btnUpdateMaterial->Click += gcnew System::EventHandler(this, &CourseMaterialManagement::btnUpdateMaterial_Click);
        // 
        // btnDeleteMaterial
        // 
        this->btnDeleteMaterial->Location = System::Drawing::Point(260, 306);
        this->btnDeleteMaterial->Margin = System::Windows::Forms::Padding(2);
        this->btnDeleteMaterial->Name = L"btnDeleteMaterial";
        this->btnDeleteMaterial->Size = System::Drawing::Size(75, 24);
        this->btnDeleteMaterial->TabIndex = 14;
        this->btnDeleteMaterial->Text = L"Delete";
        this->btnDeleteMaterial->UseVisualStyleBackColor = true;
        this->btnDeleteMaterial->Click += gcnew System::EventHandler(this, &CourseMaterialManagement::btnDeleteMaterial_Click);
        // 
        // CourseMaterialManagement
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Linen;
        this->ClientSize = System::Drawing::Size(649, 370);
        this->Controls->Add(this->treeViewMaterials);
        this->Controls->Add(this->panelMaterialDetails);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
        this->Margin = System::Windows::Forms::Padding(2);
        this->MaximizeBox = false;
        this->MinimizeBox = false;
        this->MinimumSize = System::Drawing::Size(649, 370);
        this->Name = L"CourseMaterialManagement";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"Manage Course Materials";
        this->panelMaterialDetails->ResumeLayout(false);
        this->panelMaterialDetails->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboxLogo))->EndInit();
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

