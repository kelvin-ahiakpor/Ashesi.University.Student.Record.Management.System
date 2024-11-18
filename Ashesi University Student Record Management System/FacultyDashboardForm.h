#pragma once

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FacultyDashboardForm
	/// </summary>
	public ref class FacultyDashboardForm : public System::Windows::Forms::Form
	{
	public:
		FacultyDashboardForm(void)
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
		~FacultyDashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblWelcome;
	protected:

	protected:

	private: System::Windows::Forms::Button^ btnManageCourses;
	private: System::Windows::Forms::Button^ btnEnterGrades;
	private: System::Windows::Forms::Button^ btnViewRoster;
	private: System::Windows::Forms::Button^ btnManageProfile;



	protected:


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
			this->btnManageCourses = (gcnew System::Windows::Forms::Button());
			this->btnEnterGrades = (gcnew System::Windows::Forms::Button());
			this->btnViewRoster = (gcnew System::Windows::Forms::Button());
			this->btnManageProfile = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Location = System::Drawing::Point(464, 142);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(263, 25);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Welcome <Faculty Name>";
			// 
			// btnManageCourses
			// 
			this->btnManageCourses->Location = System::Drawing::Point(112, 417);
			this->btnManageCourses->Name = L"btnManageCourses";
			this->btnManageCourses->Size = System::Drawing::Size(216, 53);
			this->btnManageCourses->TabIndex = 1;
			this->btnManageCourses->Text = L"Manage Courses";
			this->btnManageCourses->UseVisualStyleBackColor = true;
			// 
			// btnEnterGrades
			// 
			this->btnEnterGrades->Location = System::Drawing::Point(354, 417);
			this->btnEnterGrades->Name = L"btnEnterGrades";
			this->btnEnterGrades->Size = System::Drawing::Size(216, 53);
			this->btnEnterGrades->TabIndex = 2;
			this->btnEnterGrades->Text = L"Enter Grades";
			this->btnEnterGrades->UseVisualStyleBackColor = true;
			// 
			// btnViewRoster
			// 
			this->btnViewRoster->Location = System::Drawing::Point(605, 417);
			this->btnViewRoster->Name = L"btnViewRoster";
			this->btnViewRoster->Size = System::Drawing::Size(216, 53);
			this->btnViewRoster->TabIndex = 3;
			this->btnViewRoster->Text = L"View Roster";
			this->btnViewRoster->UseVisualStyleBackColor = true;
			// 
			// btnManageProfile
			// 
			this->btnManageProfile->Location = System::Drawing::Point(849, 417);
			this->btnManageProfile->Name = L"btnManageProfile";
			this->btnManageProfile->Size = System::Drawing::Size(216, 53);
			this->btnManageProfile->TabIndex = 4;
			this->btnManageProfile->Text = L"Manage Profile";
			this->btnManageProfile->UseVisualStyleBackColor = true;
			// 
			// FacultyDashboardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1179, 597);
			this->Controls->Add(this->btnManageProfile);
			this->Controls->Add(this->btnViewRoster);
			this->Controls->Add(this->btnEnterGrades);
			this->Controls->Add(this->btnManageCourses);
			this->Controls->Add(this->lblWelcome);
			this->Name = L"FacultyDashboardForm";
			this->Text = L"FacultyDashboardForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
