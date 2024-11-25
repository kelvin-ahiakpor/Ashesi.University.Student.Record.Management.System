#pragma once

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
		StudentEnrollmentForm(void)
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
		~StudentEnrollmentForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblAvailableCourses;
	private: System::Windows::Forms::ComboBox^ cboxAvailableCourses;
	protected:

	private: System::Windows::Forms::Button^ btnEnroll;

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
			this->lblAvailableCourses = (gcnew System::Windows::Forms::Label());
			this->cboxAvailableCourses = (gcnew System::Windows::Forms::ComboBox());
			this->btnEnroll = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblAvailableCourses
			// 
			this->lblAvailableCourses->AutoSize = true;
			this->lblAvailableCourses->Location = System::Drawing::Point(45, 41);
			this->lblAvailableCourses->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblAvailableCourses->Name = L"lblAvailableCourses";
			this->lblAvailableCourses->Size = System::Drawing::Size(117, 16);
			this->lblAvailableCourses->TabIndex = 0;
			this->lblAvailableCourses->Text = L"Available Courses";
			// 
			// cboxAvailableCourses
			// 
			this->cboxAvailableCourses->FormattingEnabled = true;
			this->cboxAvailableCourses->Location = System::Drawing::Point(48, 95);
			this->cboxAvailableCourses->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->cboxAvailableCourses->Name = L"cboxAvailableCourses";
			this->cboxAvailableCourses->Size = System::Drawing::Size(293, 24);
			this->cboxAvailableCourses->TabIndex = 1;
			this->cboxAvailableCourses->SelectedIndexChanged += gcnew System::EventHandler(this, &StudentEnrollmentForm::cboxAvailableCourses_SelectedIndexChanged);
			// 
			// btnEnroll
			// 
			this->btnEnroll->Location = System::Drawing::Point(387, 95);
			this->btnEnroll->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnEnroll->Name = L"btnEnroll";
			this->btnEnroll->Size = System::Drawing::Size(121, 21);
			this->btnEnroll->TabIndex = 2;
			this->btnEnroll->Text = L"Enroll";
			this->btnEnroll->UseVisualStyleBackColor = true;
			this->btnEnroll->Click += gcnew System::EventHandler(this, &StudentEnrollmentForm::btnEnroll_Click);
			// 
			// StudentEnrollmentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(533, 349);
			this->Controls->Add(this->btnEnroll);
			this->Controls->Add(this->cboxAvailableCourses);
			this->Controls->Add(this->lblAvailableCourses);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"StudentEnrollmentForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"StudentEnrollmentForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnEnroll_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Enrollment functionality coming soon.");
	}
	private: System::Void cboxAvailableCourses_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
