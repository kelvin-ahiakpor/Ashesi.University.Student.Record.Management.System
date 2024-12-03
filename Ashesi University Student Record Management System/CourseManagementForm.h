#pragma once
#include "User.h"
#include "Student.h"
#include "Faculty.h"
#include "Admin.h"

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
        User^ globalUser;
        Student^ student;
        Faculty^ faculty;
        Admin^ admin;
        String^ userRole;
    private: System::Windows::Forms::GroupBox^ groupBoxCourseActions;
    private: System::Windows::Forms::GroupBox^ groupBoxSelect;
    private: System::Windows::Forms::GroupBox^ groupBoxEdit;
    public:
        int^ studentid;

        Void LoadCourse();
        CourseManagementForm(void)
        {
            InitializeComponent();
            LoadCourse();
        }

        CourseManagementForm(User^ user)
        {
            InitializeComponent();
            LoadCourse();
            // Perform dynamic casting once and then check the user type
            if (Student^ s = dynamic_cast<Student^>(user)) {
                this->student = s;
                this->globalUser = s;  // Assigning user to globalUser
                userRole = "Student";
                studentid = student->getStudentID();
            }
            else if (Faculty^ f = dynamic_cast<Faculty^>(user)) {
                this->faculty = f;
                this->globalUser = f;  // Assigning user to globalUser
                userRole = "Faculty";
            }
            else if (Admin^ a = dynamic_cast<Admin^>(user)) {
                this->admin = a;
                this->globalUser = a;  // Assigning user to globalUser
                userRole = "Administrator";
            }
            else {
                throw gcnew System::ArgumentException("Unsupported user type.");
            }
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
    private: System::Windows::Forms::RichTextBox^ rtboxDescription;

    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ textBox1;

    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CourseManagementForm::typeid));
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
               this->rtboxDescription = (gcnew System::Windows::Forms::RichTextBox());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->textBox1 = (gcnew System::Windows::Forms::TextBox());
               this->groupBoxCourseActions = (gcnew System::Windows::Forms::GroupBox());
               this->groupBoxSelect = (gcnew System::Windows::Forms::GroupBox());
               this->groupBoxEdit = (gcnew System::Windows::Forms::GroupBox());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->BeginInit();
               this->groupBoxCourseActions->SuspendLayout();
               this->groupBoxSelect->SuspendLayout();
               this->groupBoxEdit->SuspendLayout();
               this->SuspendLayout();
               // 
               // lblCourseName
               // 
               this->lblCourseName->AutoSize = true;
               this->lblCourseName->Location = System::Drawing::Point(3, 16);
               this->lblCourseName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->lblCourseName->Name = L"lblCourseName";
               this->lblCourseName->Size = System::Drawing::Size(71, 13);
               this->lblCourseName->TabIndex = 0;
               this->lblCourseName->Text = L"Course Name";
               // 
               // lblCredits
               // 
               this->lblCredits->AutoSize = true;
               this->lblCredits->Location = System::Drawing::Point(5, 151);
               this->lblCredits->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->lblCredits->Name = L"lblCredits";
               this->lblCredits->Size = System::Drawing::Size(39, 13);
               this->lblCredits->TabIndex = 1;
               this->lblCredits->Text = L"Credits";
               // 
               // lblPrerequisites
               // 
               this->lblPrerequisites->AutoSize = true;
               this->lblPrerequisites->Location = System::Drawing::Point(5, 186);
               this->lblPrerequisites->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->lblPrerequisites->Name = L"lblPrerequisites";
               this->lblPrerequisites->Size = System::Drawing::Size(67, 13);
               this->lblPrerequisites->TabIndex = 2;
               this->lblPrerequisites->Text = L"Prerequisites";
               // 
               // txtCourseName
               // 
               this->txtCourseName->Location = System::Drawing::Point(5, 30);
               this->txtCourseName->Margin = System::Windows::Forms::Padding(2);
               this->txtCourseName->Name = L"txtCourseName";
               this->txtCourseName->Size = System::Drawing::Size(180, 20);
               this->txtCourseName->TabIndex = 3;
               // 
               // txtCredits
               // 
               this->txtCredits->Location = System::Drawing::Point(7, 165);
               this->txtCredits->Margin = System::Windows::Forms::Padding(2);
               this->txtCredits->Name = L"txtCredits";
               this->txtCredits->Size = System::Drawing::Size(180, 20);
               this->txtCredits->TabIndex = 4;
               // 
               // txtPrerequisites
               // 
               this->txtPrerequisites->Location = System::Drawing::Point(7, 201);
               this->txtPrerequisites->Margin = System::Windows::Forms::Padding(2);
               this->txtPrerequisites->Name = L"txtPrerequisites";
               this->txtPrerequisites->Size = System::Drawing::Size(180, 20);
               this->txtPrerequisites->TabIndex = 5;
               // 
               // btnSaveCourse
               // 
               this->btnSaveCourse->Location = System::Drawing::Point(510, 9);
               this->btnSaveCourse->Margin = System::Windows::Forms::Padding(2);
               this->btnSaveCourse->Name = L"btnSaveCourse";
               this->btnSaveCourse->Size = System::Drawing::Size(83, 22);
               this->btnSaveCourse->TabIndex = 6;
               this->btnSaveCourse->Text = L"Save Course";
               this->btnSaveCourse->UseVisualStyleBackColor = true;
               this->btnSaveCourse->Click += gcnew System::EventHandler(this, &CourseManagementForm::btnSaveCourse_Click);
               // 
               // btnDeleteCourse
               // 
               this->btnDeleteCourse->Location = System::Drawing::Point(684, 9);
               this->btnDeleteCourse->Margin = System::Windows::Forms::Padding(2);
               this->btnDeleteCourse->Name = L"btnDeleteCourse";
               this->btnDeleteCourse->Size = System::Drawing::Size(83, 22);
               this->btnDeleteCourse->TabIndex = 7;
               this->btnDeleteCourse->Text = L"Delete Course";
               this->btnDeleteCourse->UseVisualStyleBackColor = true;
               this->btnDeleteCourse->Click += gcnew System::EventHandler(this, &CourseManagementForm::btnDeleteCourse_Click);
               // 
               // btnEditCourse
               // 
               this->btnEditCourse->Location = System::Drawing::Point(597, 9);
               this->btnEditCourse->Margin = System::Windows::Forms::Padding(2);
               this->btnEditCourse->Name = L"btnEditCourse";
               this->btnEditCourse->Size = System::Drawing::Size(83, 22);
               this->btnEditCourse->TabIndex = 8;
               this->btnEditCourse->Text = L"Edit Course";
               this->btnEditCourse->UseVisualStyleBackColor = true;
               this->btnEditCourse->Click += gcnew System::EventHandler(this, &CourseManagementForm::btnEditCourse_Click);
               // 
               // dgvCourses
               // 
               this->dgvCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dgvCourses->Location = System::Drawing::Point(5, 12);
               this->dgvCourses->Margin = System::Windows::Forms::Padding(2);
               this->dgvCourses->Name = L"dgvCourses";
               this->dgvCourses->RowHeadersWidth = 51;
               this->dgvCourses->Size = System::Drawing::Size(762, 215);
               this->dgvCourses->TabIndex = 9;
               this->dgvCourses->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CourseManagementForm::dgvCourses_CellClick);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Location = System::Drawing::Point(3, 55);
               this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(60, 13);
               this->label1->TabIndex = 10;
               this->label1->Text = L"Description";
               // 
               // rtboxDescription
               // 
               this->rtboxDescription->Location = System::Drawing::Point(5, 70);
               this->rtboxDescription->Margin = System::Windows::Forms::Padding(2);
               this->rtboxDescription->Name = L"rtboxDescription";
               this->rtboxDescription->Size = System::Drawing::Size(180, 79);
               this->rtboxDescription->TabIndex = 11;
               this->rtboxDescription->Text = L"";
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Location = System::Drawing::Point(5, 230);
               this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(93, 13);
               this->label2->TabIndex = 12;
               this->label2->Text = L"Department Name";
               // 
               // textBox1
               // 
               this->textBox1->Location = System::Drawing::Point(7, 245);
               this->textBox1->Margin = System::Windows::Forms::Padding(2);
               this->textBox1->Name = L"textBox1";
               this->textBox1->Size = System::Drawing::Size(180, 20);
               this->textBox1->TabIndex = 13;
               // 
               // groupBoxCourseActions
               // 
               this->groupBoxCourseActions->Controls->Add(this->btnSaveCourse);
               this->groupBoxCourseActions->Controls->Add(this->btnEditCourse);
               this->groupBoxCourseActions->Controls->Add(this->btnDeleteCourse);
               this->groupBoxCourseActions->Location = System::Drawing::Point(223, 250);
               this->groupBoxCourseActions->Name = L"groupBoxCourseActions";
               this->groupBoxCourseActions->Size = System::Drawing::Size(772, 35);
               this->groupBoxCourseActions->TabIndex = 14;
               this->groupBoxCourseActions->TabStop = false;
               this->groupBoxCourseActions->Text = L"Actions";
               this->groupBoxCourseActions->Enter += gcnew System::EventHandler(this, &CourseManagementForm::groupBoxCourseActions_Enter);
               // 
               // groupBoxSelect
               // 
               this->groupBoxSelect->Controls->Add(this->dgvCourses);
               this->groupBoxSelect->Location = System::Drawing::Point(223, 12);
               this->groupBoxSelect->Name = L"groupBoxSelect";
               this->groupBoxSelect->Size = System::Drawing::Size(772, 232);
               this->groupBoxSelect->TabIndex = 15;
               this->groupBoxSelect->TabStop = false;
               this->groupBoxSelect->Text = L"Select";
               // 
               // groupBoxEdit
               // 
               this->groupBoxEdit->Controls->Add(this->txtCourseName);
               this->groupBoxEdit->Controls->Add(this->lblCourseName);
               this->groupBoxEdit->Controls->Add(this->rtboxDescription);
               this->groupBoxEdit->Controls->Add(this->textBox1);
               this->groupBoxEdit->Controls->Add(this->label1);
               this->groupBoxEdit->Controls->Add(this->label2);
               this->groupBoxEdit->Controls->Add(this->lblCredits);
               this->groupBoxEdit->Controls->Add(this->txtPrerequisites);
               this->groupBoxEdit->Controls->Add(this->lblPrerequisites);
               this->groupBoxEdit->Controls->Add(this->txtCredits);
               this->groupBoxEdit->Location = System::Drawing::Point(17, 12);
               this->groupBoxEdit->Name = L"groupBoxEdit";
               this->groupBoxEdit->Size = System::Drawing::Size(200, 273);
               this->groupBoxEdit->TabIndex = 16;
               this->groupBoxEdit->TabStop = false;
               this->groupBoxEdit->Text = L"Edit";
               // 
               // CourseManagementForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(1007, 301);
               this->Controls->Add(this->groupBoxEdit);
               this->Controls->Add(this->groupBoxSelect);
               this->Controls->Add(this->groupBoxCourseActions);
               this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
               this->Margin = System::Windows::Forms::Padding(2);
               this->Name = L"CourseManagementForm";
               this->Text = L"Course Management";
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->EndInit();
               this->groupBoxCourseActions->ResumeLayout(false);
               this->groupBoxSelect->ResumeLayout(false);
               this->groupBoxEdit->ResumeLayout(false);
               this->groupBoxEdit->PerformLayout();
               this->ResumeLayout(false);

           }
           private: System::Void btnSaveCourse_Click(System::Object^ sender, System::EventArgs^ e);
           private: System::Void btnDeleteCourse_Click(System::Object^ sender, System::EventArgs^ e);
           private: System::Void btnEditCourse_Click(System::Object^ sender, System::EventArgs^ e);
           private: System::Void dgvCourses_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
                  
#pragma endregion
private: System::Void groupBoxCourseActions_Enter(System::Object^ sender, System::EventArgs^ e) {
}
};
}
