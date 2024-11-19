#include "MainApplicationForm.h"
#include "StudentDashboardForm.h"
#include "FacultyDashboardForm.h"
#include "CourseManagementForm.h"
#include "TranscriptForm.h"
#include "resource.h" 

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;

void MainApplicationForm::OpenChildForm(Type^ formType) {
    for each (Form^ form in this->MdiChildren) {
        if (form->GetType() == formType) {
            form->Activate();
            return;
        }
    }

    Form^ childForm = (Form^)Activator::CreateInstance(formType);
    childForm->MdiParent = this;
    childForm->Show();
}

System::Void MainApplicationForm::studentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(StudentDashboardForm::typeid);
}

System::Void MainApplicationForm::facultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(FacultyDashboardForm::typeid);
}

System::Void MainApplicationForm::coursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(CourseManagementForm::typeid);
}

System::Void MainApplicationForm::generateTranscriptToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(TranscriptForm::typeid);
}

void MainApplicationForm::UpdateMenuForRole(String^ userRole) {
    if (userRole == "Student") {
        studentsToolStripMenuItem->Enabled = false;
        facultyToolStripMenuItem->Enabled = false;
        coursesToolStripMenuItem->Enabled = false;
    }
    else if (userRole == "Faculty") {
        studentsToolStripMenuItem->Enabled = false;
    }
    else if (userRole == "Administrator") {
        // Admin has access to all menus, so no need to disable anything
    }
}