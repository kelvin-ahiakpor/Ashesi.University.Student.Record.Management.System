#pragma once
#include "Student.h"
#include "User.h"

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StudentEnrollmentForm
	/// </summary>
	public ref class StudentEnrollmentForm : public System::Windows::Forms::Form
	{
	public:
		int^ StudentID;
		User^ globalUser;
		Student^ student;

		StudentEnrollmentForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		StudentEnrollmentForm(User^ user)
		{
			if (Student^ s = dynamic_cast<Student^>(user)) {
				this->student = s;
				this->globalUser = s;  // Assigning user to globalUser
				StudentID = student->getStudentID();

			}
			else {
				throw gcnew System::ArgumentException("Unsupported user type.");
			}

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentEnrollmentForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ SearchButton;
	protected:

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;


	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;





#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->SearchButton = (gcnew System::Windows::Forms::Button());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(39, 23);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(590, 22);
			   this->textBox1->TabIndex = 0;
			   // 
			   // SearchButton
			   // 
			   this->SearchButton->Location = System::Drawing::Point(635, 18);
			   this->SearchButton->Name = L"SearchButton";
			   this->SearchButton->Size = System::Drawing::Size(66, 32);
			   this->SearchButton->TabIndex = 1;
			   this->SearchButton->Text = L"Search";
			   this->SearchButton->UseVisualStyleBackColor = true;
			   this->SearchButton->Click += gcnew System::EventHandler(this, &StudentEnrollmentForm::SearchButton_Click);
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Location = System::Drawing::Point(39, 51);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->RowTemplate->Height = 24;
			   this->dataGridView1->Size = System::Drawing::Size(662, 655);
			   this->dataGridView1->TabIndex = 2;
			   this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &StudentEnrollmentForm::dataGridView1_CellClick);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(716, 51);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->ReadOnly = true;
			   this->textBox2->Size = System::Drawing::Size(611, 22);
			   this->textBox2->TabIndex = 3;
			   // 
			   // textBox3
			   // 
			   this->textBox3->Location = System::Drawing::Point(716, 131);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->ReadOnly = true;
			   this->textBox3->Size = System::Drawing::Size(611, 22);
			   this->textBox3->TabIndex = 4;
			   // 
			   // richTextBox1
			   // 
			   this->richTextBox1->Location = System::Drawing::Point(716, 189);
			   this->richTextBox1->Name = L"richTextBox1";
			   this->richTextBox1->ReadOnly = true;
			   this->richTextBox1->Size = System::Drawing::Size(611, 126);
			   this->richTextBox1->TabIndex = 5;
			   this->richTextBox1->Text = L"";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(720, 35);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(90, 16);
			   this->label1->TabIndex = 6;
			   this->label1->Text = L"Course Name";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(720, 112);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(49, 16);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"Credits";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(720, 170);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(75, 16);
			   this->label3->TabIndex = 8;
			   this->label3->Text = L"Description";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(720, 320);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(86, 16);
			   this->label4->TabIndex = 10;
			   this->label4->Text = L"Prerequisites";
			   // 
			   // richTextBox2
			   // 
			   this->richTextBox2->Location = System::Drawing::Point(716, 339);
			   this->richTextBox2->Name = L"richTextBox2";
			   this->richTextBox2->ReadOnly = true;
			   this->richTextBox2->Size = System::Drawing::Size(611, 126);
			   this->richTextBox2->TabIndex = 9;
			   this->richTextBox2->Text = L"";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(714, 480);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(64, 16);
			   this->label6->TabIndex = 14;
			   this->label6->Text = L"Schedule";
			   // 
			   // richTextBox3
			   // 
			   this->richTextBox3->Location = System::Drawing::Point(710, 499);
			   this->richTextBox3->Name = L"richTextBox3";
			   this->richTextBox3->ReadOnly = true;
			   this->richTextBox3->Size = System::Drawing::Size(611, 103);
			   this->richTextBox3->TabIndex = 13;
			   this->richTextBox3->Text = L"";
			   this->richTextBox3->TextChanged += gcnew System::EventHandler(this, &StudentEnrollmentForm::richTextBox3_TextChanged);
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(714, 614);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(63, 16);
			   this->label7->TabIndex = 16;
			   this->label7->Text = L"Capacity ";
			   // 
			   // textBox4
			   // 
			   this->textBox4->Location = System::Drawing::Point(710, 633);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->ReadOnly = true;
			   this->textBox4->Size = System::Drawing::Size(611, 22);
			   this->textBox4->TabIndex = 15;
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(1221, 12);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(100, 32);
			   this->button1->TabIndex = 17;
			   this->button1->Text = L"Enroll";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &StudentEnrollmentForm::button1_Click);
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Location = System::Drawing::Point(36, 4);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(90, 16);
			   this->label8->TabIndex = 20;
			   this->label8->Text = L"Course Name";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Location = System::Drawing::Point(351, 4);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(0, 16);
			   this->label10->TabIndex = 22;
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(714, 665);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(44, 16);
			   this->label5->TabIndex = 24;
			   this->label5->Text = L"Status";
			   // 
			   // textBox5
			   // 
			   this->textBox5->Location = System::Drawing::Point(710, 684);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->ReadOnly = true;
			   this->textBox5->Size = System::Drawing::Size(611, 22);
			   this->textBox5->TabIndex = 23;
			   // 
			   // StudentEnrollmentForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoSize = true;
			   this->ClientSize = System::Drawing::Size(1345, 708);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->textBox5);
			   this->Controls->Add(this->label10);
			   this->Controls->Add(this->label8);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->label7);
			   this->Controls->Add(this->textBox4);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->richTextBox3);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->richTextBox2);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->richTextBox1);
			   this->Controls->Add(this->textBox3);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->SearchButton);
			   this->Controls->Add(this->textBox1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->Name = L"StudentEnrollmentForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"Student Enrollment";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }

private: System::Void richTextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
	

#pragma endregion
}
