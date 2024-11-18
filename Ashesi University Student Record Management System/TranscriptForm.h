#pragma once

namespace AshesiUniversityStudentRecordManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TranscriptForm
	/// </summary>
	public ref class TranscriptForm : public System::Windows::Forms::Form
	{
	public:
		TranscriptForm(void)
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
		~TranscriptForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblStudentID;
	protected:
	private: System::Windows::Forms::TextBox^ txtStudentID;
	private: System::Windows::Forms::Button^ btnViewTranscript;
	private: System::Windows::Forms::RichTextBox^ richTxtTranscript;
	private: System::Windows::Forms::Button^ btnPrintTranscript;

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
			this->lblStudentID = (gcnew System::Windows::Forms::Label());
			this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
			this->btnViewTranscript = (gcnew System::Windows::Forms::Button());
			this->richTxtTranscript = (gcnew System::Windows::Forms::RichTextBox());
			this->btnPrintTranscript = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblStudentID
			// 
			this->lblStudentID->AutoSize = true;
			this->lblStudentID->Location = System::Drawing::Point(62, 53);
			this->lblStudentID->Name = L"lblStudentID";
			this->lblStudentID->Size = System::Drawing::Size(112, 25);
			this->lblStudentID->TabIndex = 0;
			this->lblStudentID->Text = L"Student ID";
			// 
			// txtStudentID
			// 
			this->txtStudentID->Location = System::Drawing::Point(67, 81);
			this->txtStudentID->Name = L"txtStudentID";
			this->txtStudentID->Size = System::Drawing::Size(310, 31);
			this->txtStudentID->TabIndex = 1;
			// 
			// btnViewTranscript
			// 
			this->btnViewTranscript->Location = System::Drawing::Point(67, 174);
			this->btnViewTranscript->Name = L"btnViewTranscript";
			this->btnViewTranscript->Size = System::Drawing::Size(176, 44);
			this->btnViewTranscript->TabIndex = 2;
			this->btnViewTranscript->Text = L"View Transcript";
			this->btnViewTranscript->UseVisualStyleBackColor = true;
			this->btnViewTranscript->Click += gcnew System::EventHandler(this, &TranscriptForm::btnViewTranscript_Click);
			// 
			// richTxtTranscript
			// 
			this->richTxtTranscript->Location = System::Drawing::Point(67, 247);
			this->richTxtTranscript->Name = L"richTxtTranscript";
			this->richTxtTranscript->Size = System::Drawing::Size(1094, 574);
			this->richTxtTranscript->TabIndex = 3;
			this->richTxtTranscript->Text = L"";
			// 
			// btnPrintTranscript
			// 
			this->btnPrintTranscript->Location = System::Drawing::Point(956, 53);
			this->btnPrintTranscript->Name = L"btnPrintTranscript";
			this->btnPrintTranscript->Size = System::Drawing::Size(205, 55);
			this->btnPrintTranscript->TabIndex = 4;
			this->btnPrintTranscript->Text = L"Print Transcript";
			this->btnPrintTranscript->UseVisualStyleBackColor = true;
			this->btnPrintTranscript->Click += gcnew System::EventHandler(this, &TranscriptForm::btnPrintTranscript_Click);
			// 
			// TranscriptForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1241, 898);
			this->Controls->Add(this->btnPrintTranscript);
			this->Controls->Add(this->richTxtTranscript);
			this->Controls->Add(this->btnViewTranscript);
			this->Controls->Add(this->txtStudentID);
			this->Controls->Add(this->lblStudentID);
			this->Name = L"TranscriptForm";
			this->Text = L"TranscriptForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnViewTranscript_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Transcript viewing functionality coming soon.");
	}
private: System::Void btnPrintTranscript_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Transcript printing functionality coming soon.");
}
};
}
