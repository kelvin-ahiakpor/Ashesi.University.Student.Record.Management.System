#pragma once
#include "User.h"
#include "Student.h"
#include "Faculty.h"
#include "Admin.h"
#include "DatabaseManager.h"
#include "PasswordManager.h"
#include "ProfileManagementForm.h"

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SecurityQuestionForm
	/// </summary>
	public ref class SecurityQuestionForm : public System::Windows::Forms::Form
	{
	public:
		User^ globalUser;
		Student^ student;
		Faculty^ faculty;
		Admin^ admin;
		String^ userRole;
		String^ userEmail;
		String^ mode;
		int^ userID;
		SecurityQuestionForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


		SecurityQuestionForm(User^ user)
		{
			InitializeComponent();
			// Perform dynamic casting once and then check the user type
			if (Student^ s = dynamic_cast<Student^>(user)) {
				this->student = s;
				this->globalUser = s;  // Assigning user to globalUser
				this->userEmail = s->getEmail();
				this->userID = s->getUserID();
				this->mode = mode;
				userRole = "Student";
			}
			else if (Faculty^ f = dynamic_cast<Faculty^>(user)) {
				this->faculty = f;
				this->globalUser = f;  // Assigning user to globalUser
				this->userEmail = f->getEmail();
				this->userID = f->getUserID();
				this->mode = mode;
				userRole = "Faculty";

			}
			else if (Admin^ a = dynamic_cast<Admin^>(user)) {
				this->admin = a;
				this->globalUser = a;  // Assigning user to globalUser
				this->userEmail = a->getEmail();
				this->userID = a->getUserID();
				this->mode = mode;
				userRole = "Administrator";
			}
			else {
				throw gcnew System::ArgumentException("Unsupported user type.");
			}
		}

		// Methods
		bool VerifySecurityAnswer(String^ enteredHashedAnswer);
		static String^ GetSecurityAnswerFromDB(int^ userID);
		static void SetSecurityQuestion(int^ userID, String^ answer);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SecurityQuestionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCancel;
	protected:
	private: System::Windows::Forms::PictureBox^ pboxLogo;
	private: System::Windows::Forms::Label^ lblProfile;
	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::Label^ lblCourses;
	private: System::Windows::Forms::Label^ lblQuestion;
	private: System::Windows::Forms::Label^ lblQuestionText;
	private: System::Windows::Forms::TextBox^ txtAnswer;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SecurityQuestionForm::typeid));
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->pboxLogo = (gcnew System::Windows::Forms::PictureBox());
			this->lblProfile = (gcnew System::Windows::Forms::Label());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->lblCourses = (gcnew System::Windows::Forms::Label());
			this->lblQuestion = (gcnew System::Windows::Forms::Label());
			this->lblQuestionText = (gcnew System::Windows::Forms::Label());
			this->txtAnswer = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboxLogo))->BeginInit();
			this->SuspendLayout();
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(167, 172);
			this->btnCancel->Margin = System::Windows::Forms::Padding(2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(88, 24);
			this->btnCancel->TabIndex = 24;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &SecurityQuestionForm::btnCancel_Click);
			// 
			// pboxLogo
			// 
			this->pboxLogo->BackColor = System::Drawing::Color::Transparent;
			this->pboxLogo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboxLogo.BackgroundImage")));
			this->pboxLogo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pboxLogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboxLogo.Image")));
			this->pboxLogo->Location = System::Drawing::Point(225, 14);
			this->pboxLogo->Name = L"pboxLogo";
			this->pboxLogo->Size = System::Drawing::Size(30, 30);
			this->pboxLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pboxLogo->TabIndex = 23;
			this->pboxLogo->TabStop = false;
			// 
			// lblProfile
			// 
			this->lblProfile->AutoSize = true;
			this->lblProfile->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProfile->Location = System::Drawing::Point(22, 14);
			this->lblProfile->Name = L"lblProfile";
			this->lblProfile->Size = System::Drawing::Size(197, 23);
			this->lblProfile->TabIndex = 22;
			this->lblProfile->Text = L"SECURITY QUESTION";
			// 
			// btnSubmit
			// 
			this->btnSubmit->Location = System::Drawing::Point(26, 172);
			this->btnSubmit->Margin = System::Windows::Forms::Padding(2);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(88, 24);
			this->btnSubmit->TabIndex = 21;
			this->btnSubmit->Text = L"Submit Answer";
			this->btnSubmit->UseVisualStyleBackColor = true;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &SecurityQuestionForm::btnSubmit_Click);
			// 
			// lblCourses
			// 
			this->lblCourses->AutoSize = true;
			this->lblCourses->Location = System::Drawing::Point(23, 117);
			this->lblCourses->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblCourses->Name = L"lblCourses";
			this->lblCourses->Size = System::Drawing::Size(42, 13);
			this->lblCourses->TabIndex = 16;
			this->lblCourses->Text = L"Answer";
			// 
			// lblQuestion
			// 
			this->lblQuestion->AutoSize = true;
			this->lblQuestion->Location = System::Drawing::Point(23, 66);
			this->lblQuestion->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblQuestion->Name = L"lblQuestion";
			this->lblQuestion->Size = System::Drawing::Size(49, 13);
			this->lblQuestion->TabIndex = 15;
			this->lblQuestion->Text = L"Question";
			// 
			// lblQuestionText
			// 
			this->lblQuestionText->AutoSize = true;
			this->lblQuestionText->Location = System::Drawing::Point(23, 82);
			this->lblQuestionText->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblQuestionText->Name = L"lblQuestionText";
			this->lblQuestionText->Size = System::Drawing::Size(168, 13);
			this->lblQuestionText->TabIndex = 25;
			this->lblQuestionText->Text = L"What is the name of your first pet\?";
			// 
			// txtAnswer
			// 
			this->txtAnswer->Location = System::Drawing::Point(26, 133);
			this->txtAnswer->Name = L"txtAnswer";
			this->txtAnswer->Size = System::Drawing::Size(229, 20);
			this->txtAnswer->TabIndex = 26;
			// 
			// SecurityQuestionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Linen;
			this->ClientSize = System::Drawing::Size(284, 213);
			this->Controls->Add(this->txtAnswer);
			this->Controls->Add(this->lblQuestionText);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->pboxLogo);
			this->Controls->Add(this->lblProfile);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->lblCourses);
			this->Controls->Add(this->lblQuestion);
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SecurityQuestionForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SecurityQuestionForm";
			this->Load += gcnew System::EventHandler(this, &SecurityQuestionForm::SecurityQuestionForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboxLogo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void SecurityQuestionForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
