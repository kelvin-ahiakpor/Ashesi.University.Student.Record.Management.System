#include "MainApplicationForm.h"  // Include the MainApplicationForm header file
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Simulate getting the user's role (replace this with actual logic from your LoginForm)
    String^ userRole = "Administrator"; // Example: "Student", "Faculty", or "Administrator"

    // Create and configure the main form
    AshesiUniversityStudentRecordManagementSystem::MainApplicationForm^ mainForm =
        gcnew AshesiUniversityStudentRecordManagementSystem::MainApplicationForm();
    mainForm->UpdateMenuForRole(userRole);  // Update the menu based on the user's role

    // Run the application with the configured main form
    Application::Run(mainForm);

    return 0;
}

