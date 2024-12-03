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
	/// Summary for ManageAvailableCoursesForm
	/// </summary>
	public ref class ManageAvailableCourses : public System::Windows::Forms::Form
	{
	public:
		ManageAvailableCourses(void)
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
		~ManageAvailableCourses()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		// Components Declaration
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Label^ lblCourseID;
		System::Windows::Forms::TextBox^ txtCourseID;
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
		System::Windows::Forms::DataGridView^ dgvCourses;
		System::Windows::Forms::Button^ btnSaveCourse;
		System::Windows::Forms::Button^ btnEditCourse;
		System::Windows::Forms::Button^ btnDeleteCourse;
	private: System::Windows::Forms::DataGridView^ dataGridViewCourse;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ lblFacultyName;







	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ lblSemester;





	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ lblyear;


	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ MaxCapacity;



	private: System::Windows::Forms::Button^ btnViewCourse;
	private: System::Windows::Forms::Label^ lblCourseName;









	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ btnDelete;

	private: System::Windows::Forms::GroupBox^ groupBoxCreateEdit;
	private: System::Windows::Forms::GroupBox^ groupBoxViewCourse;
	private: System::Windows::Forms::Label^ staus;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Button^ btnEdit;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ManageAvailableCourses::typeid));
			this->dataGridViewCourse = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->lblFacultyName = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->lblSemester = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->lblyear = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->MaxCapacity = (gcnew System::Windows::Forms::Label());
			this->btnViewCourse = (gcnew System::Windows::Forms::Button());
			this->lblCourseName = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->groupBoxCreateEdit = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->staus = (gcnew System::Windows::Forms::Label());
			this->groupBoxViewCourse = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCourse))->BeginInit();
			this->groupBoxCreateEdit->SuspendLayout();
			this->groupBoxViewCourse->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridViewCourse
			// 
			this->dataGridViewCourse->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewCourse->Location = System::Drawing::Point(5, 18);
			this->dataGridViewCourse->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridViewCourse->Name = L"dataGridViewCourse";
			this->dataGridViewCourse->RowHeadersWidth = 51;
			this->dataGridViewCourse->RowTemplate->Height = 24;
			this->dataGridViewCourse->Size = System::Drawing::Size(595, 139);
			this->dataGridViewCourse->TabIndex = 0;
			this->dataGridViewCourse->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ManageAvailableCourses::dataGridView1_CellClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(73, 25);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(528, 20);
			this->textBox1->TabIndex = 1;
			// 
			// lblFacultyName
			// 
			this->lblFacultyName->AutoSize = true;
			this->lblFacultyName->Location = System::Drawing::Point(2, 105);
			this->lblFacultyName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblFacultyName->Name = L"lblFacultyName";
			this->lblFacultyName->Size = System::Drawing::Size(72, 13);
			this->lblFacultyName->TabIndex = 18;
			this->lblFacultyName->Text = L"Faculty Name";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(64, 60);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(536, 20);
			this->textBox2->TabIndex = 6;
			// 
			// lblSemester
			// 
			this->lblSemester->AutoSize = true;
			this->lblSemester->Location = System::Drawing::Point(3, 67);
			this->lblSemester->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblSemester->Name = L"lblSemester";
			this->lblSemester->Size = System::Drawing::Size(51, 13);
			this->lblSemester->TabIndex = 7;
			this->lblSemester->Text = L"Semester";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(75, 169);
			this->textBox3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(521, 20);
			this->textBox3->TabIndex = 10;
			// 
			// lblyear
			// 
			this->lblyear->AutoSize = true;
			this->lblyear->Location = System::Drawing::Point(2, 143);
			this->lblyear->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblyear->Name = L"lblyear";
			this->lblyear->Size = System::Drawing::Size(29, 13);
			this->lblyear->TabIndex = 11;
			this->lblyear->Text = L"Year";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(38, 136);
			this->textBox4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(558, 20);
			this->textBox4->TabIndex = 12;
			// 
			// MaxCapacity
			// 
			this->MaxCapacity->AutoSize = true;
			this->MaxCapacity->Location = System::Drawing::Point(3, 174);
			this->MaxCapacity->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MaxCapacity->Name = L"MaxCapacity";
			this->MaxCapacity->Size = System::Drawing::Size(68, 13);
			this->MaxCapacity->TabIndex = 13;
			this->MaxCapacity->Text = L"MaxCapacity";
			// 
			// btnViewCourse
			// 
			this->btnViewCourse->Location = System::Drawing::Point(514, 11);
			this->btnViewCourse->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnViewCourse->Name = L"btnViewCourse";
			this->btnViewCourse->Size = System::Drawing::Size(91, 28);
			this->btnViewCourse->TabIndex = 14;
			this->btnViewCourse->Text = L"View Courses";
			this->btnViewCourse->UseVisualStyleBackColor = true;
			this->btnViewCourse->Click += gcnew System::EventHandler(this, &ManageAvailableCourses::btnviewcourses_Click);
			// 
			// lblCourseName
			// 
			this->lblCourseName->AutoSize = true;
			this->lblCourseName->Location = System::Drawing::Point(3, 25);
			this->lblCourseName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblCourseName->Name = L"lblCourseName";
			this->lblCourseName->Size = System::Drawing::Size(68, 13);
			this->lblCourseName->TabIndex = 4;
			this->lblCourseName->Text = L"CourseName";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(335, 238);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 27);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Save Course";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ManageAvailableCourses::savecourses_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(425, 238);
			this->btnDelete->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(86, 27);
			this->btnDelete->TabIndex = 20;
			this->btnDelete->Text = L"Delete Course";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &ManageAvailableCourses::btnDelete_Click);
			// 
			// btnEdit
			// 
			this->btnEdit->Location = System::Drawing::Point(515, 238);
			this->btnEdit->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(86, 27);
			this->btnEdit->TabIndex = 21;
			this->btnEdit->Text = L"Edit Course";
			this->btnEdit->UseVisualStyleBackColor = true;
			this->btnEdit->Click += gcnew System::EventHandler(this, &ManageAvailableCourses::btnEdit_Click);
			// 
			// groupBoxCreateEdit
			// 
			this->groupBoxCreateEdit->Controls->Add(this->comboBox3);
			this->groupBoxCreateEdit->Controls->Add(this->comboBox2);
			this->groupBoxCreateEdit->Controls->Add(this->staus);
			this->groupBoxCreateEdit->Controls->Add(this->btnEdit);
			this->groupBoxCreateEdit->Controls->Add(this->btnDelete);
			this->groupBoxCreateEdit->Controls->Add(this->textBox1);
			this->groupBoxCreateEdit->Controls->Add(this->button3);
			this->groupBoxCreateEdit->Controls->Add(this->lblFacultyName);
			this->groupBoxCreateEdit->Controls->Add(this->lblCourseName);
			this->groupBoxCreateEdit->Controls->Add(this->textBox2);
			this->groupBoxCreateEdit->Controls->Add(this->lblSemester);
			this->groupBoxCreateEdit->Controls->Add(this->MaxCapacity);
			this->groupBoxCreateEdit->Controls->Add(this->textBox4);
			this->groupBoxCreateEdit->Controls->Add(this->textBox3);
			this->groupBoxCreateEdit->Controls->Add(this->lblyear);
			this->groupBoxCreateEdit->Location = System::Drawing::Point(9, 212);
			this->groupBoxCreateEdit->Name = L"groupBoxCreateEdit";
			this->groupBoxCreateEdit->Size = System::Drawing::Size(606, 270);
			this->groupBoxCreateEdit->TabIndex = 22;
			this->groupBoxCreateEdit->TabStop = false;
			this->groupBoxCreateEdit->Text = L"Create / Edit";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(64, 206);
			this->comboBox3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(532, 21);
			this->comboBox3->TabIndex = 27;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(73, 102);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(524, 21);
			this->comboBox2->TabIndex = 26;
			// 
			// staus
			// 
			this->staus->AutoSize = true;
			this->staus->Location = System::Drawing::Point(7, 213);
			this->staus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->staus->Name = L"staus";
			this->staus->Size = System::Drawing::Size(37, 13);
			this->staus->TabIndex = 23;
			this->staus->Text = L"Status";
			// 
			// groupBoxViewCourse
			// 
			this->groupBoxViewCourse->Controls->Add(this->dataGridViewCourse);
			this->groupBoxViewCourse->Location = System::Drawing::Point(9, 44);
			this->groupBoxViewCourse->Name = L"groupBoxViewCourse";
			this->groupBoxViewCourse->Size = System::Drawing::Size(601, 162);
			this->groupBoxViewCourse->TabIndex = 23;
			this->groupBoxViewCourse->TabStop = false;
			this->groupBoxViewCourse->Text = L"View";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(332, 19);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 15);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Department";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(418, 16);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(92, 21);
			this->comboBox1->TabIndex = 25;
			// 
			// ManageAvailableCourses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 489);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnViewCourse);
			this->Controls->Add(this->groupBoxCreateEdit);
			this->Controls->Add(this->groupBoxViewCourse);
			this->ForeColor = System::Drawing::Color::Maroon;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"ManageAvailableCourses";
			this->Text = L"Manage Available Courses";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCourse))->EndInit();
			this->groupBoxCreateEdit->ResumeLayout(false);
			this->groupBoxCreateEdit->PerformLayout();
			this->groupBoxViewCourse->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void savecourses_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnviewcourses_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	};
}
