#include "MainApplicationForm.h"
#include "StudentManagementForm.h"
#include "FacultyManagementForm.h"  // Ensure this is included
#include "CourseManagementForm.h"
#include "TranscriptForm.h"
#include "resource.h"
#include "ViewGradesAdmin.h"
#include "ViewGrades.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;

void MainApplicationForm::OpenChildForm(Type^ formType, Object^ parameter) {
    // Check if the form is already open
    for each (Form ^ form in this->MdiChildren) {
        if (form->GetType() == formType) {
            form->Activate();
            return;
        }
    }

    Form^ childForm;

    // Check for specific forms requiring parameters
    if (formType == StudentManagementForm::typeid && parameter != nullptr) {
        Student^ student = dynamic_cast<Student^>(parameter);
        if (student != nullptr) {
            childForm = gcnew StudentManagementForm();
        }
        else {
            throw gcnew ArgumentException("Invalid parameter for StudentManagementForm");
        }
    }
    else {
        // Default case for forms without parameters
        childForm = (Form^)Activator::CreateInstance(formType);
    }

    childForm->MdiParent = this;
    childForm->Show();
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::MainApplicationForm_Load(System::Object^ sender, System::EventArgs^ e) {
    UpdateMenuForRole(userRole);
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::gradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    if (userRole == "Administrator") {
        ViewGradesAdmin^ adminview = gcnew ViewGradesAdmin();
        adminview->ShowDialog();
    }
    else if (userRole == "Student") {
        ViewGrades^ studentview = gcnew ViewGrades(current);
        studentview->ShowDialog();
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::profileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    if (userRole == "Administrator") {
        ProfileManagementForm^ profile = gcnew ProfileManagementForm(adminuser);
        profile->ShowDialog();
    }
    else if (userRole == "Student") {
        ProfileManagementForm^ profile = gcnew ProfileManagementForm(current);
        profile->ShowDialog();
    }
}

System::Void MainApplicationForm::studentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(StudentManagementForm::typeid, current);
}

System::Void MainApplicationForm::facultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(FacultyManagementForm::typeid, nullptr);
}

System::Void MainApplicationForm::coursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(CourseManagementForm::typeid, nullptr);
}

System::Void MainApplicationForm::generateTranscriptToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(TranscriptForm::typeid, nullptr);
}

void MainApplicationForm::UpdateMenuForRole(String^ userRole) {
    // Disable specific menu items based on user role
    manageToolStripMenuItem->Enabled = (userRole != "Student");
    studentsToolStripMenuItem->Enabled = (userRole == "Administrator" || userRole == "Faculty");
    adminToolStripMenuItem->Enabled = (userRole == "Administrator");
    coursesToolStripMenuItem->Enabled = (userRole != "Student");
    viewToolStripMenuItem->Enabled = (userRole == "Administrator" || userRole == "Faculty");
}
