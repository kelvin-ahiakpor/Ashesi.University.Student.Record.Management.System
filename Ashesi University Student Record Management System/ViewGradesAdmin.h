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
    private: System::Windows::Forms::GroupBox^ groupBoxSelect;
    private: System::Windows::Forms::GroupBox^ groupBoxView;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ViewGradesAdmin::typeid));
            this->richTxtGrades = (gcnew System::Windows::Forms::RichTextBox());
            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->btnViewGrades = (gcnew System::Windows::Forms::Button());
            this->txtFirstName = (gcnew System::Windows::Forms::MaskedTextBox());
            this->txtLastName = (gcnew System::Windows::Forms::MaskedTextBox());
            this->lblFirstName = (gcnew System::Windows::Forms::Label());
            this->lblLastName = (gcnew System::Windows::Forms::Label());
            this->dgvStudentList = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxSelect = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxView = (gcnew System::Windows::Forms::GroupBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudentList))->BeginInit();
            this->groupBoxSelect->SuspendLayout();
            this->groupBoxView->SuspendLayout();
            this->SuspendLayout();
            // 
            // richTxtGrades
            // 
            this->richTxtGrades->Location = System::Drawing::Point(11, 48);
            this->richTxtGrades->Name = L"richTxtGrades";
            this->richTxtGrades->ReadOnly = true;
            this->richTxtGrades->Size = System::Drawing::Size(594, 360);
            this->richTxtGrades->TabIndex = 0;
            this->richTxtGrades->Text = L"";
            this->richTxtGrades->TextChanged += gcnew System::EventHandler(this, &ViewGradesAdmin::richTxtGrades_TextChanged);
            // 
            // btnSearch
            // 
            this->btnSearch->Location = System::Drawing::Point(532, 18);
            this->btnSearch->Name = L"btnSearch";
            this->btnSearch->Size = System::Drawing::Size(79, 24);
            this->btnSearch->TabIndex = 1;
            this->btnSearch->Text = L"Search";
            this->btnSearch->Click += gcnew System::EventHandler(this, &ViewGradesAdmin::btnSearch_Click);
            // 
            // btnViewGrades
            // 
            this->btnViewGrades->Location = System::Drawing::Point(526, 19);
            this->btnViewGrades->Name = L"btnViewGrades";
            this->btnViewGrades->Size = System::Drawing::Size(79, 23);
            this->btnViewGrades->TabIndex = 2;
            this->btnViewGrades->Text = L"View Grades";
            this->btnViewGrades->Click += gcnew System::EventHandler(this, &ViewGradesAdmin::btnViewGrades_Click);
            // 
            // txtFirstName
            // 
            this->txtFirstName->Location = System::Drawing::Point(75, 21);
            this->txtFirstName->Name = L"txtFirstName";
            this->txtFirstName->Size = System::Drawing::Size(150, 20);
            this->txtFirstName->TabIndex = 3;
            // 
            // txtLastName
            // 
            this->txtLastName->Location = System::Drawing::Point(301, 21);
            this->txtLastName->Name = L"txtLastName";
            this->txtLastName->Size = System::Drawing::Size(150, 20);
            this->txtLastName->TabIndex = 4;
            // 
            // lblFirstName
            // 
            this->lblFirstName->Location = System::Drawing::Point(8, 24);
            this->lblFirstName->Name = L"lblFirstName";
            this->lblFirstName->Size = System::Drawing::Size(61, 17);
            this->lblFirstName->TabIndex = 5;
            this->lblFirstName->Text = L"First Name";
            // 
            // lblLastName
            // 
            this->lblLastName->Location = System::Drawing::Point(235, 25);
            this->lblLastName->Name = L"lblLastName";
            this->lblLastName->Size = System::Drawing::Size(60, 17);
            this->lblLastName->TabIndex = 6;
            this->lblLastName->Text = L"Last Name";
            // 
            // dgvStudentList
            // 
            dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
            dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
            dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::RosyBrown;
            dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
            this->dgvStudentList->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this->dgvStudentList->ColumnHeadersHeight = 29;
            this->dgvStudentList->Location = System::Drawing::Point(11, 58);
            this->dgvStudentList->Name = L"dgvStudentList";
            this->dgvStudentList->RowHeadersWidth = 51;
            this->dgvStudentList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvStudentList->Size = System::Drawing::Size(600, 200);
            this->dgvStudentList->TabIndex = 7;
            // 
            // groupBoxSelect
            // 
            this->groupBoxSelect->Controls->Add(this->txtFirstName);
            this->groupBoxSelect->Controls->Add(this->dgvStudentList);
            this->groupBoxSelect->Controls->Add(this->btnSearch);
            this->groupBoxSelect->Controls->Add(this->lblLastName);
            this->groupBoxSelect->Controls->Add(this->lblFirstName);
            this->groupBoxSelect->Controls->Add(this->txtLastName);
            this->groupBoxSelect->Location = System::Drawing::Point(12, 12);
            this->groupBoxSelect->Name = L"groupBoxSelect";
            this->groupBoxSelect->Size = System::Drawing::Size(611, 266);
            this->groupBoxSelect->TabIndex = 8;
            this->groupBoxSelect->TabStop = false;
            this->groupBoxSelect->Text = L"Select";
            // 
            // groupBoxView
            // 
            this->groupBoxView->Controls->Add(this->btnViewGrades);
            this->groupBoxView->Controls->Add(this->richTxtGrades);
            this->groupBoxView->Location = System::Drawing::Point(12, 285);
            this->groupBoxView->Name = L"groupBoxView";
            this->groupBoxView->Size = System::Drawing::Size(611, 414);
            this->groupBoxView->TabIndex = 9;
            this->groupBoxView->TabStop = false;
            this->groupBoxView->Text = L"View";
            // 
            // ViewGradesAdmin
            // 
            this->ClientSize = System::Drawing::Size(634, 711);
            this->Controls->Add(this->groupBoxSelect);
            this->Controls->Add(this->groupBoxView);
            this->ForeColor = System::Drawing::Color::Maroon;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"ViewGradesAdmin";
            this->Text = L"View Grades";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudentList))->EndInit();
            this->groupBoxSelect->ResumeLayout(false);
            this->groupBoxSelect->PerformLayout();
            this->groupBoxView->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion
        System::Void btnViewGrades_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);

    private: System::Void richTxtGrades_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
};
}