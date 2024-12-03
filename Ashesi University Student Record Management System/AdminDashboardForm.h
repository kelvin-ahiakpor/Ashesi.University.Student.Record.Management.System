#pragma once
#include "AdminDashboardForm.h"
#include "StudentEnrollmentForm.h"
#include "FacultyDashboardForm.h"
#include "CourseManagementForm.h"
#include "TranscriptForm.h"

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminDashboardForm
	/// </summary>
	public ref class AdminDashboardForm : public System::Windows::Forms::Form
	{
	public:
		AdminDashboardForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminDashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblWelcome;
	protected:

	protected:
	private: System::Windows::Forms::Button^ btnManageStudents;
	private: System::Windows::Forms::Button^ btnManageFaculty;
	private: System::Windows::Forms::Button^ btnManageCourses;
	private: System::Windows::Forms::Button^ btnGenerateReports;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminDashboardForm::typeid));
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->btnManageStudents = (gcnew System::Windows::Forms::Button());
			this->btnManageFaculty = (gcnew System::Windows::Forms::Button());
			this->btnManageCourses = (gcnew System::Windows::Forms::Button());
			this->btnGenerateReports = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Location = System::Drawing::Point(208, 69);
			this->lblWelcome->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(127, 13);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Welcome <Admin Name>";
			// 
			// btnManageStudents
			// 
			this->btnManageStudents->Location = System::Drawing::Point(40, 202);
			this->btnManageStudents->Margin = System::Windows::Forms::Padding(2);
			this->btnManageStudents->Name = L"btnManageStudents";
			this->btnManageStudents->Size = System::Drawing::Size(100, 28);
			this->btnManageStudents->TabIndex = 1;
			this->btnManageStudents->Text = L"Manage Students";
			this->btnManageStudents->UseVisualStyleBackColor = true;
			this->btnManageStudents->Click += gcnew System::EventHandler(this, &AdminDashboardForm::btnManageStudents_Click);
			// 
			// btnManageFaculty
			// 
			this->btnManageFaculty->Location = System::Drawing::Point(160, 202);
			this->btnManageFaculty->Margin = System::Windows::Forms::Padding(2);
			this->btnManageFaculty->Name = L"btnManageFaculty";
			this->btnManageFaculty->Size = System::Drawing::Size(100, 28);
			this->btnManageFaculty->TabIndex = 2;
			this->btnManageFaculty->Text = L"Manage Faculty";
			this->btnManageFaculty->UseVisualStyleBackColor = true;
			this->btnManageFaculty->Click += gcnew System::EventHandler(this, &AdminDashboardForm::btnManageFaculty_Click);
			// 
			// btnManageCourses
			// 
			this->btnManageCourses->Location = System::Drawing::Point(280, 202);
			this->btnManageCourses->Margin = System::Windows::Forms::Padding(2);
			this->btnManageCourses->Name = L"btnManageCourses";
			this->btnManageCourses->Size = System::Drawing::Size(100, 28);
			this->btnManageCourses->TabIndex = 3;
			this->btnManageCourses->Text = L"Manage Courses";
			this->btnManageCourses->UseVisualStyleBackColor = true;
			this->btnManageCourses->Click += gcnew System::EventHandler(this, &AdminDashboardForm::btnManageCourses_Click);
			// 
			// btnGenerateReports
			// 
			this->btnGenerateReports->Location = System::Drawing::Point(400, 202);
			this->btnGenerateReports->Margin = System::Windows::Forms::Padding(2);
			this->btnGenerateReports->Name = L"btnGenerateReports";
			this->btnGenerateReports->Size = System::Drawing::Size(100, 28);
			this->btnGenerateReports->TabIndex = 4;
			this->btnGenerateReports->Text = L"Generate Reports";
			this->btnGenerateReports->UseVisualStyleBackColor = true;
			this->btnGenerateReports->Click += gcnew System::EventHandler(this, &AdminDashboardForm::btnGenerateReports_Click);
			// 
			// AdminDashboardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(548, 302);
			this->Controls->Add(this->btnGenerateReports);
			this->Controls->Add(this->btnManageCourses);
			this->Controls->Add(this->btnManageFaculty);
			this->Controls->Add(this->btnManageStudents);
			this->Controls->Add(this->lblWelcome);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AdminDashboardForm";
			this->Text = L"AdminDashboardForm";
			this->Load += gcnew System::EventHandler(this, &AdminDashboardForm::AdminDashboardForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnManageStudents_Click(System::Object^ sender, System::EventArgs^ e) {
		StudentEnrollmentForm^ studentForm = gcnew StudentEnrollmentForm();
		this->Hide();
		studentForm->ShowDialog();
		this->Show();
	}
private: System::Void btnManageFaculty_Click(System::Object^ sender, System::EventArgs^ e) {
	FacultyDashboardForm^ facultyForm = gcnew FacultyDashboardForm();
	this->Hide();
	facultyForm->ShowDialog();
	this->Show();
}
private: System::Void btnManageCourses_Click(System::Object^ sender, System::EventArgs^ e) {
	CourseManagementForm^ courseForm = gcnew CourseManagementForm();
	this->Hide();
	courseForm->ShowDialog();
	this->Show();
}
private: System::Void btnGenerateReports_Click(System::Object^ sender, System::EventArgs^ e) {
	TranscriptForm^ transcriptForm = gcnew TranscriptForm();
	this->Hide();
	transcriptForm->ShowDialog();
	this->Show();
}
private: System::Void AdminDashboardForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
