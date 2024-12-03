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
	private: System::Windows::Forms::Label^ lblError;
	private: System::Windows::Forms::PictureBox^ pboxLogo;
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
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->lnklblPasswordReset = (gcnew System::Windows::Forms::LinkLabel());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->pboxLogo = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboxLogo))->BeginInit();
			this->SuspendLayout();
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Location = System::Drawing::Point(96, 61);
			this->lblEmail->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(33, 17);
			this->lblEmail->TabIndex = 0;
			this->lblEmail->Text = L"Email";
			this->lblEmail->UseCompatibleTextRendering = true;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(93, 121);
			this->lblPassword->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(53, 13);
			this->lblPassword->TabIndex = 1;
			this->lblPassword->Text = L"Password";
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(96, 78);
			this->txtEmail->Margin = System::Windows::Forms::Padding(2);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(190, 20);
			this->txtEmail->TabIndex = 3;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(96, 135);
			this->txtPassword->Margin = System::Windows::Forms::Padding(2);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(190, 20);
			this->txtPassword->TabIndex = 4;
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(96, 221);
			this->btnLogin->Margin = System::Windows::Forms::Padding(2);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(76, 27);
			this->btnLogin->TabIndex = 5;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
			// 
			// lnklblPasswordReset
			// 
			this->lnklblPasswordReset->AutoSize = true;
			this->lnklblPasswordReset->Location = System::Drawing::Point(93, 198);
			this->lnklblPasswordReset->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lnklblPasswordReset->Name = L"lnklblPasswordReset";
			this->lnklblPasswordReset->Size = System::Drawing::Size(92, 13);
			this->lnklblPasswordReset->TabIndex = 7;
			this->lnklblPasswordReset->TabStop = true;
			this->lnklblPasswordReset->Text = L"Forgot Password\?";
			this->lnklblPasswordReset->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::lnklblPasswordReset_LinkClicked);
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(207, 221);
			this->btnCancel->Margin = System::Windows::Forms::Padding(2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(76, 27);
			this->btnCancel->TabIndex = 8;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &LoginForm::btnCancel_Click);
			// 
			// lblError
			// 
			this->lblError->AutoSize = true;
			this->lblError->Location = System::Drawing::Point(93, 169);
			this->lblError->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(32, 13);
			this->lblError->TabIndex = 2;
			this->lblError->Text = L"Error:";
			// 
			// pboxLogo
			// 
			this->pboxLogo->BackColor = System::Drawing::Color::Transparent;
			this->pboxLogo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboxLogo.BackgroundImage")));
			this->pboxLogo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pboxLogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pboxLogo.Image")));
			this->pboxLogo->Location = System::Drawing::Point(179, 12);
			this->pboxLogo->Name = L"pboxLogo";
			this->pboxLogo->Size = System::Drawing::Size(30, 30);
			this->pboxLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pboxLogo->TabIndex = 9;
			this->pboxLogo->TabStop = false;
			// 
			// LoginForm
			// 
			this->AcceptButton = this->btnLogin;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Linen;
			this->CancelButton = this->btnCancel;
			this->ClientSize = System::Drawing::Size(386, 272);
			this->Controls->Add(this->pboxLogo);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->lnklblPasswordReset);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->lblError);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->lblEmail);
			this->ForeColor = System::Drawing::Color::Maroon;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pboxLogo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void lnklblPasswordReset_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
};
}
