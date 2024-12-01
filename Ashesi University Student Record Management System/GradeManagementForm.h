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
	/// Summary for GradeManagementForm
	/// </summary>
	public ref class GradeManagementForm : public System::Windows::Forms::Form
	{
	public:
		User^ globalUser;
		Student^ student;
		Admin^ admin;
		Faculty^ faculty;
		String^ userRole;
		GradeManagementForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


		GradeManagementForm(User^ user)
		{
			InitializeComponent(); // Always call this first

			// Perform dynamic casting once and then check the user type
			if (Student^ s = dynamic_cast<Student^>(user)) {
				student = s;
				this->globalUser = s;
				userRole = "Student";
			}
			else if (Faculty^ f = dynamic_cast<Faculty^>(user)) {
				faculty = f;
				userRole = "Faculty";
			}
			else if (Admin^ a = dynamic_cast<Admin^>(user)) {
				admin = a;
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
		~GradeManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblStudentID;
	protected:
	private: System::Windows::Forms::Label^ lblCourses;
	private: System::Windows::Forms::Label^ lblGrade;
	private: System::Windows::Forms::ComboBox^ cboxCourses;
	private: System::Windows::Forms::TextBox^ txtStudentID;
	private: System::Windows::Forms::ComboBox^ cboxGrades;
	private: System::Windows::Forms::Button^ btnSubmitGrade;

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
			this->lblStudentID = (gcnew System::Windows::Forms::Label());
			this->lblCourses = (gcnew System::Windows::Forms::Label());
			this->lblGrade = (gcnew System::Windows::Forms::Label());
			this->cboxCourses = (gcnew System::Windows::Forms::ComboBox());
			this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
			this->cboxGrades = (gcnew System::Windows::Forms::ComboBox());
			this->btnSubmitGrade = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblStudentID
			// 
			this->lblStudentID->AutoSize = true;
			this->lblStudentID->Location = System::Drawing::Point(102, 82);
			this->lblStudentID->Name = L"lblStudentID";
			this->lblStudentID->Size = System::Drawing::Size(112, 25);
			this->lblStudentID->TabIndex = 0;
			this->lblStudentID->Text = L"Student ID";
			// 
			// lblCourses
			// 
			this->lblCourses->AutoSize = true;
			this->lblCourses->Location = System::Drawing::Point(102, 231);
			this->lblCourses->Name = L"lblCourses";
			this->lblCourses->Size = System::Drawing::Size(92, 25);
			this->lblCourses->TabIndex = 1;
			this->lblCourses->Text = L"Courses";
			// 
			// lblGrade
			// 
			this->lblGrade->AutoSize = true;
			this->lblGrade->Location = System::Drawing::Point(102, 361);
			this->lblGrade->Name = L"lblGrade";
			this->lblGrade->Size = System::Drawing::Size(71, 25);
			this->lblGrade->TabIndex = 2;
			this->lblGrade->Text = L"Grade";
			// 
			// cboxCourses
			// 
			this->cboxCourses->FormattingEnabled = true;
			this->cboxCourses->Location = System::Drawing::Point(107, 259);
			this->cboxCourses->Name = L"cboxCourses";
			this->cboxCourses->Size = System::Drawing::Size(451, 33);
			this->cboxCourses->TabIndex = 3;
			// 
			// txtStudentID
			// 
			this->txtStudentID->Location = System::Drawing::Point(107, 110);
			this->txtStudentID->Name = L"txtStudentID";
			this->txtStudentID->Size = System::Drawing::Size(301, 31);
			this->txtStudentID->TabIndex = 5;
			// 
			// cboxGrades
			// 
			this->cboxGrades->FormattingEnabled = true;
			this->cboxGrades->Location = System::Drawing::Point(107, 418);
			this->cboxGrades->Name = L"cboxGrades";
			this->cboxGrades->Size = System::Drawing::Size(451, 33);
			this->cboxGrades->TabIndex = 6;
			// 
			// btnSubmitGrade
			// 
			this->btnSubmitGrade->Location = System::Drawing::Point(107, 556);
			this->btnSubmitGrade->Name = L"btnSubmitGrade";
			this->btnSubmitGrade->Size = System::Drawing::Size(176, 47);
			this->btnSubmitGrade->TabIndex = 7;
			this->btnSubmitGrade->Text = L"Submit Grade";
			this->btnSubmitGrade->UseVisualStyleBackColor = true;
			this->btnSubmitGrade->Click += gcnew System::EventHandler(this, &GradeManagementForm::btnSubmitGrade_Click);
			// 
			// GradeManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(818, 672);
			this->Controls->Add(this->btnSubmitGrade);
			this->Controls->Add(this->cboxGrades);
			this->Controls->Add(this->txtStudentID);
			this->Controls->Add(this->cboxCourses);
			this->Controls->Add(this->lblGrade);
			this->Controls->Add(this->lblCourses);
			this->Controls->Add(this->lblStudentID);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"GradeManagementForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GradeManagementForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSubmitGrade_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Grade submitted successfully.");
	}
};
}
