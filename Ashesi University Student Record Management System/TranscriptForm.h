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
	/// Summary for TranscriptForm
	/// </summary>
	public ref class TranscriptForm : public System::Windows::Forms::Form
	{
	public:
		User^ globalUser;
		Student^ student;
		Faculty^ faculty;
		Admin^ admin;
		List<Student^>^ cachedStudents = gcnew List<Student^>();

	private: System::Windows::Forms::ComboBox^ cboxStudentName;
	private: System::Windows::Forms::TextBox^ textStudentID;



	public:
		String^ userRole;
		TranscriptForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		TranscriptForm(User^ user)
		{
			InitializeComponent();
			// Perform dynamic casting once and then check the user type
			if (Student^ s = dynamic_cast<Student^>(user)) {
				this->student = s;
				this->globalUser = s;  // Assigning user to globalUser
				userRole = "Student";

				this->lblStudentID->Enabled = true;
				this->lblStudentID->Text = "Student ID";
				this->textStudentID->Enabled = false;
				this->cboxStudentName->Enabled = false;
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
				this->textStudentID->Visible = false;
			}
			else {
				throw gcnew System::ArgumentException("Unsupported user type.");
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TranscriptForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblStudentID;
	protected:

	private: System::Windows::Forms::Button^ btnViewTranscript;
	private: System::Windows::Forms::RichTextBox^ richTxtTranscript;
	private: System::Windows::Forms::Button^ btnPrintTranscript;

	private:
		void DisablePrintButtonBasedOnUserRole();
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TranscriptForm::typeid));
			this->lblStudentID = (gcnew System::Windows::Forms::Label());
			this->btnViewTranscript = (gcnew System::Windows::Forms::Button());
			this->richTxtTranscript = (gcnew System::Windows::Forms::RichTextBox());
			this->btnPrintTranscript = (gcnew System::Windows::Forms::Button());
			this->cboxStudentName = (gcnew System::Windows::Forms::ComboBox());
			this->textStudentID = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// lblStudentID
			// 
			this->lblStudentID->AutoSize = true;
			this->lblStudentID->Location = System::Drawing::Point(31, 12);
			this->lblStudentID->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblStudentID->Name = L"lblStudentID";
			this->lblStudentID->Size = System::Drawing::Size(75, 13);
			this->lblStudentID->TabIndex = 0;
			this->lblStudentID->Text = L"Student Name";
			// 
			// btnViewTranscript
			// 
			this->btnViewTranscript->Location = System::Drawing::Point(388, 23);
			this->btnViewTranscript->Margin = System::Windows::Forms::Padding(2);
			this->btnViewTranscript->Name = L"btnViewTranscript";
			this->btnViewTranscript->Size = System::Drawing::Size(88, 23);
			this->btnViewTranscript->TabIndex = 2;
			this->btnViewTranscript->Text = L"View Transcript";
			this->btnViewTranscript->UseVisualStyleBackColor = true;
			this->btnViewTranscript->Click += gcnew System::EventHandler(this, &TranscriptForm::btnViewTranscript_Click);
			// 
			// richTxtTranscript
			// 
			this->richTxtTranscript->Location = System::Drawing::Point(34, 68);
			this->richTxtTranscript->Margin = System::Windows::Forms::Padding(2);
			this->richTxtTranscript->Name = L"richTxtTranscript";
			this->richTxtTranscript->Size = System::Drawing::Size(549, 301);
			this->richTxtTranscript->TabIndex = 3;
			this->richTxtTranscript->Text = L"";
			this->richTxtTranscript->TextChanged += gcnew System::EventHandler(this, &TranscriptForm::richTxtTranscript_TextChanged);
			// 
			// btnPrintTranscript
			// 
			this->btnPrintTranscript->Location = System::Drawing::Point(480, 23);
			this->btnPrintTranscript->Margin = System::Windows::Forms::Padding(2);
			this->btnPrintTranscript->Name = L"btnPrintTranscript";
			this->btnPrintTranscript->Size = System::Drawing::Size(103, 23);
			this->btnPrintTranscript->TabIndex = 4;
			this->btnPrintTranscript->Text = L"Print Transcript";
			this->btnPrintTranscript->UseVisualStyleBackColor = true;
			this->btnPrintTranscript->Click += gcnew System::EventHandler(this, &TranscriptForm::btnPrintTranscript_Click);
			// 
			// cboxStudentName
			// 
			this->cboxStudentName->FormattingEnabled = true;
			this->cboxStudentName->Location = System::Drawing::Point(34, 28);
			this->cboxStudentName->Name = L"cboxStudentName";
			this->cboxStudentName->Size = System::Drawing::Size(157, 21);
			this->cboxStudentName->TabIndex = 5;
			this->cboxStudentName->SelectedIndexChanged += gcnew System::EventHandler(this, &TranscriptForm::cboxStudentName_SelectedIndexChanged);
			this->cboxStudentName->TextChanged += gcnew System::EventHandler(this, &TranscriptForm::cboxStudentName_TextChanged);
			// 
			// textStudentID
			// 
			this->textStudentID->Location = System::Drawing::Point(34, 29);
			this->textStudentID->Name = L"textStudentID";
			this->textStudentID->Size = System::Drawing::Size(157, 20);
			this->textStudentID->TabIndex = 6;
			// 
			// TranscriptForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 386);
			this->Controls->Add(this->textStudentID);
			this->Controls->Add(this->cboxStudentName);
			this->Controls->Add(this->btnPrintTranscript);
			this->Controls->Add(this->richTxtTranscript);
			this->Controls->Add(this->btnViewTranscript);
			this->Controls->Add(this->lblStudentID);
			this->ForeColor = System::Drawing::Color::Maroon;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"TranscriptForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Transcripts";
			this->Load += gcnew System::EventHandler(this, &TranscriptForm::TranscriptForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnViewTranscript_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void btnPrintTranscript_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void txtStudentID_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTxtTranscript_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TranscriptForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void GetTranscript(DatabaseManager^ db);
	   
private: System::Void cboxStudentName_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void LoadStudentsToCache();
private: System::Void cboxStudentName_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
};
}
