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
	public ref class ViewGrades : public System::Windows::Forms::Form
	{
	public:
		User^ globalUser;
		Student^ student;
		Faculty^ faculty;
		Admin^ admin;
		String^ userRole;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnCancel;
	public:
		int^ studentid;

		ViewGrades(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ViewGrades(User^ user)

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
		~ViewGrades()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnViewGrades;
	protected:

	private: System::Windows::Forms::RichTextBox^ richTxtTranscript;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ViewGrades::typeid));
			this->btnViewGrades = (gcnew System::Windows::Forms::Button());
			this->richTxtTranscript = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnViewGrades
			// 
			this->btnViewGrades->Location = System::Drawing::Point(202, 324);
			this->btnViewGrades->Margin = System::Windows::Forms::Padding(2);
			this->btnViewGrades->Name = L"btnViewGrades";
			this->btnViewGrades->Size = System::Drawing::Size(92, 23);
			this->btnViewGrades->TabIndex = 0;
			this->btnViewGrades->Text = L"View Grades";
			this->btnViewGrades->UseVisualStyleBackColor = true;
			this->btnViewGrades->Click += gcnew System::EventHandler(this, &ViewGrades::btnViewGrades_Click);
			// 
			// richTxtTranscript
			// 
			this->richTxtTranscript->Location = System::Drawing::Point(11, 43);
			this->richTxtTranscript->Margin = System::Windows::Forms::Padding(2);
			this->richTxtTranscript->Name = L"richTxtTranscript";
			this->richTxtTranscript->Size = System::Drawing::Size(549, 269);
			this->richTxtTranscript->TabIndex = 4;
			this->richTxtTranscript->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 22);
			this->label1->TabIndex = 5;
			this->label1->Text = L"View Grades";
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(298, 324);
			this->btnCancel->Margin = System::Windows::Forms::Padding(2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(92, 23);
			this->btnCancel->TabIndex = 6;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &ViewGrades::btnCancel_Click);
			// 
			// ViewGrades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Linen;
			this->ClientSize = System::Drawing::Size(574, 358);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTxtTranscript);
			this->Controls->Add(this->btnViewGrades);
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ViewGrades";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"View Grades";
			this->Load += gcnew System::EventHandler(this, &ViewGrades::ViewGrades_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ViewGrades_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void btnViewGrades_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
};
}
