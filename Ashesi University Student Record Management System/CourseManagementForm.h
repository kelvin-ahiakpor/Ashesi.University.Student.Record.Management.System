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

	/// <summary>
	/// Summary for CourseManagementForm
	/// </summary>
	public ref class CourseManagementForm : public System::Windows::Forms::Form
	{
	public:
		User^ globalUser;
		Student^ student;
		Faculty^ faculty;
		Admin^ admin;
		String^ userRole;

		CourseManagementForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		CourseManagementForm(User^ user)
		{
			InitializeComponent();
			// Perform dynamic casting once and then check the user type
			if (Student^ s = dynamic_cast<Student^>(user)) {
				this->student = s;
				this->globalUser = s;  // Assigning user to globalUser
				userRole = "Student";
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
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CourseManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblCourseName;
	protected:
	private: System::Windows::Forms::Label^ lblCredits;
	private: System::Windows::Forms::Label^ lblPrerequisites;
	private: System::Windows::Forms::TextBox^ txtCourseName;
	private: System::Windows::Forms::TextBox^ txtCredits;
	private: System::Windows::Forms::TextBox^ txtPrerequisites;
	private: System::Windows::Forms::Button^ btnSaveCourse;
	private: System::Windows::Forms::Button^ btnDeleteCourse;
	private: System::Windows::Forms::Button^ btnEditCourse;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
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
			this->SuspendLayout();
			// 
			// lblCourseName
			// 
			this->lblCourseName->AutoSize = true;
			this->lblCourseName->Location = System::Drawing::Point(26, 24);
			this->lblCourseName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblCourseName->Name = L"lblCourseName";
			this->lblCourseName->Size = System::Drawing::Size(71, 13);
			this->lblCourseName->TabIndex = 0;
			this->lblCourseName->Text = L"Course Name";
			// 
			// lblCredits
			// 
			this->lblCredits->AutoSize = true;
			this->lblCredits->Location = System::Drawing::Point(26, 94);
			this->lblCredits->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblCredits->Name = L"lblCredits";
			this->lblCredits->Size = System::Drawing::Size(39, 13);
			this->lblCredits->TabIndex = 1;
			this->lblCredits->Text = L"Credits";
			// 
			// lblPrerequisites
			// 
			this->lblPrerequisites->AutoSize = true;
			this->lblPrerequisites->Location = System::Drawing::Point(26, 148);
			this->lblPrerequisites->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPrerequisites->Name = L"lblPrerequisites";
			this->lblPrerequisites->Size = System::Drawing::Size(67, 13);
			this->lblPrerequisites->TabIndex = 2;
			this->lblPrerequisites->Text = L"Prerequisites";
			// 
			// txtCourseName
			// 
			this->txtCourseName->Location = System::Drawing::Point(28, 38);
			this->txtCourseName->Margin = System::Windows::Forms::Padding(2);
			this->txtCourseName->Name = L"txtCourseName";
			this->txtCourseName->Size = System::Drawing::Size(157, 20);
			this->txtCourseName->TabIndex = 3;
			// 
			// txtCredits
			// 
			this->txtCredits->Location = System::Drawing::Point(28, 109);
			this->txtCredits->Margin = System::Windows::Forms::Padding(2);
			this->txtCredits->Name = L"txtCredits";
			this->txtCredits->Size = System::Drawing::Size(157, 20);
			this->txtCredits->TabIndex = 4;
			// 
			// txtPrerequisites
			// 
			this->txtPrerequisites->Location = System::Drawing::Point(28, 162);
			this->txtPrerequisites->Margin = System::Windows::Forms::Padding(2);
			this->txtPrerequisites->Name = L"txtPrerequisites";
			this->txtPrerequisites->Size = System::Drawing::Size(157, 20);
			this->txtPrerequisites->TabIndex = 5;
			// 
			// btnSaveCourse
			// 
			this->btnSaveCourse->Location = System::Drawing::Point(28, 231);
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
			this->btnDeleteCourse->Location = System::Drawing::Point(392, 275);
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
			this->btnEditCourse->Location = System::Drawing::Point(28, 275);
			this->btnEditCourse->Margin = System::Windows::Forms::Padding(2);
			this->btnEditCourse->Name = L"btnEditCourse";
			this->btnEditCourse->Size = System::Drawing::Size(83, 22);
			this->btnEditCourse->TabIndex = 8;
			this->btnEditCourse->Text = L"Edit Course";
			this->btnEditCourse->UseVisualStyleBackColor = true;
			// 
			// CourseManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(526, 330);
			this->Controls->Add(this->btnEditCourse);
			this->Controls->Add(this->btnDeleteCourse);
			this->Controls->Add(this->btnSaveCourse);
			this->Controls->Add(this->txtPrerequisites);
			this->Controls->Add(this->txtCredits);
			this->Controls->Add(this->txtCourseName);
			this->Controls->Add(this->lblPrerequisites);
			this->Controls->Add(this->lblCredits);
			this->Controls->Add(this->lblCourseName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"CourseManagementForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"CourseManagementForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSaveCourse_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Course saved successfully.");
	}
private: System::Void btnDeleteCourse_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Course deleted successfully.");
}
};
}
