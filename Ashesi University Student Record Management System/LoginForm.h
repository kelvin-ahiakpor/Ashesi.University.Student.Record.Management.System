#pragma once
#include "MainApplicationForm.h"

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		DataTable^ sqlDt;
		MySqlDataAdapter^ sqlDtA;

	public:
		LoginForm(void)
		{
			InitializeComponent();
			sqlConn = gcnew MySqlConnection();
			sqlCmd = gcnew MySqlCommand();
			sqlDt = gcnew DataTable();
			sqlDtA = gcnew MySqlDataAdapter();
			//
			//TODO: Add the constructor code here
			//
		}
		MySqlDataReader^ sqlRd;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblEmail;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::Label^ lblError;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::LinkLabel^ lnklblPasswordReset;
	private: System::Windows::Forms::Button^ btnCancel;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->lnklblPasswordReset = (gcnew System::Windows::Forms::LinkLabel());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Location = System::Drawing::Point(119, 61);
			this->lblEmail->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(38, 20);
			this->lblEmail->TabIndex = 0;
			this->lblEmail->Text = L"Email";
			this->lblEmail->UseCompatibleTextRendering = true;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(115, 135);
			this->lblPassword->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(67, 16);
			this->lblPassword->TabIndex = 1;
			this->lblPassword->Text = L"Password";
			// 
			// lblError
			// 
			this->lblError->AutoSize = true;
			this->lblError->Location = System::Drawing::Point(115, 194);
			this->lblError->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(39, 16);
			this->lblError->TabIndex = 2;
			this->lblError->Text = L"Error:";
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(119, 82);
			this->txtEmail->Margin = System::Windows::Forms::Padding(2);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(252, 22);
			this->txtEmail->TabIndex = 3;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(119, 153);
			this->txtPassword->Margin = System::Windows::Forms::Padding(2);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(252, 22);
			this->txtPassword->TabIndex = 4;
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(119, 258);
			this->btnLogin->Margin = System::Windows::Forms::Padding(2);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(102, 33);
			this->btnLogin->TabIndex = 5;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
			// 
			// lnklblPasswordReset
			// 
			this->lnklblPasswordReset->AutoSize = true;
			this->lnklblPasswordReset->Location = System::Drawing::Point(115, 230);
			this->lnklblPasswordReset->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lnklblPasswordReset->Name = L"lnklblPasswordReset";
			this->lnklblPasswordReset->Size = System::Drawing::Size(116, 16);
			this->lnklblPasswordReset->TabIndex = 7;
			this->lnklblPasswordReset->TabStop = true;
			this->lnklblPasswordReset->Text = L"Forgot Password\?";
			this->lnklblPasswordReset->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::lnklblPasswordReset_LinkClicked);
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(267, 258);
			this->btnCancel->Margin = System::Windows::Forms::Padding(2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(102, 33);
			this->btnCancel->TabIndex = 8;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &LoginForm::btnCancel_Click);
			// 
			// LoginForm
			// 
			this->AcceptButton = this->btnLogin;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnCancel;
			this->ClientSize = System::Drawing::Size(515, 342);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->lnklblPasswordReset);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->lblError);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->lblEmail);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"LoginForm";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void lnklblPasswordReset_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
