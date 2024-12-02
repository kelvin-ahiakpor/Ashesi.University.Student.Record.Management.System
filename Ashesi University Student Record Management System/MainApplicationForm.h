#pragma once
#include "User.h"
#include "Student.h"
#include "Faculty.h"
#include "Admin.h"
#include "TranscriptForm.h"
#include "Student.h"
#include "Admin.h"
#include "Faculty.h"


namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainApplicationForm
	/// </summary>
	public ref class MainApplicationForm : public System::Windows::Forms::Form
	{
	public:
		User^ globalUser;
		Student^ student;
		Faculty^ faculty;
		Admin^ admin;
		String^ userRole;
		int^ studentid;
	private: System::Windows::Forms::ToolStripMenuItem^ enrollmentHistoryToolStripMenuItem;

	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^ tsbtnLogOut;

	public:

		Faculty^ facultyrole;

		MainApplicationForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//this->Icon = gcnew System::Drawing::Icon(GetType()->Assembly->GetManifestResourceStream("AshesiUniversityStudentRecordManagementSystem.IDI_ASHESI_LOGO"));
		}

		MainApplicationForm(User^ user)
		{
			InitializeComponent();
			// Perform dynamic casting once and then check the user type
			if (Student^ s = dynamic_cast<Student^>(user)) {
				this->student = s;
				this->globalUser = s;  // Assigning user to globalUser
				userRole = "Student";
				studentid = student->getStudentID();
			}
			else if (Faculty^ f = dynamic_cast<Faculty^>(user)) {
				this->faculty = f;
				this->globalUser = f;  // Assigning user to globalUser
				userRole = "Faculty";
			}
			else if (Admin^ a = dynamic_cast<Admin^>(user)) {
				this->admin = a;
				this->globalUser = a;  // Assigning user to globalUser
				userRole = "Administrator";
			}
			else {
				throw gcnew System::ArgumentException("Unsupported user type.");
			}
		}
	private: System::Windows::Forms::ToolStripMenuItem^ viewToolStripMenuItem;
	public:

	private: System::Windows::Forms::ToolStripMenuItem^ gradesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ profileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enrollmentsToolStripMenuItem;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainApplicationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ studentsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ facultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ coursesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ reportsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ generateTranscriptToolStripMenuItem;




	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ tsstatWelcomeMessage;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainApplicationForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->studentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->coursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enrollmentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reportsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generateTranscriptToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enrollmentHistoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->profileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->tsstatWelcomeMessage = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tsbtnLogOut = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fileToolStripMenuItem,
					this->manageToolStripMenuItem, this->reportsToolStripMenuItem, this->viewToolStripMenuItem, this->profileToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(3, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(644, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 22);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::fileToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(93, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::exitToolStripMenuItem_Click);
			// 
			// manageToolStripMenuItem
			// 
			this->manageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->studentsToolStripMenuItem,
					this->facultyToolStripMenuItem, this->coursesToolStripMenuItem, this->enrollmentsToolStripMenuItem
			});
			this->manageToolStripMenuItem->Name = L"manageToolStripMenuItem";
			this->manageToolStripMenuItem->Size = System::Drawing::Size(62, 22);
			this->manageToolStripMenuItem->Text = L"Manage";
			this->manageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::manageToolStripMenuItem_Click);
			// 
			// studentsToolStripMenuItem
			// 
			this->studentsToolStripMenuItem->Name = L"studentsToolStripMenuItem";
			this->studentsToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->studentsToolStripMenuItem->Text = L"Students";
			this->studentsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::studentsToolStripMenuItem_Click);
			// 
			// facultyToolStripMenuItem
			// 
			this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
			this->facultyToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->facultyToolStripMenuItem->Text = L"Faculty";
			this->facultyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::facultyToolStripMenuItem_Click);
			// 
			// coursesToolStripMenuItem
			// 
			this->coursesToolStripMenuItem->Name = L"coursesToolStripMenuItem";
			this->coursesToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->coursesToolStripMenuItem->Text = L"Courses";
			this->coursesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::coursesToolStripMenuItem_Click);
			// 
			// enrollmentsToolStripMenuItem
			// 
			this->enrollmentsToolStripMenuItem->Name = L"enrollmentsToolStripMenuItem";
			this->enrollmentsToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->enrollmentsToolStripMenuItem->Text = L"Enrollments";
			this->enrollmentsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::enrollmentsToolStripMenuItem_Click);
			// 
			// reportsToolStripMenuItem
			// 
			this->reportsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->generateTranscriptToolStripMenuItem });
			this->reportsToolStripMenuItem->Name = L"reportsToolStripMenuItem";
			this->reportsToolStripMenuItem->Size = System::Drawing::Size(59, 22);
			this->reportsToolStripMenuItem->Text = L"Reports";
			// 
			// generateTranscriptToolStripMenuItem
			// 
			this->generateTranscriptToolStripMenuItem->Name = L"generateTranscriptToolStripMenuItem";
			this->generateTranscriptToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->generateTranscriptToolStripMenuItem->Text = L"Generate Transcript";
			this->generateTranscriptToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::generateTranscriptToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->gradesToolStripMenuItem,
					this->enrollmentHistoryToolStripMenuItem
			});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 22);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// gradesToolStripMenuItem
			// 
			this->gradesToolStripMenuItem->Name = L"gradesToolStripMenuItem";
			this->gradesToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->gradesToolStripMenuItem->Text = L"Grades";
			this->gradesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::gradesToolStripMenuItem_Click);
			// 
			// enrollmentHistoryToolStripMenuItem
			// 
			this->enrollmentHistoryToolStripMenuItem->Name = L"enrollmentHistoryToolStripMenuItem";
			this->enrollmentHistoryToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->enrollmentHistoryToolStripMenuItem->Text = L"Enrollment History";
			this->enrollmentHistoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::enrollmentHistoryToolStripMenuItem_Click);
			// 
			// profileToolStripMenuItem
			// 
			this->profileToolStripMenuItem->Name = L"profileToolStripMenuItem";
			this->profileToolStripMenuItem->Size = System::Drawing::Size(53, 22);
			this->profileToolStripMenuItem->Text = L"Profile";
			this->profileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainApplicationForm::profileToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tsstatWelcomeMessage });
			this->statusStrip1->Location = System::Drawing::Point(0, 413);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(1, 0, 7, 0);
			this->statusStrip1->Size = System::Drawing::Size(644, 22);
			this->statusStrip1->TabIndex = 4;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// tsstatWelcomeMessage
			// 
			this->tsstatWelcomeMessage->Name = L"tsstatWelcomeMessage";
			this->tsstatWelcomeMessage->Size = System::Drawing::Size(112, 17);
			this->tsstatWelcomeMessage->Text = L"Welcome <Admin>";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripSeparator1,
					this->tsbtnLogOut
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(644, 25);
			this->toolStrip1->TabIndex = 8;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// tsbtnLogOut
			// 
			this->tsbtnLogOut->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->tsbtnLogOut->BackColor = System::Drawing::SystemColors::Control;
			this->tsbtnLogOut->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tsbtnLogOut->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tsbtnLogOut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbtnLogOut.Image")));
			this->tsbtnLogOut->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsbtnLogOut->Margin = System::Windows::Forms::Padding(0, 1, 8, 2);
			this->tsbtnLogOut->Name = L"tsbtnLogOut";
			this->tsbtnLogOut->Size = System::Drawing::Size(51, 22);
			this->tsbtnLogOut->Text = L"LogOut";
			this->tsbtnLogOut->Click += gcnew System::EventHandler(this, &MainApplicationForm::btnLogOut_Click);
			// 
			// MainApplicationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(644, 435);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainApplicationForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainApplicationForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainApplicationForm::MainApplicationForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainApplicationForm::MainApplicationForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		System::Void studentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void facultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void coursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void generateTranscriptToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		void UpdateMenuForRole(String^ userRole);
		void OpenChildForm(Type^ formType, Object^ parameter);

		private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}

private: System::Void MainApplicationForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void manageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void adminToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void gradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void profileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void coursesToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void enrollmentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void enrollmentHistoryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnLogOut_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MainApplicationForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}
