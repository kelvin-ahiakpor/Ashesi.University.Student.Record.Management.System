#pragma once
#include "StudentDashboardForm.h"
#include "FacultyDashboardForm.h"
#include "AdminDashboardForm.h"

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainMenuForm
	/// </summary>
	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
		MainMenuForm(void)
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
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblWelcome;
	protected:

	protected:
	private: System::Windows::Forms::Button^ btnStudentDashboard;
	private: System::Windows::Forms::Button^ btnFacultyDashboard;
	private: System::Windows::Forms::Button^ btnAdminDashboard;


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
			this->btnStudentDashboard = (gcnew System::Windows::Forms::Button());
			this->btnFacultyDashboard = (gcnew System::Windows::Forms::Button());
			this->btnAdminDashboard = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Location = System::Drawing::Point(436, 118);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(224, 25);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Welcome <UserType>";
			// 
			// btnStudentDashboard
			// 
			this->btnStudentDashboard->Location = System::Drawing::Point(218, 411);
			this->btnStudentDashboard->Name = L"btnStudentDashboard";
			this->btnStudentDashboard->Size = System::Drawing::Size(164, 49);
			this->btnStudentDashboard->TabIndex = 1;
			this->btnStudentDashboard->Text = L"STUDENTS";
			this->btnStudentDashboard->UseVisualStyleBackColor = true;
			this->btnStudentDashboard->Click += gcnew System::EventHandler(this, &MainMenuForm::btnStudentDashboard_Click);
			// 
			// btnFacultyDashboard
			// 
			this->btnFacultyDashboard->Location = System::Drawing::Point(475, 411);
			this->btnFacultyDashboard->Name = L"btnFacultyDashboard";
			this->btnFacultyDashboard->Size = System::Drawing::Size(164, 49);
			this->btnFacultyDashboard->TabIndex = 2;
			this->btnFacultyDashboard->Text = L"FACULTY";
			this->btnFacultyDashboard->UseVisualStyleBackColor = true;
			this->btnFacultyDashboard->Click += gcnew System::EventHandler(this, &MainMenuForm::btnFacultyDashboard_Click);
			// 
			// btnAdminDashboard
			// 
			this->btnAdminDashboard->Location = System::Drawing::Point(723, 411);
			this->btnAdminDashboard->Name = L"btnAdminDashboard";
			this->btnAdminDashboard->Size = System::Drawing::Size(164, 49);
			this->btnAdminDashboard->TabIndex = 3;
			this->btnAdminDashboard->Text = L"ADMIN";
			this->btnAdminDashboard->UseVisualStyleBackColor = true;
			this->btnAdminDashboard->Click += gcnew System::EventHandler(this, &MainMenuForm::btnAdminDashboard_Click);
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1142, 654);
			this->Controls->Add(this->btnAdminDashboard);
			this->Controls->Add(this->btnFacultyDashboard);
			this->Controls->Add(this->btnStudentDashboard);
			this->Controls->Add(this->lblWelcome);
			this->Name = L"MainMenuForm";
			this->Text = L"MainMenuForm";
			this->Load += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnStudentDashboard_Click(System::Object^ sender, System::EventArgs^ e) {
		StudentDashboardForm^ studentForm = gcnew StudentDashboardForm();
		this->Hide();
		studentForm->ShowDialog();
		this->Show();  // Re-show MainMenuForm after closing StudentDashboardForm

	}
private: System::Void btnFacultyDashboard_Click(System::Object^ sender, System::EventArgs^ e) {
	FacultyDashboardForm^ facultyForm = gcnew FacultyDashboardForm();
	this->Hide();
	facultyForm->ShowDialog();
	this->Show();
}
private: System::Void btnAdminDashboard_Click(System::Object^ sender, System::EventArgs^ e) {
	AdminDashboardForm^ adminForm = gcnew AdminDashboardForm();
	this->Hide();
	adminForm->ShowDialog();
	this->Show();
}
private: System::Void MainMenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
