#include "MainApplicationForm.h"
#include "StudentManagementForm.h"
#include "FacultyManagementForm.h"  
#include "CourseManagementForm.h"
#include "TranscriptForm.h"
#include "resource.h"
#include "ViewGradesAdmin.h"
#include "ViewGrades.h"
#include "StudentEnrollmentForm.h"
#include "EnrollmentHistory.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;

void MainApplicationForm::OpenChildForm(Type^ formType, Object^ parameter) {
    // Ensure that the parameter is of type User
    User^ user = dynamic_cast<User^>(parameter);
    if (user == nullptr && parameter != nullptr) {
        throw gcnew ArgumentException("Invalid parameter type. Expected User.");
    }

    for each (Form ^ form in this->MdiChildren) {
        if (form->GetType() == formType) {
            form->Activate();
            return;
        }
    }

    // Find the constructor that accepts a User parameter
    array<System::Reflection::ConstructorInfo^>^ constructors = formType->GetConstructors();
    Form^ childForm = nullptr;

    // Try to find a constructor that accepts a User^ parameter
    for each (System::Reflection::ConstructorInfo ^ constructor in constructors) {
        array<System::Reflection::ParameterInfo^>^ parameters = constructor->GetParameters();
        if (parameters->Length == 1 && parameters[0]->ParameterType == User::typeid) {
            // If we found a matching constructor, create the form with the User parameter
            childForm = (Form^)constructor->Invoke(gcnew array<Object^> { user });
            break;  // Exit after creating the form
        }
    }

    // If no constructor with User^ parameter was found, fall back to default constructor (no parameters)
    if (childForm == nullptr) {
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
	else if (userRole == "Faculty") {
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

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::enrollmentHistoryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{    
    OpenChildForm(EnrollmentHistory::typeid, globalUser);

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
    enrollmentHistoryToolStripMenuItem->Enabled = (userRole == "Student");
    facultyToolStripMenuItem->Enabled = (userRole != "Student");


}
