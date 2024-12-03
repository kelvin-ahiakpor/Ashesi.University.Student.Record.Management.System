#pragma once
#include "Student.h"
#include "User.h"
#include "Course.h"
#include "DatabaseManager.h"

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
		List<Course^>^ cachedCourses = gcnew List<Course^>();
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

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ courseIdbox;
		   Student^ student;

		

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
	private: System::Windows::Forms::TextBox^ txtBoxSearch;
	protected:

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
	private: System::Windows::Forms::Button^ btnEnroll;



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
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StudentEnrollmentForm::typeid));
			   this->txtBoxSearch = (gcnew System::Windows::Forms::TextBox());
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
			   this->btnEnroll = (gcnew System::Windows::Forms::Button());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->courseIdbox = (gcnew System::Windows::Forms::TextBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // txtBoxSearch
			   // 
			   this->txtBoxSearch->Location = System::Drawing::Point(11, 24);
			   this->txtBoxSearch->Margin = System::Windows::Forms::Padding(2);
			   this->txtBoxSearch->Name = L"txtBoxSearch";
			   this->txtBoxSearch->Size = System::Drawing::Size(350, 20);
			   this->txtBoxSearch->TabIndex = 0;
			   this->txtBoxSearch->TextChanged += gcnew System::EventHandler(this, &StudentEnrollmentForm::txtBoxSearch_TextChanged);
			   // 
			   // SearchButton
			   // 
			   this->SearchButton->Location = System::Drawing::Point(420, 22);
			   this->SearchButton->Margin = System::Windows::Forms::Padding(2);
			   this->SearchButton->Name = L"SearchButton";
			   this->SearchButton->Size = System::Drawing::Size(87, 23);
			   this->SearchButton->TabIndex = 1;
			   this->SearchButton->Text = L"Search";
			   this->SearchButton->UseVisualStyleBackColor = true;
			   this->SearchButton->Click += gcnew System::EventHandler(this, &StudentEnrollmentForm::SearchButton_Click);
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Location = System::Drawing::Point(11, 48);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->RowTemplate->Height = 24;
			   this->dataGridView1->Size = System::Drawing::Size(496, 552);
			   this->dataGridView1->TabIndex = 2;
			   this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &StudentEnrollmentForm::dataGridView1_CellClick);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(528, 63);
			   this->textBox2->Margin = System::Windows::Forms::Padding(2);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->ReadOnly = true;
			   this->textBox2->Size = System::Drawing::Size(454, 20);
			   this->textBox2->TabIndex = 3;
			   // 
			   // textBox3
			   // 
			   this->textBox3->Location = System::Drawing::Point(530, 141);
			   this->textBox3->Margin = System::Windows::Forms::Padding(2);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->ReadOnly = true;
			   this->textBox3->Size = System::Drawing::Size(454, 20);
			   this->textBox3->TabIndex = 4;
			   // 
			   // richTextBox1
			   // 
			   this->richTextBox1->Location = System::Drawing::Point(530, 188);
			   this->richTextBox1->Margin = System::Windows::Forms::Padding(2);
			   this->richTextBox1->Name = L"richTextBox1";
			   this->richTextBox1->ReadOnly = true;
			   this->richTextBox1->Size = System::Drawing::Size(454, 84);
			   this->richTextBox1->TabIndex = 5;
			   this->richTextBox1->Text = L"";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(527, 48);
			   this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(71, 13);
			   this->label1->TabIndex = 6;
			   this->label1->Text = L"Course Name";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(525, 125);
			   this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(39, 13);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"Credits";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(525, 173);
			   this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(60, 13);
			   this->label3->TabIndex = 8;
			   this->label3->Text = L"Description";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(525, 284);
			   this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(67, 13);
			   this->label4->TabIndex = 10;
			   this->label4->Text = L"Prerequisites";
			   // 
			   // richTextBox2
			   // 
			   this->richTextBox2->Location = System::Drawing::Point(530, 299);
			   this->richTextBox2->Margin = System::Windows::Forms::Padding(2);
			   this->richTextBox2->Name = L"richTextBox2";
			   this->richTextBox2->ReadOnly = true;
			   this->richTextBox2->Size = System::Drawing::Size(454, 84);
			   this->richTextBox2->TabIndex = 9;
			   this->richTextBox2->Text = L"";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(526, 397);
			   this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(52, 13);
			   this->label6->TabIndex = 14;
			   this->label6->Text = L"Schedule";
			   // 
			   // richTextBox3
			   // 
			   this->richTextBox3->Location = System::Drawing::Point(530, 413);
			   this->richTextBox3->Margin = System::Windows::Forms::Padding(2);
			   this->richTextBox3->Name = L"richTextBox3";
			   this->richTextBox3->ReadOnly = true;
			   this->richTextBox3->Size = System::Drawing::Size(459, 84);
			   this->richTextBox3->TabIndex = 13;
			   this->richTextBox3->Text = L"";
			   this->richTextBox3->TextChanged += gcnew System::EventHandler(this, &StudentEnrollmentForm::richTextBox3_TextChanged);
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(526, 510);
			   this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(51, 13);
			   this->label7->TabIndex = 16;
			   this->label7->Text = L"Capacity ";
			   // 
			   // textBox4
			   // 
			   this->textBox4->Location = System::Drawing::Point(530, 526);
			   this->textBox4->Margin = System::Windows::Forms::Padding(2);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->ReadOnly = true;
			   this->textBox4->Size = System::Drawing::Size(459, 20);
			   this->textBox4->TabIndex = 15;
			   // 
			   // btnEnroll
			   // 
			   this->btnEnroll->Location = System::Drawing::Point(916, 24);
			   this->btnEnroll->Margin = System::Windows::Forms::Padding(2);
			   this->btnEnroll->Name = L"btnEnroll";
			   this->btnEnroll->Size = System::Drawing::Size(75, 23);
			   this->btnEnroll->TabIndex = 17;
			   this->btnEnroll->Text = L"Enroll";
			   this->btnEnroll->UseVisualStyleBackColor = true;
			   this->btnEnroll->Click += gcnew System::EventHandler(this, &StudentEnrollmentForm::btnEnrollClick);
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Location = System::Drawing::Point(11, 9);
			   this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(71, 13);
			   this->label8->TabIndex = 20;
			   this->label8->Text = L"Course Name";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Location = System::Drawing::Point(263, 3);
			   this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(0, 13);
			   this->label10->TabIndex = 22;
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(525, 566);
			   this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(37, 13);
			   this->label5->TabIndex = 24;
			   this->label5->Text = L"Status";
			   // 
			   // textBox5
			   // 
			   this->textBox5->Location = System::Drawing::Point(530, 580);
			   this->textBox5->Margin = System::Windows::Forms::Padding(2);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->ReadOnly = true;
			   this->textBox5->Size = System::Drawing::Size(459, 20);
			   this->textBox5->TabIndex = 23;
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Location = System::Drawing::Point(525, 91);
			   this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(51, 13);
			   this->label9->TabIndex = 26;
			   this->label9->Text = L"CourseID";
			   // 
			   // courseIdbox
			   // 
			   this->courseIdbox->Location = System::Drawing::Point(530, 106);
			   this->courseIdbox->Margin = System::Windows::Forms::Padding(2);
			   this->courseIdbox->Name = L"courseIdbox";
			   this->courseIdbox->ReadOnly = true;
			   this->courseIdbox->Size = System::Drawing::Size(454, 20);
			   this->courseIdbox->TabIndex = 25;
			   // 
			   // StudentEnrollmentForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoSize = true;
			   this->ClientSize = System::Drawing::Size(1002, 612);
			   this->Controls->Add(this->label9);
			   this->Controls->Add(this->courseIdbox);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->textBox5);
			   this->Controls->Add(this->label10);
			   this->Controls->Add(this->label8);
			   this->Controls->Add(this->btnEnroll);
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
			   this->Controls->Add(this->txtBoxSearch);
			   this->ForeColor = System::Drawing::Color::Maroon;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"StudentEnrollmentForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Student Enrollment";
			   this->Load += gcnew System::EventHandler(this, &StudentEnrollmentForm::StudentEnrollmentForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }

private: System::Void richTextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void btnEnrollClick(System::Object^ sender, System::EventArgs^ e);
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtBoxSearch_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void SearchCourses(DatabaseManager^ db, System::Object^ sender, System::EventArgs^ e);
private: System::Void EnrollStudent(DatabaseManager^ db, System::Object^ sender, System::EventArgs^ e);
private: System::Void LoadCoursesToCache();
private: System::Void StudentEnrollmentForm_Load(System::Object^ sender, System::EventArgs^ e);
};
	

#pragma endregion
}
