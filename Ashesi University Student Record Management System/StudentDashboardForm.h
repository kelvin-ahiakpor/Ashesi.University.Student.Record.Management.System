#pragma once
#include "StudentEnrollmentForm.h"
#include "GradeManagementForm.h"
#include "TranscriptForm.h"
#include "ProfileManagementForm.h"
#include "ViewGrades.h"
#include "Student.h"

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for StudentDashboardForm
	/// </summary>
	public ref class StudentDashboardForm : public System::Windows::Forms::Form
	{
	public:
		User^ globalUser;
		Student^ student;
		Faculty^ faculty;
		Admin^ admin;
		String^ userRole;

		StudentDashboardForm(void)
		{
			InitializeComponent();
		}

		StudentDashboardForm(User^ user)
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
		~StudentDashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblWelcome;
	protected:
	private: System::Windows::Forms::Button^ btnEnrollInCourse;
	private: System::Windows::Forms::Button^ btnViewGrades;
	private: System::Windows::Forms::Button^ btnViewTranscript;
	private: System::Windows::Forms::Button^ btnManageProfile;

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
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->btnEnrollInCourse = (gcnew System::Windows::Forms::Button());
			this->btnViewGrades = (gcnew System::Windows::Forms::Button());
			this->btnViewTranscript = (gcnew System::Windows::Forms::Button());
			this->btnManageProfile = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Location = System::Drawing::Point(289, 95);
			this->lblWelcome->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(167, 16);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Welcome" + student->getFirstName();
			this->lblWelcome->Click += gcnew System::EventHandler(this, &StudentDashboardForm::lblWelcome_Click);
			// 
			// btnEnrollInCourse
			// 
			this->btnEnrollInCourse->Location = System::Drawing::Point(89, 250);
			this->btnEnrollInCourse->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnEnrollInCourse->Name = L"btnEnrollInCourse";
			this->btnEnrollInCourse->Size = System::Drawing::Size(122, 34);
			this->btnEnrollInCourse->TabIndex = 1;
			this->btnEnrollInCourse->Text = L"Enroll Course";
			this->btnEnrollInCourse->UseVisualStyleBackColor = true;
			this->btnEnrollInCourse->Click += gcnew System::EventHandler(this, &StudentDashboardForm::btnEnrollInCourse_Click);
			// 
			// btnViewGrades
			// 
			this->btnViewGrades->Location = System::Drawing::Point(236, 250);
			this->btnViewGrades->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnViewGrades->Name = L"btnViewGrades";
			this->btnViewGrades->Size = System::Drawing::Size(122, 34);
			this->btnViewGrades->TabIndex = 2;
			this->btnViewGrades->Text = L"View Grades";
			this->btnViewGrades->UseVisualStyleBackColor = true;
			this->btnViewGrades->Click += gcnew System::EventHandler(this, &StudentDashboardForm::btnViewGrades_Click);
			// 
			// btnViewTranscript
			// 
			this->btnViewTranscript->Location = System::Drawing::Point(380, 250);
			this->btnViewTranscript->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnViewTranscript->Name = L"btnViewTranscript";
			this->btnViewTranscript->Size = System::Drawing::Size(122, 34);
			this->btnViewTranscript->TabIndex = 3;
			this->btnViewTranscript->Text = L"View Transcript";
			this->btnViewTranscript->UseVisualStyleBackColor = true;
			this->btnViewTranscript->Click += gcnew System::EventHandler(this, &StudentDashboardForm::btnViewTranscript_Click);
			// 
			// btnManageProfile
			// 
			this->btnManageProfile->Location = System::Drawing::Point(529, 250);
			this->btnManageProfile->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnManageProfile->Name = L"btnManageProfile";
			this->btnManageProfile->Size = System::Drawing::Size(122, 34);
			this->btnManageProfile->TabIndex = 4;
			this->btnManageProfile->Text = L"Manage Profile";
			this->btnManageProfile->UseVisualStyleBackColor = true;
			this->btnManageProfile->Click += gcnew System::EventHandler(this, &StudentDashboardForm::btnManageProfile_Click);
			// 
			// StudentDashboardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 438);
			this->Controls->Add(this->btnManageProfile);
			this->Controls->Add(this->btnViewTranscript);
			this->Controls->Add(this->btnViewGrades);
			this->Controls->Add(this->btnEnrollInCourse);
			this->Controls->Add(this->lblWelcome);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"StudentDashboardForm";
			this->Text = L"StudentDashboardForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnEnrollInCourse_Click(System::Object^ sender, System::EventArgs^ e) {
		StudentEnrollmentForm^ enrollForm = gcnew StudentEnrollmentForm();
		this->Hide();  // Hide the Student Dashboard
		enrollForm->ShowDialog();  // Show the Enrollment Form
		this->Show();  // Re-show the Student Dashboard after closing Enrollment Form
	}
private: System::Void btnViewGrades_Click(System::Object^ sender, System::EventArgs^ e) {
	ViewGrades^ gradeForm = gcnew ViewGrades(student);
	this->Hide();
	gradeForm->ShowDialog();
	this->Show();
}
private: System::Void btnViewTranscript_Click(System::Object^ sender, System::EventArgs^ e) {
	TranscriptForm^ transcriptForm = gcnew TranscriptForm(student);
	this->Hide();
	transcriptForm->ShowDialog();
	this->Show();
}
private: System::Void btnManageProfile_Click(System::Object^ sender, System::EventArgs^ e) {
	ProfileManagementForm^ profileForm = gcnew ProfileManagementForm(student);
	this->Hide();
	profileForm->ShowDialog();
	this->Show();
}
private: System::Void lblWelcome_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
