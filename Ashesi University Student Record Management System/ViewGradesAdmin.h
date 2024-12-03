#pragma once

namespace AshesiUniversityStudentRecordManagementSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class ViewGradesAdmin : public System::Windows::Forms::Form
    {
    public:
        ViewGradesAdmin(void)
        {
            InitializeComponent();
        }

    protected:
        ~ViewGradesAdmin()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::RichTextBox^ richTxtGrades;
        System::Windows::Forms::Button^ btnSearch;
        System::Windows::Forms::Button^ btnViewGrades;
        System::Windows::Forms::MaskedTextBox^ txtFirstName;
        System::Windows::Forms::MaskedTextBox^ txtLastName;
        System::Windows::Forms::Label^ lblFirstName;
        System::Windows::Forms::Label^ lblLastName;
        System::Windows::Forms::DataGridView^ dgvStudentList;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ViewGradesAdmin::typeid));
            this->richTxtGrades = (gcnew System::Windows::Forms::RichTextBox());
            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->btnViewGrades = (gcnew System::Windows::Forms::Button());
            this->txtFirstName = (gcnew System::Windows::Forms::MaskedTextBox());
            this->txtLastName = (gcnew System::Windows::Forms::MaskedTextBox());
            this->lblFirstName = (gcnew System::Windows::Forms::Label());
            this->lblLastName = (gcnew System::Windows::Forms::Label());
            this->dgvStudentList = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudentList))->BeginInit();
            this->SuspendLayout();
            // 
            // richTxtGrades
            // 
            this->richTxtGrades->Location = System::Drawing::Point(26, 352);
            this->richTxtGrades->Name = L"richTxtGrades";
            this->richTxtGrades->ReadOnly = true;
            this->richTxtGrades->Size = System::Drawing::Size(600, 385);
            this->richTxtGrades->TabIndex = 0;
            this->richTxtGrades->Text = L"";
            this->richTxtGrades->TextChanged += gcnew System::EventHandler(this, &ViewGradesAdmin::richTxtGrades_TextChanged);
            // 
            // btnSearch
            // 
            this->btnSearch->Location = System::Drawing::Point(526, 26);
            this->btnSearch->Name = L"btnSearch";
            this->btnSearch->Size = System::Drawing::Size(100, 30);
            this->btnSearch->TabIndex = 1;
            this->btnSearch->Text = L"Search";
            this->btnSearch->Click += gcnew System::EventHandler(this, &ViewGradesAdmin::btnSearch_Click);
            // 
            // btnViewGrades
            // 
            this->btnViewGrades->Location = System::Drawing::Point(476, 303);
            this->btnViewGrades->Name = L"btnViewGrades";
            this->btnViewGrades->Size = System::Drawing::Size(150, 30);
            this->btnViewGrades->TabIndex = 2;
            this->btnViewGrades->Text = L"View Grades";
            this->btnViewGrades->Click += gcnew System::EventHandler(this, &ViewGradesAdmin::btnViewGrades_Click);
            // 
            // txtFirstName
            // 
            this->txtFirstName->Location = System::Drawing::Point(50, 30);
            this->txtFirstName->Name = L"txtFirstName";
            this->txtFirstName->Size = System::Drawing::Size(150, 20);
            this->txtFirstName->TabIndex = 3;
            // 
            // txtLastName
            // 
            this->txtLastName->Location = System::Drawing::Point(250, 30);
            this->txtLastName->Name = L"txtLastName";
            this->txtLastName->Size = System::Drawing::Size(150, 20);
            this->txtLastName->TabIndex = 4;
            // 
            // lblFirstName
            // 
            this->lblFirstName->Location = System::Drawing::Point(50, 10);
            this->lblFirstName->Name = L"lblFirstName";
            this->lblFirstName->Size = System::Drawing::Size(100, 23);
            this->lblFirstName->TabIndex = 5;
            this->lblFirstName->Text = L"First Name";
            // 
            // lblLastName
            // 
            this->lblLastName->Location = System::Drawing::Point(250, 10);
            this->lblLastName->Name = L"lblLastName";
            this->lblLastName->Size = System::Drawing::Size(100, 23);
            this->lblLastName->TabIndex = 6;
            this->lblLastName->Text = L"Last Name";
            // 
            // dgvStudentList
            // 
            this->dgvStudentList->ColumnHeadersHeight = 29;
            this->dgvStudentList->Location = System::Drawing::Point(26, 72);
            this->dgvStudentList->Name = L"dgvStudentList";
            this->dgvStudentList->RowHeadersWidth = 51;
            this->dgvStudentList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvStudentList->Size = System::Drawing::Size(600, 200);
            this->dgvStudentList->TabIndex = 7;
            // 
            // ViewGradesAdmin
            // 
            this->ClientSize = System::Drawing::Size(662, 798);
            this->Controls->Add(this->richTxtGrades);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->btnViewGrades);
            this->Controls->Add(this->txtFirstName);
            this->Controls->Add(this->txtLastName);
            this->Controls->Add(this->lblFirstName);
            this->Controls->Add(this->lblLastName);
            this->Controls->Add(this->dgvStudentList);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"ViewGradesAdmin";
            this->Text = L"View Grades Admin";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudentList))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
        System::Void btnViewGrades_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);

    private: System::Void richTxtGrades_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
};
}