#pragma once

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CourseManagementForm
	/// </summary>
	public ref class CourseManagementForm : public System::Windows::Forms::Form
	{
	public:
		CourseManagementForm(void)
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
		~CourseManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblCourseName;
	protected:
	private: System::Windows::Forms::Label^ lblCredits;
	private: System::Windows::Forms::Label^ lblPrerequisites;
	private: System::Windows::Forms::TextBox^ txtCourseName;
	private: System::Windows::Forms::TextBox^ txtCredits;
	private: System::Windows::Forms::TextBox^ txtPrerequisites;
	private: System::Windows::Forms::Button^ btnSaveCourse;
	private: System::Windows::Forms::Button^ btnDeleteCourse;
	private: System::Windows::Forms::Button^ btnEditCourse;


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
			this->lblCourseName = (gcnew System::Windows::Forms::Label());
			this->lblCredits = (gcnew System::Windows::Forms::Label());
			this->lblPrerequisites = (gcnew System::Windows::Forms::Label());
			this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
			this->txtCredits = (gcnew System::Windows::Forms::TextBox());
			this->txtPrerequisites = (gcnew System::Windows::Forms::TextBox());
			this->btnSaveCourse = (gcnew System::Windows::Forms::Button());
			this->btnDeleteCourse = (gcnew System::Windows::Forms::Button());
			this->btnEditCourse = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblCourseName
			// 
			this->lblCourseName->AutoSize = true;
			this->lblCourseName->Location = System::Drawing::Point(51, 46);
			this->lblCourseName->Name = L"lblCourseName";
			this->lblCourseName->Size = System::Drawing::Size(143, 25);
			this->lblCourseName->TabIndex = 0;
			this->lblCourseName->Text = L"Course Name";
			// 
			// lblCredits
			// 
			this->lblCredits->AutoSize = true;
			this->lblCredits->Location = System::Drawing::Point(51, 182);
			this->lblCredits->Name = L"lblCredits";
			this->lblCredits->Size = System::Drawing::Size(80, 25);
			this->lblCredits->TabIndex = 1;
			this->lblCredits->Text = L"Credits";
			// 
			// lblPrerequisites
			// 
			this->lblPrerequisites->AutoSize = true;
			this->lblPrerequisites->Location = System::Drawing::Point(51, 285);
			this->lblPrerequisites->Name = L"lblPrerequisites";
			this->lblPrerequisites->Size = System::Drawing::Size(138, 25);
			this->lblPrerequisites->TabIndex = 2;
			this->lblPrerequisites->Text = L"Prerequisites";
			// 
			// txtCourseName
			// 
			this->txtCourseName->Location = System::Drawing::Point(56, 74);
			this->txtCourseName->Name = L"txtCourseName";
			this->txtCourseName->Size = System::Drawing::Size(310, 31);
			this->txtCourseName->TabIndex = 3;
			// 
			// txtCredits
			// 
			this->txtCredits->Location = System::Drawing::Point(56, 210);
			this->txtCredits->Name = L"txtCredits";
			this->txtCredits->Size = System::Drawing::Size(310, 31);
			this->txtCredits->TabIndex = 4;
			// 
			// txtPrerequisites
			// 
			this->txtPrerequisites->Location = System::Drawing::Point(56, 313);
			this->txtPrerequisites->Name = L"txtPrerequisites";
			this->txtPrerequisites->Size = System::Drawing::Size(310, 31);
			this->txtPrerequisites->TabIndex = 5;
			// 
			// btnSaveCourse
			// 
			this->btnSaveCourse->Location = System::Drawing::Point(56, 444);
			this->btnSaveCourse->Name = L"btnSaveCourse";
			this->btnSaveCourse->Size = System::Drawing::Size(167, 42);
			this->btnSaveCourse->TabIndex = 6;
			this->btnSaveCourse->Text = L"Save Course";
			this->btnSaveCourse->UseVisualStyleBackColor = true;
			// 
			// btnDeleteCourse
			// 
			this->btnDeleteCourse->Location = System::Drawing::Point(785, 529);
			this->btnDeleteCourse->Name = L"btnDeleteCourse";
			this->btnDeleteCourse->Size = System::Drawing::Size(167, 42);
			this->btnDeleteCourse->TabIndex = 7;
			this->btnDeleteCourse->Text = L"Delete Course";
			this->btnDeleteCourse->UseVisualStyleBackColor = true;
			// 
			// btnEditCourse
			// 
			this->btnEditCourse->Location = System::Drawing::Point(56, 529);
			this->btnEditCourse->Name = L"btnEditCourse";
			this->btnEditCourse->Size = System::Drawing::Size(167, 42);
			this->btnEditCourse->TabIndex = 8;
			this->btnEditCourse->Text = L"Edit Course";
			this->btnEditCourse->UseVisualStyleBackColor = true;
			// 
			// CourseManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1053, 635);
			this->Controls->Add(this->btnEditCourse);
			this->Controls->Add(this->btnDeleteCourse);
			this->Controls->Add(this->btnSaveCourse);
			this->Controls->Add(this->txtPrerequisites);
			this->Controls->Add(this->txtCredits);
			this->Controls->Add(this->txtCourseName);
			this->Controls->Add(this->lblPrerequisites);
			this->Controls->Add(this->lblCredits);
			this->Controls->Add(this->lblCourseName);
			this->Name = L"CourseManagementForm";
			this->Text = L"CourseManagementForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
