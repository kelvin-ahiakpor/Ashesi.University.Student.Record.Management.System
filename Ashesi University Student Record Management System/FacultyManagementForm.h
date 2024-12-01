#pragma once

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FacultyManagementForm
	/// </summary>
	public ref class FacultyManagementForm : public System::Windows::Forms::Form
	{
	public:
		FacultyManagementForm(void)
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
		~FacultyManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		// Components Declaration
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Label^ lblFacultyID;
		System::Windows::Forms::TextBox^ txtFacultyID;
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
		System::Windows::Forms::DataGridView^ dgvFacultys;
		System::Windows::Forms::Button^ btnSaveFaculty;
		System::Windows::Forms::Button^ btnEditFaculty;
		System::Windows::Forms::Button^ btnDeleteFaculty;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 53);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(830, 210);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FacultyManagementForm::dataGridView1_CellClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(124, 275);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(718, 22);
			this->textBox1->TabIndex = 1;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(139, 504);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(718, 22);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 275);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"First Name";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(634, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 35);
			this->button1->TabIndex = 5;
			this->button1->Text = L"View Faculty Users";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(124, 326);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(718, 22);
			this->textBox2->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 329);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Last Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 510);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(124, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"DateOfAppointment";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(149, 458);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(718, 22);
			this->textBox3->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 420);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Email";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(124, 420);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(718, 22);
			this->textBox4->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(26, 464);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(117, 16);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Department Name";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(420, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(208, 35);
			this->button2->TabIndex = 14;
			this->button2->Text = L"View Facultys";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button2_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(124, 378);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(718, 22);
			this->textBox5->TabIndex = 17;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(31, 381);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(63, 16);
			this->label8->TabIndex = 18;
			this->label8->Text = L"FacultyID";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(435, 550);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(114, 43);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Create Faculty";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(555, 550);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(114, 43);
			this->button4->TabIndex = 20;
			this->button4->Text = L"Delete Faculty";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(692, 550);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(114, 43);
			this->button5->TabIndex = 21;
			this->button5->Text = L"Edit Faculty Info";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button5_Click);
			// 
			// FacultyManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(854, 652);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"FacultyManagementForm";
			this->Text = L"FacultyManagementForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	};
}

