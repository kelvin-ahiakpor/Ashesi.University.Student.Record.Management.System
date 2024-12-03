#pragma once
#include "User.h"
#include "Faculty.h"
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
	private: System::Windows::Forms::ComboBox^ statusBox1;


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
			this->statusBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBoxDetails->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(737, 537);
			this->btnSave->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(115, 28);
			this->btnSave->TabIndex = 39;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &FacultyEnrollmentManagement::btnSave_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(-267, 137);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 16);
			this->label8->TabIndex = 38;
			this->label8->Text = L"StudentID";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(97, 100);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(725, 22);
			this->textBox5->TabIndex = 37;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(-272, 372);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(101, 16);
			this->label7->TabIndex = 36;
			this->label7->Text = L"Exprected Grad";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(-272, 220);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(117, 16);
			this->label6->TabIndex = 34;
			this->label6->Text = L"Department Name";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(117, 137);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(705, 22);
			this->textBox4->TabIndex = 33;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(-272, 176);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 16);
			this->label5->TabIndex = 32;
			this->label5->Text = L"Email";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(-272, 324);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 16);
			this->label4->TabIndex = 30;
			this->label4->Text = L"EnrollmentDate";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(-267, 265);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 16);
			this->label3->TabIndex = 29;
			this->label3->Text = L"DOB";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(-272, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 16);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Last Name";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(109, 59);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(713, 22);
			this->textBox2->TabIndex = 27;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(-272, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 16);
			this->label1->TabIndex = 26;
			this->label1->Text = L"First Name";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(109, 17);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(713, 22);
			this->textBox1->TabIndex = 23;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(23, 52);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(829, 210);
			this->dataGridView1->TabIndex = 22;
			// 
			// ViewEnroll
			// 
			this->ViewEnroll->Location = System::Drawing::Point(693, 14);
			this->ViewEnroll->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ViewEnroll->Name = L"ViewEnroll";
			this->ViewEnroll->Size = System::Drawing::Size(159, 32);
			this->ViewEnroll->TabIndex = 40;
			this->ViewEnroll->Text = L"View Enrollments";
			this->ViewEnroll->UseVisualStyleBackColor = true;
			this->ViewEnroll->Click += gcnew System::EventHandler(this, &FacultyEnrollmentManagement::ViewEnroll_Click);
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Location = System::Drawing::Point(120, 175);
			this->dateTimePicker3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(703, 22);
			this->dateTimePicker3->TabIndex = 35;
			// 
			// Student_Name
			// 
			this->Student_Name->AutoSize = true;
			this->Student_Name->Location = System::Drawing::Point(9, 20);
			this->Student_Name->Name = L"Student_Name";
			this->Student_Name->Size = System::Drawing::Size(92, 16);
			this->Student_Name->TabIndex = 41;
			this->Student_Name->Text = L"Student Name";
			// 
			// CourseName
			// 
			this->CourseName->AutoSize = true;
			this->CourseName->Location = System::Drawing::Point(9, 63);
			this->CourseName->Name = L"CourseName";
			this->CourseName->Size = System::Drawing::Size(90, 16);
			this->CourseName->TabIndex = 42;
			this->CourseName->Text = L"Course Name";
			// 
			// Department
			// 
			this->Department->AutoSize = true;
			this->Department->Location = System::Drawing::Point(9, 103);
			this->Department->Name = L"Department";
			this->Department->Size = System::Drawing::Size(77, 16);
			this->Department->TabIndex = 43;
			this->Department->Text = L"Department";
			// 
			// EnrollmentDate
			// 
			this->EnrollmentDate->AutoSize = true;
			this->EnrollmentDate->Location = System::Drawing::Point(9, 182);
			this->EnrollmentDate->Name = L"EnrollmentDate";
			this->EnrollmentDate->Size = System::Drawing::Size(99, 16);
			this->EnrollmentDate->TabIndex = 44;
			this->EnrollmentDate->Text = L"EnrollmentDate";
			// 
			// Semester
			// 
			this->Semester->AutoSize = true;
			this->Semester->Location = System::Drawing::Point(9, 145);
			this->Semester->Name = L"Semester";
			this->Semester->Size = System::Drawing::Size(65, 16);
			this->Semester->TabIndex = 45;
			this->Semester->Text = L"Semester";
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(631, 536);
			this->btnCancel->Margin = System::Windows::Forms::Padding(4);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(100, 28);
			this->btnCancel->TabIndex = 46;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &FacultyEnrollmentManagement::btnCancel_Click);
			// 
			// groupBoxDetails
			// 
			this->groupBoxDetails->Controls->Add(this->statusBox1);
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
			this->groupBoxDetails->Location = System::Drawing::Point(21, 268);
			this->groupBoxDetails->Margin = System::Windows::Forms::Padding(4);
			this->groupBoxDetails->Name = L"groupBoxDetails";
			this->groupBoxDetails->Padding = System::Windows::Forms::Padding(4);
			this->groupBoxDetails->Size = System::Drawing::Size(831, 251);
			this->groupBoxDetails->TabIndex = 47;
			this->groupBoxDetails->TabStop = false;
			this->groupBoxDetails->Text = L"Details";
			// 
			// statusBox1
			// 
			this->statusBox1->FormattingEnabled = true;
			this->statusBox1->Location = System::Drawing::Point(109, 223);
			this->statusBox1->Name = L"statusBox1";
			this->statusBox1->Size = System::Drawing::Size(722, 24);
			this->statusBox1->TabIndex = 48;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(9, 231);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(44, 16);
			this->label9->TabIndex = 46;
			this->label9->Text = L"Status";
			// 
			// FacultyEnrollmentManagement
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(885, 576);
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
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FacultyEnrollmentManagement";
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
};
}
