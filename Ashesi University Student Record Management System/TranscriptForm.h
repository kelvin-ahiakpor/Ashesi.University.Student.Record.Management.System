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
	/// Summary for TranscriptForm
	/// </summary>
	public ref class TranscriptForm : public System::Windows::Forms::Form
	{
	public:
		User^ globalUser;
		Student^ student;
		Faculty^ faculty;
		Admin^ admin;
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
		~TranscriptForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblStudentID;
	protected:
	private: System::Windows::Forms::TextBox^ txtStudentID;
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
			this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
			this->btnViewTranscript = (gcnew System::Windows::Forms::Button());
			this->richTxtTranscript = (gcnew System::Windows::Forms::RichTextBox());
			this->btnPrintTranscript = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblStudentID
			// 
			this->lblStudentID->AutoSize = true;
			this->lblStudentID->Location = System::Drawing::Point(31, 28);
			this->lblStudentID->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblStudentID->Name = L"lblStudentID";
			this->lblStudentID->Size = System::Drawing::Size(58, 13);
			this->lblStudentID->TabIndex = 0;
			this->lblStudentID->Text = L"Student ID";
			// 
			// txtStudentID
			// 
			this->txtStudentID->Location = System::Drawing::Point(34, 42);
			this->txtStudentID->Margin = System::Windows::Forms::Padding(2);
			this->txtStudentID->Name = L"txtStudentID";
			this->txtStudentID->Size = System::Drawing::Size(157, 20);
			this->txtStudentID->TabIndex = 1;
			this->txtStudentID->TextChanged += gcnew System::EventHandler(this, &TranscriptForm::txtStudentID_TextChanged);
			// 
			// btnViewTranscript
			// 
			this->btnViewTranscript->Location = System::Drawing::Point(34, 90);
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
			this->richTxtTranscript->Location = System::Drawing::Point(34, 128);
			this->richTxtTranscript->Margin = System::Windows::Forms::Padding(2);
			this->richTxtTranscript->Name = L"richTxtTranscript";
			this->richTxtTranscript->Size = System::Drawing::Size(549, 301);
			this->richTxtTranscript->TabIndex = 3;
			this->richTxtTranscript->Text = L"";
			this->richTxtTranscript->TextChanged += gcnew System::EventHandler(this, &TranscriptForm::richTxtTranscript_TextChanged);
			// 
			// btnPrintTranscript
			// 
			this->btnPrintTranscript->Location = System::Drawing::Point(478, 28);
			this->btnPrintTranscript->Margin = System::Windows::Forms::Padding(2);
			this->btnPrintTranscript->Name = L"btnPrintTranscript";
			this->btnPrintTranscript->Size = System::Drawing::Size(103, 28);
			this->btnPrintTranscript->TabIndex = 4;
			this->btnPrintTranscript->Text = L"Print Transcript";
			this->btnPrintTranscript->UseVisualStyleBackColor = true;
			this->btnPrintTranscript->Click += gcnew System::EventHandler(this, &TranscriptForm::btnPrintTranscript_Click);
			// 
			// TranscriptForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 467);
			this->Controls->Add(this->btnPrintTranscript);
			this->Controls->Add(this->richTxtTranscript);
			this->Controls->Add(this->btnViewTranscript);
			this->Controls->Add(this->txtStudentID);
			this->Controls->Add(this->lblStudentID);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"TranscriptForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"TranscriptForm";
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
	   
};
}
