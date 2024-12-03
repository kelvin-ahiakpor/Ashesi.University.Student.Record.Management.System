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
	private: System::Windows::Forms::TextBox^ CourseNameBox;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GradeManagementForm::typeid));
			this->lblStudentID = (gcnew System::Windows::Forms::Label());
			this->lblCourses = (gcnew System::Windows::Forms::Label());
			this->lblGrade = (gcnew System::Windows::Forms::Label());
			this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
			this->cboxGrades = (gcnew System::Windows::Forms::ComboBox());
			this->btnSubmitGrade = (gcnew System::Windows::Forms::Button());
			this->pboxLogo = (gcnew System::Windows::Forms::PictureBox());
			this->lblProfile = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->CourseNameBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboxLogo))->BeginInit();
			this->SuspendLayout();
			// 
			// lblStudentID
			// 
			this->lblStudentID->AutoSize = true;
			this->lblStudentID->Location = System::Drawing::Point(69, 89);
			this->lblStudentID->Name = L"lblStudentID";
			this->lblStudentID->Size = System::Drawing::Size(68, 16);
			this->lblStudentID->TabIndex = 0;
			this->lblStudentID->Text = L"Student ID";
			// 
			// lblCourses
			// 
			this->lblCourses->AutoSize = true;
			this->lblCourses->Location = System::Drawing::Point(69, 151);
			this->lblCourses->Name = L"lblCourses";
			this->lblCourses->Size = System::Drawing::Size(90, 16);
			this->lblCourses->TabIndex = 1;
			this->lblCourses->Text = L"Course Name";
			// 
			// lblGrade
			// 
			this->lblGrade->AutoSize = true;
			this->lblGrade->Location = System::Drawing::Point(69, 215);
			this->lblGrade->Name = L"lblGrade";
			this->lblGrade->Size = System::Drawing::Size(45, 16);
			this->lblGrade->TabIndex = 2;
			this->lblGrade->Text = L"Grade";
			// 
			// txtStudentID
			// 
			this->txtStudentID->Location = System::Drawing::Point(73, 106);
			this->txtStudentID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStudentID->Name = L"txtStudentID";
			this->txtStudentID->Size = System::Drawing::Size(152, 22);
			this->txtStudentID->TabIndex = 5;
			this->txtStudentID->TextChanged += gcnew System::EventHandler(this, &GradeManagementForm::txtStudentID_TextChanged);
			// 
			// cboxGrades
			// 
			this->cboxGrades->FormattingEnabled = true;
			this->cboxGrades->Location = System::Drawing::Point(73, 234);
			this->cboxGrades->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cboxGrades->Name = L"cboxGrades";
			this->cboxGrades->Size = System::Drawing::Size(303, 24);
			this->cboxGrades->TabIndex = 6;
			// 
			// btnSubmitGrade
			// 
			this->btnSubmitGrade->Location = System::Drawing::Point(73, 286);
			this->btnSubmitGrade->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSubmitGrade->Name = L"btnSubmitGrade";
			this->btnSubmitGrade->Size = System::Drawing::Size(117, 30);
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
			this->pboxLogo->Location = System::Drawing::Point(339, 25);
			this->pboxLogo->Margin = System::Windows::Forms::Padding(4);
			this->pboxLogo->Name = L"pboxLogo";
			this->pboxLogo->Size = System::Drawing::Size(40, 37);
			this->pboxLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pboxLogo->TabIndex = 13;
			this->pboxLogo->TabStop = false;
			// 
			// lblProfile
			// 
			this->lblProfile->AutoSize = true;
			this->lblProfile->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProfile->Location = System::Drawing::Point(68, 25);
			this->lblProfile->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblProfile->Name = L"lblProfile";
			this->lblProfile->Size = System::Drawing::Size(97, 29);
			this->lblProfile->TabIndex = 12;
			this->lblProfile->Text = L"GRADES";
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(260, 286);
			this->btnCancel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(117, 30);
			this->btnCancel->TabIndex = 14;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &GradeManagementForm::btnCancel_Click);
			// 
			// CourseNameBox
			// 
			this->CourseNameBox->Location = System::Drawing::Point(72, 180);
			this->CourseNameBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CourseNameBox->Name = L"CourseNameBox";
			this->CourseNameBox->Size = System::Drawing::Size(153, 22);
			this->CourseNameBox->TabIndex = 15;
			// 
			// GradeManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Linen;
			this->ClientSize = System::Drawing::Size(452, 357);
			this->Controls->Add(this->CourseNameBox);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->pboxLogo);
			this->Controls->Add(this->lblProfile);
			this->Controls->Add(this->btnSubmitGrade);
			this->Controls->Add(this->cboxGrades);
			this->Controls->Add(this->txtStudentID);
			this->Controls->Add(this->lblGrade);
			this->Controls->Add(this->lblCourses);
			this->Controls->Add(this->lblStudentID);
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
