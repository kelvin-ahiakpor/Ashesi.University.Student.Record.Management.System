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
	private: System::Windows::Forms::DataGridView^ dataGridViewFaculty;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ lblFirstName;




	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ lblLastName;
	private: System::Windows::Forms::Label^ lblDateOfAppointment;



	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ lblEmail;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ lblDepartmentName;

	private: System::Windows::Forms::Button^ btnViewFaculty;



	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ lblFaculty;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::GroupBox^ groupBoxCreateEdit;
	private: System::Windows::Forms::GroupBox^ groupBoxViewFaculty;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FacultyManagementForm::typeid));
			this->dataGridViewFaculty = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblFirstName = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->lblLastName = (gcnew System::Windows::Forms::Label());
			this->lblDateOfAppointment = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->lblDepartmentName = (gcnew System::Windows::Forms::Label());
			this->btnViewFaculty = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->lblFaculty = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBoxCreateEdit = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxViewFaculty = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewFaculty))->BeginInit();
			this->groupBoxCreateEdit->SuspendLayout();
			this->groupBoxViewFaculty->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridViewFaculty
			// 
			this->dataGridViewFaculty->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewFaculty->Location = System::Drawing::Point(5, 18);
			this->dataGridViewFaculty->Margin = System::Windows::Forms::Padding(2);
			this->dataGridViewFaculty->Name = L"dataGridViewFaculty";
			this->dataGridViewFaculty->RowHeadersWidth = 51;
			this->dataGridViewFaculty->RowTemplate->Height = 24;
			this->dataGridViewFaculty->Size = System::Drawing::Size(595, 139);
			this->dataGridViewFaculty->TabIndex = 0;
			this->dataGridViewFaculty->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FacultyManagementForm::dataGridView1_CellClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(64, 18);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(537, 20);
			this->textBox1->TabIndex = 1;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(107, 205);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(494, 20);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// lblFirstName
			// 
			this->lblFirstName->AutoSize = true;
			this->lblFirstName->Location = System::Drawing::Point(3, 25);
			this->lblFirstName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblFirstName->Name = L"lblFirstName";
			this->lblFirstName->Size = System::Drawing::Size(57, 13);
			this->lblFirstName->TabIndex = 4;
			this->lblFirstName->Text = L"First Name";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(64, 60);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(537, 20);
			this->textBox2->TabIndex = 6;
			// 
			// lblLastName
			// 
			this->lblLastName->AutoSize = true;
			this->lblLastName->Location = System::Drawing::Point(3, 67);
			this->lblLastName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblLastName->Name = L"lblLastName";
			this->lblLastName->Size = System::Drawing::Size(58, 13);
			this->lblLastName->TabIndex = 7;
			this->lblLastName->Text = L"Last Name";
			// 
			// lblDateOfAppointment
			// 
			this->lblDateOfAppointment->AutoSize = true;
			this->lblDateOfAppointment->Location = System::Drawing::Point(3, 175);
			this->lblDateOfAppointment->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblDateOfAppointment->Name = L"lblDateOfAppointment";
			this->lblDateOfAppointment->Size = System::Drawing::Size(92, 13);
			this->lblDateOfAppointment->TabIndex = 9;
			this->lblDateOfAppointment->Text = L"Appointment Date";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(107, 172);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(494, 20);
			this->textBox3->TabIndex = 10;
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Location = System::Drawing::Point(2, 143);
			this->lblEmail->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(32, 13);
			this->lblEmail->TabIndex = 11;
			this->lblEmail->Text = L"Email";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(38, 136);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(563, 20);
			this->textBox4->TabIndex = 12;
			// 
			// lblDepartmentName
			// 
			this->lblDepartmentName->AutoSize = true;
			this->lblDepartmentName->Location = System::Drawing::Point(3, 211);
			this->lblDepartmentName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblDepartmentName->Name = L"lblDepartmentName";
			this->lblDepartmentName->Size = System::Drawing::Size(93, 13);
			this->lblDepartmentName->TabIndex = 13;
			this->lblDepartmentName->Text = L"Department Name";
			// 
			// btnViewFaculty
			// 
			this->btnViewFaculty->Location = System::Drawing::Point(519, 11);
			this->btnViewFaculty->Margin = System::Windows::Forms::Padding(2);
			this->btnViewFaculty->Name = L"btnViewFaculty";
			this->btnViewFaculty->Size = System::Drawing::Size(91, 28);
			this->btnViewFaculty->TabIndex = 14;
			this->btnViewFaculty->Text = L"View Faculty";
			this->btnViewFaculty->UseVisualStyleBackColor = true;
			this->btnViewFaculty->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button2_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(58, 102);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(543, 20);
			this->textBox5->TabIndex = 17;
			// 
			// lblFaculty
			// 
			this->lblFaculty->AutoSize = true;
			this->lblFaculty->Location = System::Drawing::Point(2, 105);
			this->lblFaculty->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblFaculty->Name = L"lblFaculty";
			this->lblFaculty->Size = System::Drawing::Size(52, 13);
			this->lblFaculty->TabIndex = 18;
			this->lblFaculty->Text = L"FacultyID";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(335, 238);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 27);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Create Faculty";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(425, 238);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(86, 27);
			this->button4->TabIndex = 20;
			this->button4->Text = L"Delete Faculty";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(515, 238);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(86, 27);
			this->button5->TabIndex = 21;
			this->button5->Text = L"Edit Faculty";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &FacultyManagementForm::button5_Click);
			// 
			// groupBoxCreateEdit
			// 
			this->groupBoxCreateEdit->Controls->Add(this->button5);
			this->groupBoxCreateEdit->Controls->Add(this->button4);
			this->groupBoxCreateEdit->Controls->Add(this->textBox1);
			this->groupBoxCreateEdit->Controls->Add(this->button3);
			this->groupBoxCreateEdit->Controls->Add(this->dateTimePicker1);
			this->groupBoxCreateEdit->Controls->Add(this->lblFaculty);
			this->groupBoxCreateEdit->Controls->Add(this->lblFirstName);
			this->groupBoxCreateEdit->Controls->Add(this->textBox5);
			this->groupBoxCreateEdit->Controls->Add(this->textBox2);
			this->groupBoxCreateEdit->Controls->Add(this->lblLastName);
			this->groupBoxCreateEdit->Controls->Add(this->lblDepartmentName);
			this->groupBoxCreateEdit->Controls->Add(this->lblDateOfAppointment);
			this->groupBoxCreateEdit->Controls->Add(this->textBox4);
			this->groupBoxCreateEdit->Controls->Add(this->textBox3);
			this->groupBoxCreateEdit->Controls->Add(this->lblEmail);
			this->groupBoxCreateEdit->Location = System::Drawing::Point(9, 212);
			this->groupBoxCreateEdit->Name = L"groupBoxCreateEdit";
			this->groupBoxCreateEdit->Size = System::Drawing::Size(606, 270);
			this->groupBoxCreateEdit->TabIndex = 22;
			this->groupBoxCreateEdit->TabStop = false;
			this->groupBoxCreateEdit->Text = L"Create / Edit";
			// 
			// groupBoxViewFaculty
			// 
			this->groupBoxViewFaculty->Controls->Add(this->dataGridViewFaculty);
			this->groupBoxViewFaculty->Location = System::Drawing::Point(9, 44);
			this->groupBoxViewFaculty->Name = L"groupBoxViewFaculty";
			this->groupBoxViewFaculty->Size = System::Drawing::Size(601, 162);
			this->groupBoxViewFaculty->TabIndex = 23;
			this->groupBoxViewFaculty->TabStop = false;
			this->groupBoxViewFaculty->Text = L"View";
			// 
			// FacultyManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 489);
			this->Controls->Add(this->btnViewFaculty);
			this->Controls->Add(this->groupBoxCreateEdit);
			this->Controls->Add(this->groupBoxViewFaculty);
			this->ForeColor = System::Drawing::Color::Maroon;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FacultyManagementForm";
			this->Text = L"Manage Faculty";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewFaculty))->EndInit();
			this->groupBoxCreateEdit->ResumeLayout(false);
			this->groupBoxCreateEdit->PerformLayout();
			this->groupBoxViewFaculty->ResumeLayout(false);
			this->ResumeLayout(false);

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

