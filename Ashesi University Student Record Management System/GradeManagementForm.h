#pragma once
#include "User.h"
#include "Student.h"
#include "Faculty.h"
#include "Admin.h"
#include "DatabaseManager.h"

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
	private: System::Windows::Forms::ComboBox^ cboxCourses;
	private: System::Windows::Forms::ComboBox^ cboxStudentName;
	public:
		Faculty^ faculty;

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

	private: System::Windows::Forms::PictureBox^ pboxLogo;
	public:
	private: System::Windows::Forms::Label^ lblProfile;
	private: System::Windows::Forms::Button^ btnCancel;

		   String^ userRole;
		GradeManagementForm(void)
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GradeManagementForm::typeid));
			this->lblStudentID = (gcnew System::Windows::Forms::Label());
			this->lblCourses = (gcnew System::Windows::Forms::Label());
			this->lblGrade = (gcnew System::Windows::Forms::Label());
			this->cboxGrades = (gcnew System::Windows::Forms::ComboBox());
			this->btnSubmitGrade = (gcnew System::Windows::Forms::Button());
			this->pboxLogo = (gcnew System::Windows::Forms::PictureBox());
			this->lblProfile = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->cboxCourses = (gcnew System::Windows::Forms::ComboBox());
			this->cboxStudentName = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboxLogo))->BeginInit();
			this->SuspendLayout();
			// 
			// lblStudentID
			// 
			this->lblStudentID->AutoSize = true;
			this->lblStudentID->Location = System::Drawing::Point(52, 72);
			this->lblStudentID->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblStudentID->Name = L"lblStudentID";
			this->lblStudentID->Size = System::Drawing::Size(75, 13);
			this->lblStudentID->TabIndex = 0;
			this->lblStudentID->Text = L"Student Name";
			// 
			// lblCourses
			// 
			this->lblCourses->AutoSize = true;
			this->lblCourses->Location = System::Drawing::Point(52, 123);
			this->lblCourses->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblCourses->Name = L"lblCourses";
			this->lblCourses->Size = System::Drawing::Size(71, 13);
			this->lblCourses->TabIndex = 1;
			this->lblCourses->Text = L"Course Name";
			// 
			// lblGrade
			// 
			this->lblGrade->AutoSize = true;
			this->lblGrade->Location = System::Drawing::Point(52, 175);
			this->lblGrade->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblGrade->Name = L"lblGrade";
			this->lblGrade->Size = System::Drawing::Size(36, 13);
			this->lblGrade->TabIndex = 2;
			this->lblGrade->Text = L"Grade";
			// 
			// cboxGrades
			// 
			this->cboxGrades->FormattingEnabled = true;
			this->cboxGrades->Location = System::Drawing::Point(55, 190);
			this->cboxGrades->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->cboxGrades->Name = L"cboxGrades";
			this->cboxGrades->Size = System::Drawing::Size(228, 21);
			this->cboxGrades->TabIndex = 6;
			// 
			// btnSubmitGrade
			// 
			this->btnSubmitGrade->Location = System::Drawing::Point(55, 232);
			this->btnSubmitGrade->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnSubmitGrade->Name = L"btnSubmitGrade";
			this->btnSubmitGrade->Size = System::Drawing::Size(88, 24);
			this->btnSubmitGrade->TabIndex = 7;
			this->btnSubmitGrade->Text = L"Submit Grade";
			this->btnSubmitGrade->UseVisualStyleBackColor = true;
			this->btnSubmitGrade->Click += gcnew System::EventHandler(this, &GradeManagementForm::btnSubmitGrade_Click);
			// 
			// pboxLogo
			// 
			this->pboxLogo->BackColor = System::Drawing::Color::Transparent;
			this->pboxLogo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboxLogo.BackgroundImage")));
			this->pboxLogo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pboxLogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboxLogo.Image")));
			this->pboxLogo->Location = System::Drawing::Point(254, 20);
			this->pboxLogo->Name = L"pboxLogo";
			this->pboxLogo->Size = System::Drawing::Size(30, 30);
			this->pboxLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pboxLogo->TabIndex = 13;
			this->pboxLogo->TabStop = false;
			// 
			// lblProfile
			// 
			this->lblProfile->AutoSize = true;
			this->lblProfile->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProfile->Location = System::Drawing::Point(51, 20);
			this->lblProfile->Name = L"lblProfile";
			this->lblProfile->Size = System::Drawing::Size(76, 23);
			this->lblProfile->TabIndex = 12;
			this->lblProfile->Text = L"GRADES";
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(195, 232);
			this->btnCancel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(88, 24);
			this->btnCancel->TabIndex = 14;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &GradeManagementForm::btnCancel_Click);
			// 
			// cboxCourses
			// 
			this->cboxCourses->FormattingEnabled = true;
			this->cboxCourses->Location = System::Drawing::Point(55, 138);
			this->cboxCourses->Margin = System::Windows::Forms::Padding(2);
			this->cboxCourses->Name = L"cboxCourses";
			this->cboxCourses->Size = System::Drawing::Size(228, 21);
			this->cboxCourses->TabIndex = 16;
			// 
			// cboxStudentName
			// 
			this->cboxStudentName->FormattingEnabled = true;
			this->cboxStudentName->Location = System::Drawing::Point(55, 87);
			this->cboxStudentName->Margin = System::Windows::Forms::Padding(2);
			this->cboxStudentName->Name = L"cboxStudentName";
			this->cboxStudentName->Size = System::Drawing::Size(228, 21);
			this->cboxStudentName->TabIndex = 17;
			// 
			// GradeManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Linen;
			this->ClientSize = System::Drawing::Size(339, 290);
			this->Controls->Add(this->cboxStudentName);
			this->Controls->Add(this->cboxCourses);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->pboxLogo);
			this->Controls->Add(this->lblProfile);
			this->Controls->Add(this->btnSubmitGrade);
			this->Controls->Add(this->cboxGrades);
			this->Controls->Add(this->lblGrade);
			this->Controls->Add(this->lblCourses);
			this->Controls->Add(this->lblStudentID);
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"GradeManagementForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Grade Management";
			this->Load += gcnew System::EventHandler(this, &GradeManagementForm::GradeManagementForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboxLogo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSubmitGrade_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void GradeManagementForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void txtStudentID_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void LoadGrades(DatabaseManager^ db, Object^ sender, EventArgs^ e);
private: System::Void SubmitGrade(DatabaseManager^ db, Object^ sender, EventArgs^ e);
};
}
