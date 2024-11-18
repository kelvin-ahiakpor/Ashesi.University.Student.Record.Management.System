#include "LoginForm.h"  // Include your LoginForm header file
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew AshesiUniversityStudentRecordManagementSystem::LoginForm());  // Start with LoginForm
    return 0;
}
