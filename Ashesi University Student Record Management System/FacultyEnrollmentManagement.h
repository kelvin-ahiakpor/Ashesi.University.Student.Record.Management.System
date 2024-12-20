#pragma once
#include "User.h"
#include "Faculty.h"
#include "DatabaseManager.h"

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FacultyEnrollmentManagement
	/// </summary>
	public ref class FacultyEnrollmentManagement : public System::Windows::Forms::Form
	{
	public:
		Faculty^ faculty;
		User^ globalUser;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::GroupBox^ groupBoxDetails;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ cboxStatus;





	public:


	public:
		int^ userID;
		FacultyEnrollmentManagement(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		FacultyEnrollmentManagement(User^ user)
		{
			// Perform dynamic casting once and then check the user type
			if (Faculty^ f = dynamic_cast<Faculty^>(user)) {
				this->faculty = f;
				this->globalUser = f;  // Assigning user to globalUser
				userID = faculty->getUserID();
			}
			else {
				throw gcnew System::ArgumentException("Unsupported user type.");
			}

			InitializeComponent();
		}
	private: System::Windows::Forms::Button^ btnSave;
	public:


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ ViewEnroll;

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker3;
	private: System::Windows::Forms::Label^ Student_Name;
	private: System::Windows::Forms::Label^ CourseName;
	private: System::Windows::Forms::Label^ Department;
	private: System::Windows::Forms::Label^ EnrollmentDate;
	private: System::Windows::Forms::Label^ Semester;


		

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~FacultyEnrollmentManagement()
			{
				if (components)
				{
					delete components;
				}
			}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FacultyEnrollmentManagement::typeid));
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ViewEnroll = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->Student_Name = (gcnew System::Windows::Forms::Label());
			this->CourseName = (gcnew System::Windows::Forms::Label());
			this->Department = (gcnew System::Windows::Forms::Label());
			this->EnrollmentDate = (gcnew System::Windows::Forms::Label());
			this->Semester = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->groupBoxDetails = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cboxStatus = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBoxDetails->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(553, 436);
			this->btnSave->Margin = System::Windows::Forms::Padding(2);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(86, 23);
			this->btnSave->TabIndex = 39;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &FacultyEnrollmentManagement::btnSave_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(-200, 111);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 13);
			this->label8->TabIndex = 38;
			this->label8->Text = L"StudentID";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(73, 81);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(545, 20);
			this->textBox5->TabIndex = 37;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(-204, 302);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(81, 13);
			this->label7->TabIndex = 36;
			this->label7->Text = L"Exprected Grad";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(-204, 179);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 13);
			this->label6->TabIndex = 34;
			this->label6->Text = L"Department Name";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(88, 111);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(530, 20);
			this->textBox4->TabIndex = 33;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(-204, 143);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 13);
			this->label5->TabIndex = 32;
			this->label5->Text = L"Email";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(-204, 263);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 13);
			this->label4->TabIndex = 30;
			this->label4->Text = L"EnrollmentDate";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(-200, 215);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 13);
			this->label3->TabIndex = 29;
			this->label3->Text = L"DOB";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(-204, 69);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Last Name";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(82, 48);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(536, 20);
			this->textBox2->TabIndex = 27;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(-204, 25);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 26;
			this->label1->Text = L"First Name";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(82, 14);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(536, 20);
			this->textBox1->TabIndex = 23;
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(17, 42);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(622, 171);
			this->dataGridView1->TabIndex = 22;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FacultyEnrollmentManagement::dataGridView1_CellClick);
			// 
			// ViewEnroll
			// 
			this->ViewEnroll->Location = System::Drawing::Point(520, 11);
			this->ViewEnroll->Margin = System::Windows::Forms::Padding(2);
			this->ViewEnroll->Name = L"ViewEnroll";
			this->ViewEnroll->Size = System::Drawing::Size(119, 26);
			this->ViewEnroll->TabIndex = 40;
			this->ViewEnroll->Text = L"View Enrollments";
			this->ViewEnroll->UseVisualStyleBackColor = true;
			this->ViewEnroll->Click += gcnew System::EventHandler(this, &FacultyEnrollmentManagement::ViewEnroll_Click);
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Location = System::Drawing::Point(90, 142);
			this->dateTimePicker3->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(528, 20);
			this->dateTimePicker3->TabIndex = 35;
			// 
			// Student_Name
			// 
			this->Student_Name->AutoSize = true;
			this->Student_Name->Location = System::Drawing::Point(7, 16);
			this->Student_Name->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Student_Name->Name = L"Student_Name";
			this->Student_Name->Size = System::Drawing::Size(75, 13);
			this->Student_Name->TabIndex = 41;
			this->Student_Name->Text = L"Student Name";
			// 
			// CourseName
			// 
			this->CourseName->AutoSize = true;
			this->CourseName->Location = System::Drawing::Point(7, 51);
			this->CourseName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->CourseName->Name = L"CourseName";
			this->CourseName->Size = System::Drawing::Size(71, 13);
			this->CourseName->TabIndex = 42;
			this->CourseName->Text = L"Course Name";
			// 
			// Department
			// 
			this->Department->AutoSize = true;
			this->Department->Location = System::Drawing::Point(7, 84);
			this->Department->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Department->Name = L"Department";
			this->Department->Size = System::Drawing::Size(62, 13);
			this->Department->TabIndex = 43;
			this->Department->Text = L"Department";
			// 
			// EnrollmentDate
			// 
			this->EnrollmentDate->AutoSize = true;
			this->EnrollmentDate->Location = System::Drawing::Point(7, 148);
			this->EnrollmentDate->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->EnrollmentDate->Name = L"EnrollmentDate";
			this->EnrollmentDate->Size = System::Drawing::Size(79, 13);
			this->EnrollmentDate->TabIndex = 44;
			this->EnrollmentDate->Text = L"EnrollmentDate";
			// 
			// Semester
			// 
			this->Semester->AutoSize = true;
			this->Semester->Location = System::Drawing::Point(7, 118);
			this->Semester->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Semester->Name = L"Semester";
			this->Semester->Size = System::Drawing::Size(51, 13);
			this->Semester->TabIndex = 45;
			this->Semester->Text = L"Semester";
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(473, 436);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 46;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &FacultyEnrollmentManagement::btnCancel_Click);
			// 
			// groupBoxDetails
			// 
			this->groupBoxDetails->Controls->Add(this->cboxStatus);
			this->groupBoxDetails->Controls->Add(this->label9);
			this->groupBoxDetails->Controls->Add(this->Department);
			this->groupBoxDetails->Controls->Add(this->textBox4);
			this->groupBoxDetails->Controls->Add(this->textBox2);
			this->groupBoxDetails->Controls->Add(this->Semester);
			this->groupBoxDetails->Controls->Add(this->textBox1);
			this->groupBoxDetails->Controls->Add(this->textBox5);
			this->groupBoxDetails->Controls->Add(this->CourseName);
			this->groupBoxDetails->Controls->Add(this->dateTimePicker3);
			this->groupBoxDetails->Controls->Add(this->EnrollmentDate);
			this->groupBoxDetails->Controls->Add(this->Student_Name);
			this->groupBoxDetails->Location = System::Drawing::Point(16, 218);
			this->groupBoxDetails->Name = L"groupBoxDetails";
			this->groupBoxDetails->Size = System::Drawing::Size(623, 213);
			this->groupBoxDetails->TabIndex = 47;
			this->groupBoxDetails->TabStop = false;
			this->groupBoxDetails->Text = L"Details";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(7, 188);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(37, 13);
			this->label9->TabIndex = 46;
			this->label9->Text = L"Status";
			// 
			// cboxStatus
			// 
			this->cboxStatus->FormattingEnabled = true;
			this->cboxStatus->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Enrolled", L"Pending", L"Withdrawn" });
			this->cboxStatus->Location = System::Drawing::Point(90, 185);
			this->cboxStatus->Name = L"cboxStatus";
			this->cboxStatus->Size = System::Drawing::Size(528, 21);
			this->cboxStatus->TabIndex = 48;
			// 
			// FacultyEnrollmentManagement
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(664, 468);
			this->Controls->Add(this->ViewEnroll);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBoxDetails);
			this->ForeColor = System::Drawing::Color::Maroon;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FacultyEnrollmentManagement";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Enroll Students";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBoxDetails->ResumeLayout(false);
			this->groupBoxDetails->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void ViewEnroll_Click(System::Object^ sender, System::EventArgs^ e);
 private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void CourseName_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void ViewEnrollments(DatabaseManager^ db, System::Object^ sender, System::EventArgs^ e);
	   };
}
