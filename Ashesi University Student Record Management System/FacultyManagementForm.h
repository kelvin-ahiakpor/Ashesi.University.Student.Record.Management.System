#pragma once

namespace AshesiUniversityStudentRecordManagementSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class FacultyManagementForm : public System::Windows::Forms::Form
    {
    public:
        FacultyManagementForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~FacultyManagementForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ lblFacultyName;
    private: System::Windows::Forms::Label^ lblDepartment;
    private: System::Windows::Forms::Label^ lblTitle;
    private: System::Windows::Forms::TextBox^ txtFacultyName;
    private: System::Windows::Forms::TextBox^ txtDepartment;
    private: System::Windows::Forms::TextBox^ txtTitle;
    private: System::Windows::Forms::Button^ btnSaveFaculty;
    private: System::Windows::Forms::Button^ btnDeleteFaculty;
    private: System::Windows::Forms::Button^ btnEditFaculty;
    private: System::Windows::Forms::DataGridView^ dgvFaculty;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::RichTextBox^ richTextBox1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ txtPhoneNumber;

    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->lblFacultyName = (gcnew System::Windows::Forms::Label());
               this->lblDepartment = (gcnew System::Windows::Forms::Label());
               this->lblTitle = (gcnew System::Windows::Forms::Label());
               this->txtFacultyName = (gcnew System::Windows::Forms::TextBox());
               this->txtDepartment = (gcnew System::Windows::Forms::TextBox());
               this->txtTitle = (gcnew System::Windows::Forms::TextBox());
               this->btnSaveFaculty = (gcnew System::Windows::Forms::Button());
               this->btnDeleteFaculty = (gcnew System::Windows::Forms::Button());
               this->btnEditFaculty = (gcnew System::Windows::Forms::Button());
               this->dgvFaculty = (gcnew System::Windows::Forms::DataGridView());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->txtPhoneNumber = (gcnew System::Windows::Forms::TextBox());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFaculty))->BeginInit();
               this->SuspendLayout();
               // 
               // lblFacultyName
               // 
               this->lblFacultyName->AutoSize = true;
               this->lblFacultyName->Location = System::Drawing::Point(34, 29);
               this->lblFacultyName->Name = L"lblFacultyName";
               this->lblFacultyName->Size = System::Drawing::Size(90, 16);
               this->lblFacultyName->TabIndex = 0;
               this->lblFacultyName->Text = L"Faculty Name";
               // 
               // lblDepartment
               // 
               this->lblDepartment->AutoSize = true;
               this->lblDepartment->Location = System::Drawing::Point(34, 225);
               this->lblDepartment->Name = L"lblDepartment";
               this->lblDepartment->Size = System::Drawing::Size(77, 16);
               this->lblDepartment->TabIndex = 1;
               this->lblDepartment->Text = L"Department";
               // 
               // lblTitle
               // 
               this->lblTitle->AutoSize = true;
               this->lblTitle->Location = System::Drawing::Point(34, 268);
               this->lblTitle->Name = L"lblTitle";
               this->lblTitle->Size = System::Drawing::Size(33, 16);
               this->lblTitle->TabIndex = 2;
               this->lblTitle->Text = L"Title";
               // 
               // txtFacultyName
               // 
               this->txtFacultyName->Location = System::Drawing::Point(37, 47);
               this->txtFacultyName->Name = L"txtFacultyName";
               this->txtFacultyName->Size = System::Drawing::Size(239, 22);
               this->txtFacultyName->TabIndex = 3;
               // 
               // txtDepartment
               // 
               this->txtDepartment->Location = System::Drawing::Point(37, 243);
               this->txtDepartment->Name = L"txtDepartment";
               this->txtDepartment->Size = System::Drawing::Size(239, 22);
               this->txtDepartment->TabIndex = 4;
               // 
               // txtTitle
               // 
               this->txtTitle->Location = System::Drawing::Point(37, 287);
               this->txtTitle->Name = L"txtTitle";
               this->txtTitle->Size = System::Drawing::Size(239, 22);
               this->txtTitle->TabIndex = 5;
               // 
               // btnSaveFaculty
               // 
               this->btnSaveFaculty->Location = System::Drawing::Point(293, 336);
               this->btnSaveFaculty->Name = L"btnSaveFaculty";
               this->btnSaveFaculty->Size = System::Drawing::Size(111, 27);
               this->btnSaveFaculty->TabIndex = 6;
               this->btnSaveFaculty->Text = L"Save Faculty";
               this->btnSaveFaculty->UseVisualStyleBackColor = true;
               this->btnSaveFaculty->Click += gcnew System::EventHandler(this, &FacultyManagementForm::btnSaveFaculty_Click);
               // 
               // btnDeleteFaculty
               // 
               this->btnDeleteFaculty->Location = System::Drawing::Point(551, 336);
               this->btnDeleteFaculty->Name = L"btnDeleteFaculty";
               this->btnDeleteFaculty->Size = System::Drawing::Size(111, 27);
               this->btnDeleteFaculty->TabIndex = 7;
               this->btnDeleteFaculty->Text = L"Delete Faculty";
               this->btnDeleteFaculty->UseVisualStyleBackColor = true;
               this->btnDeleteFaculty->Click += gcnew System::EventHandler(this, &FacultyManagementForm::btnDeleteFaculty_Click);
               // 
               // btnEditFaculty
               // 
               this->btnEditFaculty->Location = System::Drawing::Point(420, 336);
               this->btnEditFaculty->Name = L"btnEditFaculty";
               this->btnEditFaculty->Size = System::Drawing::Size(111, 27);
               this->btnEditFaculty->TabIndex = 8;
               this->btnEditFaculty->Text = L"Edit Faculty";
               this->btnEditFaculty->UseVisualStyleBackColor = true;
               this->btnEditFaculty->Click += gcnew System::EventHandler(this, &FacultyManagementForm::btnEditFaculty_Click);
               // 
               // dgvFaculty
               // 
               this->dgvFaculty->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dgvFaculty->Location = System::Drawing::Point(293, 47);
               this->dgvFaculty->Name = L"dgvFaculty";
               this->dgvFaculty->RowHeadersWidth = 51;
               this->dgvFaculty->Size = System::Drawing::Size(519, 283);
               this->dgvFaculty->TabIndex = 9;
               this->dgvFaculty->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FacultyManagementForm::dgvFaculty_CellClick);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Location = System::Drawing::Point(34, 85);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(75, 16);
               this->label1->TabIndex = 10;
               this->label1->Text = L"Description";
               // 
               // richTextBox1
               // 
               this->richTextBox1->Location = System::Drawing::Point(37, 104);
               this->richTextBox1->Name = L"richTextBox1";
               this->richTextBox1->Size = System::Drawing::Size(239, 96);
               this->richTextBox1->TabIndex = 11;
               this->richTextBox1->Text = L"";
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Location = System::Drawing::Point(34, 322);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(97, 16);
               this->label2->TabIndex = 12;
               this->label2->Text = L"Phone Number";
               // 
               // txtPhoneNumber
               // 
               this->txtPhoneNumber->Location = System::Drawing::Point(37, 341);
               this->txtPhoneNumber->Name = L"txtPhoneNumber";
               this->txtPhoneNumber->Size = System::Drawing::Size(239, 22);
               this->txtPhoneNumber->TabIndex = 13;
               // 
               // FacultyManagementForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(835, 392);
               this->Controls->Add(this->txtPhoneNumber);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->richTextBox1);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->dgvFaculty);
               this->Controls->Add(this->btnEditFaculty);
               this->Controls->Add(this->btnDeleteFaculty);
               this->Controls->Add(this->btnSaveFaculty);
               this->Controls->Add(this->txtTitle);
               this->Controls->Add(this->txtDepartment);
               this->Controls->Add(this->txtFacultyName);
               this->Controls->Add(this->lblTitle);
               this->Controls->Add(this->lblDepartment);
               this->Controls->Add(this->lblFacultyName);
               this->Name = L"FacultyManagementForm";
               this->Text = L"FacultyManagementForm";
               this->Load += gcnew System::EventHandler(this, &FacultyManagementForm::FacultyManagementForm_Load);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFaculty))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private: System::Void btnSaveFaculty_Click(System::Object^ sender, System::EventArgs^ e) {
        // Save logic
    }
    private: System::Void btnEditFaculty_Click(System::Object^ sender, System::EventArgs^ e) {
        // Edit logic
    }
    private: System::Void btnDeleteFaculty_Click(System::Object^ sender, System::EventArgs^ e) {
        // Delete logic
    }
    private: System::Void dgvFaculty_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        // Load selected faculty to textboxes
    }
    private: System::Void FacultyManagementForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
