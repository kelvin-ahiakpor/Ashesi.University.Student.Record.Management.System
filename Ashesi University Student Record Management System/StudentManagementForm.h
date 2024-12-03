#pragma once
#include "DatabaseManager.h"

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StudentManagementForm
	/// </summary>
	public ref class StudentManagementForm : public System::Windows::Forms::Form
	{
	public:
		StudentManagementForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		// Components Declaration
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Label^ lblStudentID;
		System::Windows::Forms::TextBox^ txtStudentID;
		System::Windows::Forms::Label^ lblUserID;
		System::Windows::Forms::TextBox^ txtUserID;
		System::Windows::Forms::Label^ lblDateOfBirth;
		System::Windows::Forms::DateTimePicker^ dtpDateOfBirth;
		System::Windows::Forms::Label^ lblDepartmentID;
		System::Windows::Forms::ComboBox^ cmbDepartmentID;
		System::Windows::Forms::Label^ lblEnrollmentDate;
		System::Windows::Forms::DateTimePicker^ dtpEnrollmentDate;
		System::Windows::Forms::Label^ lblProfilePicture;
		System::Windows::Forms::Button^ btnUploadProfilePicture;
		System::Windows::Forms::Label^ lblExpectedGraduation;
		System::Windows::Forms::DateTimePicker^ dtpExpectedGraduation;
		System::Windows::Forms::Label^ lblStatus;
		System::Windows::Forms::ComboBox^ cmbStatus;
		System::Windows::Forms::DataGridView^ dgvStudents;
		System::Windows::Forms::Button^ btnSaveStudent;
		System::Windows::Forms::Button^ btnEditStudent;
		System::Windows::Forms::Button^ btnDeleteStudent;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker3;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ btnCreateStudent;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::GroupBox^ groupBoxActions;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::Button^ button5;


	private:
		/// <summary>
		/// Required designer variable.

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StudentManagementForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnCreateStudent = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBoxActions = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBoxActions->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(14, 44);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(624, 171);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &StudentManagementForm::dataGridView1_CellClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(78, 23);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(540, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &StudentManagementForm::textBox1_TextChanged);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(91, 253);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(527, 20);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(80, 205);
			this->dateTimePicker2->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(538, 20);
			this->dateTimePicker2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 26);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"First Name";
			this->label1->Click += gcnew System::EventHandler(this, &StudentManagementForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(530, 13);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 27);
			this->button1->TabIndex = 5;
			this->button1->Text = L"View Student Users";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StudentManagementForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(78, 65);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(540, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &StudentManagementForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 68);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Last Name";
			this->label2->Click += gcnew System::EventHandler(this, &StudentManagementForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 212);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Date Of Birth";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(5, 258);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Enrollment Date";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(110, 172);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(508, 20);
			this->textBox3->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(5, 144);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Email";
			this->label5->Click += gcnew System::EventHandler(this, &StudentManagementForm::label5_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(78, 141);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(540, 20);
			this->textBox4->TabIndex = 12;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &StudentManagementForm::textBox4_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(5, 175);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(93, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Department Name";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(440, 13);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 27);
			this->button2->TabIndex = 14;
			this->button2->Text = L"View Students";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &StudentManagementForm::button2_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(5, 303);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(133, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Expected Graduation Date";
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Location = System::Drawing::Point(142, 297);
			this->dateTimePicker3->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(476, 20);
			this->dateTimePicker3->TabIndex = 15;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(77, 103);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(540, 20);
			this->textBox5->TabIndex = 17;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &StudentManagementForm::textBox5_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(5, 106);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"StudentID";
			this->label8->Click += gcnew System::EventHandler(this, &StudentManagementForm::label8_Click);
			// 
			// btnCreateStudent
			// 
			this->btnCreateStudent->Location = System::Drawing::Point(328, 7);
			this->btnCreateStudent->Margin = System::Windows::Forms::Padding(2);
			this->btnCreateStudent->Name = L"btnCreateStudent";
			this->btnCreateStudent->Size = System::Drawing::Size(86, 26);
			this->btnCreateStudent->TabIndex = 19;
			this->btnCreateStudent->Text = L"Create Student";
			this->btnCreateStudent->UseVisualStyleBackColor = true;
			this->btnCreateStudent->Click += gcnew System::EventHandler(this, &StudentManagementForm::btnCreateStudent_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(418, 7);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(86, 26);
			this->button4->TabIndex = 20;
			this->button4->Text = L"Delete Student";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &StudentManagementForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(508, 7);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(94, 26);
			this->button5->TabIndex = 21;
			this->button5->Text = L"Edit Student Info";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &StudentManagementForm::button5_Click);
			// 
			// groupBoxActions
			// 
			this->groupBoxActions->Controls->Add(this->button5);
			this->groupBoxActions->Controls->Add(this->btnCreateStudent);
			this->groupBoxActions->Controls->Add(this->button4);
			this->groupBoxActions->Location = System::Drawing::Point(14, 554);
			this->groupBoxActions->Name = L"groupBoxActions";
			this->groupBoxActions->Size = System::Drawing::Size(624, 35);
			this->groupBoxActions->TabIndex = 22;
			this->groupBoxActions->TabStop = false;
			this->groupBoxActions->Text = L"Actions";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->dateTimePicker1);
			this->groupBox1->Controls->Add(this->dateTimePicker3);
			this->groupBox1->Controls->Add(this->dateTimePicker2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(16, 220);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(622, 328);
			this->groupBox1->TabIndex = 23;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Details";
			// 
			// StudentManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(654, 601);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBoxActions);
			this->Controls->Add(this->groupBox1);
			this->ForeColor = System::Drawing::Color::Maroon;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"StudentManagementForm";
			this->Text = L"StudentManagementForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBoxActions->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void btnCreateStudent_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

	   private: System::Void LoadStudents(DatabaseManager^ db);
};
}
