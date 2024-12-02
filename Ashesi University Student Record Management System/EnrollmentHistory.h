#pragma once
#include "User.h"
#include "Student.h"
#include "Faculty.h"
#include "Admin.h"
#include <string>

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class EnrollmentHistory : public System::Windows::Forms::Form
	{
	public:
		User^ globalUser;
		Student^ student;
		Faculty^ faculty;
		Admin^ admin;
		String^ userRole;
		int^ studentid;

		EnrollmentHistory(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		EnrollmentHistory(User^ user)

		{
			InitializeComponent();
			// Perform dynamic casting once and then check the user type
			if (Student^ s = dynamic_cast<Student^>(user)) {
				this->student = s;
				this->globalUser = s;  // Assigning user to globalUser
				userRole = "Student";
				studentid = student->getStudentID();
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
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EnrollmentHistory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTxtTranscript;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EnrollmentHistory::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTxtTranscript = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(19, 10);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 25);
			this->button1->TabIndex = 0;
			this->button1->Text = L" View Enrollment History";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EnrollmentHistory::button1_Click);
			// 
			// richTxtTranscript
			// 
			this->richTxtTranscript->Location = System::Drawing::Point(19, 39);
			this->richTxtTranscript->Margin = System::Windows::Forms::Padding(2);
			this->richTxtTranscript->Name = L"richTxtTranscript";
			this->richTxtTranscript->Size = System::Drawing::Size(549, 301);
			this->richTxtTranscript->TabIndex = 4;
			this->richTxtTranscript->Text = L"";
			this->richTxtTranscript->TextChanged += gcnew System::EventHandler(this, &EnrollmentHistory::richTxtGrades_TextChanged);
			// 
			// EnrollmentHistory
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(592, 364);
			this->Controls->Add(this->richTxtTranscript);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"EnrollmentHistory";
			this->Text = L" View Enrollment History";
			this->Load += gcnew System::EventHandler(this, &EnrollmentHistory::EnrollmentHistory_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void EnrollmentHistory_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void richTxtGrades_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	};
}