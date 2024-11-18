#pragma once

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminDashboardForm
	/// </summary>
	public ref class AdminDashboardForm : public System::Windows::Forms::Form
	{
	public:
		AdminDashboardForm(void)
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
		~AdminDashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblWelcome;
	protected:

	protected:
	private: System::Windows::Forms::Button^ btnManageStudents;
	private: System::Windows::Forms::Button^ btnManageFaculty;
	private: System::Windows::Forms::Button^ btnManageCourses;
	private: System::Windows::Forms::Button^ btnGenerateReports;




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
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->btnManageStudents = (gcnew System::Windows::Forms::Button());
			this->btnManageFaculty = (gcnew System::Windows::Forms::Button());
			this->btnManageCourses = (gcnew System::Windows::Forms::Button());
			this->btnGenerateReports = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Location = System::Drawing::Point(415, 133);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(253, 25);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Welcome <Admin Name>";
			// 
			// btnManageStudents
			// 
			this->btnManageStudents->Location = System::Drawing::Point(80, 389);
			this->btnManageStudents->Name = L"btnManageStudents";
			this->btnManageStudents->Size = System::Drawing::Size(201, 55);
			this->btnManageStudents->TabIndex = 1;
			this->btnManageStudents->Text = L"Manage Students";
			this->btnManageStudents->UseVisualStyleBackColor = true;
			// 
			// btnManageFaculty
			// 
			this->btnManageFaculty->Location = System::Drawing::Point(321, 389);
			this->btnManageFaculty->Name = L"btnManageFaculty";
			this->btnManageFaculty->Size = System::Drawing::Size(201, 55);
			this->btnManageFaculty->TabIndex = 2;
			this->btnManageFaculty->Text = L"Manage Faculty";
			this->btnManageFaculty->UseVisualStyleBackColor = true;
			// 
			// btnManageCourses
			// 
			this->btnManageCourses->Location = System::Drawing::Point(561, 389);
			this->btnManageCourses->Name = L"btnManageCourses";
			this->btnManageCourses->Size = System::Drawing::Size(201, 55);
			this->btnManageCourses->TabIndex = 3;
			this->btnManageCourses->Text = L"Manage Courses";
			this->btnManageCourses->UseVisualStyleBackColor = true;
			// 
			// btnGenerateReports
			// 
			this->btnGenerateReports->Location = System::Drawing::Point(801, 389);
			this->btnGenerateReports->Name = L"btnGenerateReports";
			this->btnGenerateReports->Size = System::Drawing::Size(201, 55);
			this->btnGenerateReports->TabIndex = 4;
			this->btnGenerateReports->Text = L"Generate Reports";
			this->btnGenerateReports->UseVisualStyleBackColor = true;
			// 
			// AdminDashboardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1095, 581);
			this->Controls->Add(this->btnGenerateReports);
			this->Controls->Add(this->btnManageCourses);
			this->Controls->Add(this->btnManageFaculty);
			this->Controls->Add(this->btnManageStudents);
			this->Controls->Add(this->lblWelcome);
			this->Name = L"AdminDashboardForm";
			this->Text = L"AdminDashboardForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
