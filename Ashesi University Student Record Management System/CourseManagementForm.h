#pragma once

namespace AshesiUniversityStudentRecordManagementSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class CourseManagementForm : public System::Windows::Forms::Form
    {
    public:
        Void LoadCourse();
        CourseManagementForm(void)
        {
            InitializeComponent();
            LoadCourse();
        }

    protected:
        ~CourseManagementForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ lblCourseName;
    private: System::Windows::Forms::Label^ lblCredits;
    private: System::Windows::Forms::Label^ lblPrerequisites;
    private: System::Windows::Forms::TextBox^ txtCourseName;
    private: System::Windows::Forms::TextBox^ txtCredits;
    private: System::Windows::Forms::TextBox^ txtPrerequisites;
    private: System::Windows::Forms::Button^ btnSaveCourse;
    private: System::Windows::Forms::Button^ btnDeleteCourse;
    private: System::Windows::Forms::Button^ btnEditCourse;
    private: System::Windows::Forms::DataGridView^ dgvCourses;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::RichTextBox^ richTextBox1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ textBox1;

    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->lblCourseName = (gcnew System::Windows::Forms::Label());
               this->lblCredits = (gcnew System::Windows::Forms::Label());
               this->lblPrerequisites = (gcnew System::Windows::Forms::Label());
               this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
               this->txtCredits = (gcnew System::Windows::Forms::TextBox());
               this->txtPrerequisites = (gcnew System::Windows::Forms::TextBox());
               this->btnSaveCourse = (gcnew System::Windows::Forms::Button());
               this->btnDeleteCourse = (gcnew System::Windows::Forms::Button());
               this->btnEditCourse = (gcnew System::Windows::Forms::Button());
               this->dgvCourses = (gcnew System::Windows::Forms::DataGridView());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->textBox1 = (gcnew System::Windows::Forms::TextBox());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->BeginInit();
               this->SuspendLayout();
               // 
               // lblCourseName
               // 
               this->lblCourseName->AutoSize = true;
               this->lblCourseName->Location = System::Drawing::Point(34, 29);
               this->lblCourseName->Name = L"lblCourseName";
               this->lblCourseName->Size = System::Drawing::Size(90, 16);
               this->lblCourseName->TabIndex = 0;
               this->lblCourseName->Text = L"Course Name";
               // 
               // lblCredits
               // 
               this->lblCredits->AutoSize = true;
               this->lblCredits->Location = System::Drawing::Point(34, 225);
               this->lblCredits->Name = L"lblCredits";
               this->lblCredits->Size = System::Drawing::Size(49, 16);
               this->lblCredits->TabIndex = 1;
               this->lblCredits->Text = L"Credits";
               // 
               // lblPrerequisites
               // 
               this->lblPrerequisites->AutoSize = true;
               this->lblPrerequisites->Location = System::Drawing::Point(34, 268);
               this->lblPrerequisites->Name = L"lblPrerequisites";
               this->lblPrerequisites->Size = System::Drawing::Size(86, 16);
               this->lblPrerequisites->TabIndex = 2;
               this->lblPrerequisites->Text = L"Prerequisites";
               // 
               // txtCourseName
               // 
               this->txtCourseName->Location = System::Drawing::Point(37, 47);
               this->txtCourseName->Name = L"txtCourseName";
               this->txtCourseName->Size = System::Drawing::Size(239, 22);
               this->txtCourseName->TabIndex = 3;
               // 
               // txtCredits
               // 
               this->txtCredits->Location = System::Drawing::Point(37, 243);
               this->txtCredits->Name = L"txtCredits";
               this->txtCredits->Size = System::Drawing::Size(239, 22);
               this->txtCredits->TabIndex = 4;
               // 
               // txtPrerequisites
               // 
               this->txtPrerequisites->Location = System::Drawing::Point(37, 287);
               this->txtPrerequisites->Name = L"txtPrerequisites";
               this->txtPrerequisites->Size = System::Drawing::Size(239, 22);
               this->txtPrerequisites->TabIndex = 5;
               // 
               // btnSaveCourse
               // 
               this->btnSaveCourse->Location = System::Drawing::Point(293, 336);
               this->btnSaveCourse->Name = L"btnSaveCourse";
               this->btnSaveCourse->Size = System::Drawing::Size(111, 27);
               this->btnSaveCourse->TabIndex = 6;
               this->btnSaveCourse->Text = L"Save Course";
               this->btnSaveCourse->UseVisualStyleBackColor = true;
               this->btnSaveCourse->Click += gcnew System::EventHandler(this, &CourseManagementForm::btnSaveCourse_Click);
               // 
               // btnDeleteCourse
               // 
               this->btnDeleteCourse->Location = System::Drawing::Point(551, 336);
               this->btnDeleteCourse->Name = L"btnDeleteCourse";
               this->btnDeleteCourse->Size = System::Drawing::Size(111, 27);
               this->btnDeleteCourse->TabIndex = 7;
               this->btnDeleteCourse->Text = L"Delete Course";
               this->btnDeleteCourse->UseVisualStyleBackColor = true;
               this->btnDeleteCourse->Click += gcnew System::EventHandler(this, &CourseManagementForm::btnDeleteCourse_Click);
               // 
               // btnEditCourse
               // 
               this->btnEditCourse->Location = System::Drawing::Point(420, 336);
               this->btnEditCourse->Name = L"btnEditCourse";
               this->btnEditCourse->Size = System::Drawing::Size(111, 27);
               this->btnEditCourse->TabIndex = 8;
               this->btnEditCourse->Text = L"Edit Course";
               this->btnEditCourse->UseVisualStyleBackColor = true;
               this->btnEditCourse->Click += gcnew System::EventHandler(this, &CourseManagementForm::btnEditCourse_Click);
               // 
               // dgvCourses
               // 
               this->dgvCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dgvCourses->Location = System::Drawing::Point(293, 47);
               this->dgvCourses->Name = L"dgvCourses";
               this->dgvCourses->RowHeadersWidth = 51;
               this->dgvCourses->Size = System::Drawing::Size(519, 283);
               this->dgvCourses->TabIndex = 9;
               this->dgvCourses->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CourseManagementForm::dgvCourses_CellClick);
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
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Location = System::Drawing::Point(34, 322);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(117, 16);
               this->label2->TabIndex = 12;
               this->label2->Text = L"Department Name";
               // 
               // textBox1
               // 
               this->textBox1->Location = System::Drawing::Point(37, 341);
               this->textBox1->Name = L"textBox1";
               this->textBox1->Size = System::Drawing::Size(239, 22);
               this->textBox1->TabIndex = 13;
               // 
               // CourseManagementForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(834, 373);
               this->Controls->Add(this->textBox1);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->richTextBox1);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->dgvCourses);
               this->Controls->Add(this->btnEditCourse);
               this->Controls->Add(this->btnDeleteCourse);
               this->Controls->Add(this->btnSaveCourse);
               this->Controls->Add(this->txtPrerequisites);
               this->Controls->Add(this->txtCredits);
               this->Controls->Add(this->txtCourseName);
               this->Controls->Add(this->lblPrerequisites);
               this->Controls->Add(this->lblCredits);
               this->Controls->Add(this->lblCourseName);
               this->Name = L"CourseManagementForm";
               this->Text = L"Course Management";
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
           private: System::Void btnSaveCourse_Click(System::Object^ sender, System::EventArgs^ e);
           private: System::Void btnDeleteCourse_Click(System::Object^ sender, System::EventArgs^ e);
           private: System::Void btnEditCourse_Click(System::Object^ sender, System::EventArgs^ e);
           private: System::Void dgvCourses_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
                  
#pragma endregion
};
}
