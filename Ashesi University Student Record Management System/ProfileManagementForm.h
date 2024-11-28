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
	/// Summary for ProfileManagementForm
	/// </summary>
	public ref class ProfileManagementForm : public System::Windows::Forms::Form
	{
	public:
		User^ globalUser;
		Student^ student;
		Faculty^ faculty;
		Admin^ admin;
		String^ userRole;

		ProfileManagementForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		ProfileManagementForm(User^ user)
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
		~ProfileManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblFirstName;
	private: System::Windows::Forms::Label^ lblLastName;
	private: System::Windows::Forms::Label^ lblEmail;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ btnSaveProfile;
	protected:

	protected:




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
			this->lblFirstName = (gcnew System::Windows::Forms::Label());
			this->lblLastName = (gcnew System::Windows::Forms::Label());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->btnSaveProfile = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblFirstName
			// 
			this->lblFirstName->AutoSize = true;
			this->lblFirstName->Location = System::Drawing::Point(52, 51);
			this->lblFirstName->Name = L"lblFirstName";
			this->lblFirstName->Size = System::Drawing::Size(116, 25);
			this->lblFirstName->TabIndex = 0;
			this->lblFirstName->Text = L"First Name";
			// 
			// lblLastName
			// 
			this->lblLastName->AutoSize = true;
			this->lblLastName->Location = System::Drawing::Point(52, 147);
			this->lblLastName->Name = L"lblLastName";
			this->lblLastName->Size = System::Drawing::Size(115, 25);
			this->lblLastName->TabIndex = 1;
			this->lblLastName->Text = L"Last Name";
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Location = System::Drawing::Point(52, 250);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(65, 25);
			this->lblEmail->TabIndex = 2;
			this->lblEmail->Text = L"Email";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(52, 345);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(106, 25);
			this->lblPassword->TabIndex = 3;
			this->lblPassword->Text = L"Password";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(57, 79);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(416, 31);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(57, 175);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(416, 31);
			this->textBox2->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(57, 278);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(416, 31);
			this->textBox3->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(57, 373);
			this->textBox4->Name = L"textBox4";
			this->textBox4->PasswordChar = '*';
			this->textBox4->Size = System::Drawing::Size(416, 31);
			this->textBox4->TabIndex = 7;
			// 
			// btnSaveProfile
			// 
			this->btnSaveProfile->Location = System::Drawing::Point(57, 448);
			this->btnSaveProfile->Name = L"btnSaveProfile";
			this->btnSaveProfile->Size = System::Drawing::Size(240, 46);
			this->btnSaveProfile->TabIndex = 8;
			this->btnSaveProfile->Text = L"Save Profile";
			this->btnSaveProfile->UseVisualStyleBackColor = true;
			this->btnSaveProfile->Click += gcnew System::EventHandler(this, &ProfileManagementForm::btnSaveProfile_Click);
			// 
			// ProfileManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 560);
			this->Controls->Add(this->btnSaveProfile);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->lblEmail);
			this->Controls->Add(this->lblLastName);
			this->Controls->Add(this->lblFirstName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"ProfileManagementForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"ProfileManagementForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSaveProfile_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Profile saved successfully.");
	}
};
}
