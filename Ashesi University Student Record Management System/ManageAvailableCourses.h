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
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->staus = (gcnew System::Windows::Forms::Label());
			this->groupBoxViewCourse = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCourse))->BeginInit();
			this->groupBoxCreateEdit->SuspendLayout();
			this->groupBoxViewCourse->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridViewCourse
			// 
			this->dataGridViewCourse->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewCourse->Location = System::Drawing::Point(7, 22);
			this->dataGridViewCourse->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridViewCourse->Name = L"dataGridViewCourse";
			this->dataGridViewCourse->RowHeadersWidth = 51;
			this->dataGridViewCourse->RowTemplate->Height = 24;
			this->dataGridViewCourse->Size = System::Drawing::Size(793, 171);
			this->dataGridViewCourse->TabIndex = 0;
			this->dataGridViewCourse->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ManageAvailableCourses::dataGridView1_CellClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(97, 31);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(703, 22);
			this->textBox1->TabIndex = 1;
			// 
			// lblFacultyName
			// 
			this->lblFacultyName->AutoSize = true;
			this->lblFacultyName->Location = System::Drawing::Point(3, 129);
			this->lblFacultyName->Name = L"lblFacultyName";
			this->lblFacultyName->Size = System::Drawing::Size(90, 16);
			this->lblFacultyName->TabIndex = 18;
			this->lblFacultyName->Text = L"Faculty Name";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(85, 74);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(715, 22);
			this->textBox2->TabIndex = 6;
			// 
			// lblSemester
			// 
			this->lblSemester->AutoSize = true;
			this->lblSemester->Location = System::Drawing::Point(4, 82);
			this->lblSemester->Name = L"lblSemester";
			this->lblSemester->Size = System::Drawing::Size(65, 16);
			this->lblSemester->TabIndex = 7;
			this->lblSemester->Text = L"Semester";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(85, 208);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(715, 22);
			this->textBox3->TabIndex = 10;
			// 
			// lblyear
			// 
			this->lblyear->AutoSize = true;
			this->lblyear->Location = System::Drawing::Point(3, 176);
			this->lblyear->Name = L"lblyear";
			this->lblyear->Size = System::Drawing::Size(36, 16);
			this->lblyear->TabIndex = 11;
			this->lblyear->Text = L"Year";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(51, 167);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(749, 22);
			this->textBox4->TabIndex = 12;
			// 
			// MaxCapacity
			// 
			this->MaxCapacity->AutoSize = true;
			this->MaxCapacity->Location = System::Drawing::Point(4, 214);
			this->MaxCapacity->Name = L"MaxCapacity";
			this->MaxCapacity->Size = System::Drawing::Size(85, 16);
			this->MaxCapacity->TabIndex = 13;
			this->MaxCapacity->Text = L"MaxCapacity";
			// 
			// btnViewCourse
			// 
			this->btnViewCourse->Location = System::Drawing::Point(685, 14);
			this->btnViewCourse->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnViewCourse->Name = L"btnViewCourse";
			this->btnViewCourse->Size = System::Drawing::Size(121, 34);
			this->btnViewCourse->TabIndex = 14;
			this->btnViewCourse->Text = L"View Courses";
			this->btnViewCourse->UseVisualStyleBackColor = true;
			this->btnViewCourse->Click += gcnew System::EventHandler(this, &ManageAvailableCourses::btnviewcourses_Click);
			// 
			// lblCourseName
			// 
			this->lblCourseName->AutoSize = true;
			this->lblCourseName->Location = System::Drawing::Point(4, 31);
			this->lblCourseName->Name = L"lblCourseName";
			this->lblCourseName->Size = System::Drawing::Size(87, 16);
			this->lblCourseName->TabIndex = 4;
			this->lblCourseName->Text = L"CourseName";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(447, 293);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(115, 33);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Save Course";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ManageAvailableCourses::savecourses_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(567, 293);
			this->btnDelete->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(115, 33);
			this->btnDelete->TabIndex = 20;
			this->btnDelete->Text = L"Delete Course";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &ManageAvailableCourses::btnDelete_Click);
			// 
			// btnEdit
			// 
			this->btnEdit->Location = System::Drawing::Point(687, 293);
			this->btnEdit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(115, 33);
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
			this->groupBoxCreateEdit->Location = System::Drawing::Point(12, 261);
			this->groupBoxCreateEdit->Margin = System::Windows::Forms::Padding(4);
			this->groupBoxCreateEdit->Name = L"groupBoxCreateEdit";
			this->groupBoxCreateEdit->Padding = System::Windows::Forms::Padding(4);
			this->groupBoxCreateEdit->Size = System::Drawing::Size(808, 332);
			this->groupBoxCreateEdit->TabIndex = 22;
			this->groupBoxCreateEdit->TabStop = false;
			this->groupBoxCreateEdit->Text = L"Create / Edit";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(97, 126);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(697, 24);
			this->comboBox2->TabIndex = 26;
			// 
			// staus
			// 
			this->staus->AutoSize = true;
			this->staus->Location = System::Drawing::Point(9, 262);
			this->staus->Name = L"staus";
			this->staus->Size = System::Drawing::Size(44, 16);
			this->staus->TabIndex = 23;
			this->staus->Text = L"Status";
			// 
			// groupBoxViewCourse
			// 
			this->groupBoxViewCourse->Controls->Add(this->dataGridViewCourse);
			this->groupBoxViewCourse->Location = System::Drawing::Point(12, 54);
			this->groupBoxViewCourse->Margin = System::Windows::Forms::Padding(4);
			this->groupBoxViewCourse->Name = L"groupBoxViewCourse";
			this->groupBoxViewCourse->Padding = System::Windows::Forms::Padding(4);
			this->groupBoxViewCourse->Size = System::Drawing::Size(801, 199);
			this->groupBoxViewCourse->TabIndex = 23;
			this->groupBoxViewCourse->TabStop = false;
			this->groupBoxViewCourse->Text = L"View";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 16);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Select Department";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(24, 24);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 25;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(85, 254);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(697, 24);
			this->comboBox3->TabIndex = 27;
			// 
			// ManageAvailableCoursesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(829, 602);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnViewCourse);
			this->Controls->Add(this->groupBoxCreateEdit);
			this->Controls->Add(this->groupBoxViewCourse);
			this->ForeColor = System::Drawing::Color::Maroon;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"ManageAvailableCoursesForm";
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
	private: System::Void LoadCourses(DatabaseManager^ db);
private: System::Void LoadCourseCell(DatabaseManager^ db, DataGridViewCellEventArgs^ e);
	private: System::Void UpdateCourse(DatabaseManager^ db, Object^ sender, EventArgs^ e);
	private: System::Void DeleteCourse(DatabaseManager^ db, Object^ sender, EventArgs^ e);
	private: System::Void CreateCourse(DatabaseManager^ db, Object^ sender, EventArgs^ e);
	};
}
