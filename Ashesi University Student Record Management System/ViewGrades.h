#pragma once

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class ViewGrades : public System::Windows::Forms::Form
	{
	public:
		ViewGrades(void)
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
		~ViewGrades()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTxtTranscript;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTxtTranscript = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(171, 49);
			this->button1->TabIndex = 0;
			this->button1->Text = L"View Grades";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ViewGrades::button1_Click);
			// 
			// richTxtTranscript
			// 
			this->richTxtTranscript->Location = System::Drawing::Point(25, 79);
			this->richTxtTranscript->Margin = System::Windows::Forms::Padding(2);
			this->richTxtTranscript->Name = L"richTxtGrades";
			this->richTxtTranscript->Size = System::Drawing::Size(731, 369);
			this->richTxtTranscript->TabIndex = 4;
			this->richTxtTranscript->Text = L"";
			this->richTxtTranscript->TextChanged += gcnew System::EventHandler(this, &ViewGrades::richTxtGrades_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 504);
			this->Controls->Add(this->richTxtTranscript);
			this->Controls->Add(this->button1);
			this->Name = L"View Grades";
			this->Text = L"View Grades";
			this->Load += gcnew System::EventHandler(this, &ViewGrades::ViewGrades_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ViewGrades_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void richTxtGrades_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	};
}
