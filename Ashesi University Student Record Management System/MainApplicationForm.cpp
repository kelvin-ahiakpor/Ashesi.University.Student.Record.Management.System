#include "MainApplicationForm.h"
#include "StudentManagementForm.h"
#include "FacultyManagementForm.h"  
#include "CourseManagementForm.h"
#include "TranscriptForm.h"
#include "resource.h"
#include "ViewGradesAdmin.h"
#include "ViewGrades.h"
#include "StudentEnrollmentForm.h"

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
        ViewGrades^ studentview = gcnew ViewGrades(globalUser);
        studentview->ShowDialog();
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::profileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    if (userRole == "Administrator") {
        ProfileManagementForm^ profile = gcnew ProfileManagementForm(globalUser);
        profile->ShowDialog();
    }
    else if (userRole == "Student") {
        ProfileManagementForm^ profile = gcnew ProfileManagementForm(globalUser);
        profile->ShowDialog();
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::coursesToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::enrollmentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    OpenChildForm(StudentEnrollmentForm::typeid, globalUser);
    return System::Void();
}

System::Void MainApplicationForm::studentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(StudentManagementForm::typeid, globalUser);
}

System::Void MainApplicationForm::facultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(FacultyManagementForm::typeid, globalUser);
}

System::Void MainApplicationForm::coursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(CourseManagementForm::typeid, globalUser);
}

System::Void MainApplicationForm::generateTranscriptToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenChildForm(TranscriptForm::typeid, globalUser);
}

void MainApplicationForm::UpdateMenuForRole(String^ userRole) {
    // Disable specific menu items based on user role
    studentsToolStripMenuItem->Enabled = (userRole == "Administrator" || userRole == "Faculty");
    coursesToolStripMenuItem->Enabled = (userRole != "Student");
    viewToolStripMenuItem->Enabled = (userRole == "Administrator" || userRole == "Faculty" || userRole == "Student");
    coursesToolStripMenuItem1->Enabled = (userRole == "Faculty");
    enrollmentsToolStripMenuItem->Enabled = (userRole == "Student");


}
