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

	private: System::Windows::Forms::Button^ button3;
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
			this->button3 = (gcnew System::Windows::Forms::Button());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(760, 511);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(114, 43);
			this->button3->TabIndex = 39;
			this->button3->Text = L"Save";
			this->button3->UseVisualStyleBackColor = true;
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
			this->textBox5->Location = System::Drawing::Point(161, 382);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(718, 22);
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
			this->textBox4->Location = System::Drawing::Point(161, 424);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(718, 22);
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
			this->textBox2->Location = System::Drawing::Point(161, 330);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(718, 22);
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
			this->textBox1->Location = System::Drawing::Point(161, 279);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(718, 22);
			this->textBox1->TabIndex = 23;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(23, 52);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(830, 210);
			this->dataGridView1->TabIndex = 22;
			// 
			// ViewEnroll
			// 
			this->ViewEnroll->Location = System::Drawing::Point(739, 3);
			this->ViewEnroll->Name = L"ViewEnroll";
			this->ViewEnroll->Size = System::Drawing::Size(114, 43);
			this->ViewEnroll->TabIndex = 40;
			this->ViewEnroll->Text = L"View Enrollements";
			this->ViewEnroll->UseVisualStyleBackColor = true;
			this->ViewEnroll->Click += gcnew System::EventHandler(this, &FacultyEnrollmentManagement::ViewEnroll_Click);
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Location = System::Drawing::Point(161, 471);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(718, 22);
			this->dateTimePicker3->TabIndex = 35;
			// 
			// Student_Name
			// 
			this->Student_Name->AutoSize = true;
			this->Student_Name->Location = System::Drawing::Point(54, 282);
			this->Student_Name->Name = L"Student_Name";
			this->Student_Name->Size = System::Drawing::Size(92, 16);
			this->Student_Name->TabIndex = 41;
			this->Student_Name->Text = L"Student Name";
			// 
			// CourseName
			// 
			this->CourseName->AutoSize = true;
			this->CourseName->Location = System::Drawing::Point(54, 333);
			this->CourseName->Name = L"CourseName";
			this->CourseName->Size = System::Drawing::Size(90, 16);
			this->CourseName->TabIndex = 42;
			this->CourseName->Text = L"Course Name";
			// 
			// Department
			// 
			this->Department->AutoSize = true;
			this->Department->Location = System::Drawing::Point(54, 385);
			this->Department->Name = L"Department";
			this->Department->Size = System::Drawing::Size(77, 16);
			this->Department->TabIndex = 43;
			this->Department->Text = L"Department";
			// 
			// EnrollmentDate
			// 
			this->EnrollmentDate->AutoSize = true;
			this->EnrollmentDate->Location = System::Drawing::Point(45, 476);
			this->EnrollmentDate->Name = L"EnrollmentDate";
			this->EnrollmentDate->Size = System::Drawing::Size(99, 16);
			this->EnrollmentDate->TabIndex = 44;
			this->EnrollmentDate->Text = L"EnrollmentDate";
			// 
			// Semester
			// 
			this->Semester->AutoSize = true;
			this->Semester->Location = System::Drawing::Point(54, 430);
			this->Semester->Name = L"Semester";
			this->Semester->Size = System::Drawing::Size(65, 16);
			this->Semester->TabIndex = 45;
			this->Semester->Text = L"Semester";
			// 
			// FacultyEnrollmentManagement
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(886, 563);
			this->Controls->Add(this->Semester);
			this->Controls->Add(this->EnrollmentDate);
			this->Controls->Add(this->Department);
			this->Controls->Add(this->CourseName);
			this->Controls->Add(this->Student_Name);
			this->Controls->Add(this->ViewEnroll);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dateTimePicker3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"FacultyEnrollmentManagement";
			this->Text = L"FacultyEnrollmentManagement";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void ViewEnroll_Click(System::Object^ sender, System::EventArgs^ e) {};
};
}
