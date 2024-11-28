#include "MainApplicationForm.h"
#include "StudentDashboardForm.h"
#include "FacultyDashboardForm.h"
#include "CourseManagementForm.h"
#include "TranscriptForm.h"
#include "resource.h" 

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;

void MainApplicationForm::OpenChildForm(Type^ formType, Object^ parameter) {
    for each (Form ^ form in this->MdiChildren) {
        if (form->GetType() == formType) {
            form->Activate();
            return;
        }
    }

    // Check for specific forms requiring parameters
    Form^ childForm;
    if (formType == StudentDashboardForm::typeid && parameter != nullptr) {
        Student^ student = dynamic_cast<Student^>(parameter);
        if (student != nullptr) {
            childForm = gcnew StudentDashboardForm(student);
        }
        else {
            throw gcnew ArgumentException("Invalid parameter for StudentDashboardForm");
        }
    }
    else {
        // Default case for forms without parameters
        childForm = (Form^)Activator::CreateInstance(formType);
    }

    childForm->MdiParent = this;
    childForm->Show();
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::MainApplicationForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    UpdateMenuForRole(userRole);
    return System::Void();
}


System::Void MainApplicationForm::studentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(StudentDashboardForm::typeid, current);
}

System::Void MainApplicationForm::facultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(FacultyDashboardForm::typeid, NULL);
}

System::Void MainApplicationForm::coursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(CourseManagementForm::typeid, NULL);
}

System::Void MainApplicationForm::generateTranscriptToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(TranscriptForm::typeid, NULL);
}

void MainApplicationForm::UpdateMenuForRole(String^ userRole) {
    if (userRole == "Student") {
        studentsToolStripMenuItem->Enabled = true;
        facultyToolStripMenuItem->Enabled = false;
        coursesToolStripMenuItem->Enabled = false;
        adminToolStripMenuItem->Enabled = false;
    }
    else if (userRole == "Faculty") {
        studentsToolStripMenuItem->Enabled = false;
        adminToolStripMenuItem->Enabled = false;
        coursesToolStripMenuItem->Enabled = false;
		viewToolStripMenuItem->Enabled = false;
    }
    else if (userRole == "Administrator") {
        // Admin has access to all menus, so no need to disable anything
    }
}