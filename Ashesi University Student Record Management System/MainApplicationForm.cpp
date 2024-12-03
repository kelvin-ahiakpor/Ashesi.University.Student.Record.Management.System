#include "MainApplicationForm.h"
#include "StudentManagementForm.h"
#include "FacultyManagementForm.h" 
#include "FacultyEnrollmentManagement.h"
#include "CourseManagementForm.h"
#include "TranscriptForm.h"
#include "resource.h"
#include "ViewGradesAdmin.h"
#include "ViewGrades.h"
#include "StudentEnrollmentForm.h"
#include "EnrollmentHistory.h"
#include "LoginForm.h"
#include "ProfileManagementForm.h"
#include "GradeManagementForm.h"
#include "ClassRoster.h"

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
	tsstatWelcomeMessage->Text = "Welcome, " + globalUser->getFirstName() + " " + globalUser->getLastName() + "!";
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
        ProfileManagementForm^ profile = gcnew ProfileManagementForm(globalUser);
        profile->ShowDialog();
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::coursesToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::enrollmentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (userRole == "Student") {
        OpenChildForm(StudentEnrollmentForm::typeid, globalUser);

    }
    else if (userRole == "Faculty") {
        OpenChildForm(FacultyEnrollmentManagement::typeid, globalUser);
    }
   
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::enrollmentHistoryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{    
    OpenChildForm(EnrollmentHistory::typeid, globalUser);
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::btnLogOut_Click(System::Object^ sender, System::EventArgs^ e)
{
	DialogResult = MessageBox::Show("Are you sure you want to log out?", "Log Out", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
    if (DialogResult == System::Windows::Forms::DialogResult::Yes) {
        globalUser->logout();

        // Close all child forms
        for each (Form ^ childForm in this->MdiChildren) {
            childForm->Close();
        }

        // Cast and cleanup specific user types
        Student^ student = dynamic_cast<Student^>(globalUser);
        Faculty^ faculty = dynamic_cast<Faculty^>(globalUser);
        Admin^ admin = dynamic_cast<Admin^>(globalUser);

        if (student != nullptr) {
            student = nullptr;
        }
        else if (faculty != nullptr) {
            faculty = nullptr;
        }
        else if (admin != nullptr) {
            admin = nullptr;
        }

        // Clear the base user object
        globalUser = nullptr;

        // Create and show new login form
        LoginForm^ loginForm = gcnew LoginForm();
        loginForm->Show();

        // Close the current form
        this->Close();
    }
    else {
        return;
    }
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
    studentsToolStripMenuItem->Enabled = (userRole == "Administrator");
    coursesToolStripMenuItem->Enabled = (userRole == "Administrator" );
    viewToolStripMenuItem->Enabled = (userRole == "Administrator" || userRole == "Faculty" || userRole == "Student");
    enrollmentsToolStripMenuItem->Enabled = (userRole == "Student"|| userRole == "Faculty");
    enrollmentHistoryToolStripMenuItem->Enabled = (userRole == "Student");
    gradesToolStripMenuItem->Enabled = (userRole == "Student");
    facultyToolStripMenuItem->Enabled = (userRole == "Administrator");
    gradesToolStripMenuItem1->Enabled= (userRole == "Faculty");
    generateTranscriptToolStripMenuItem->Enabled = (userRole != "Faculty");
    classRosterToolStripMenuItem->Enabled = (userRole == "Faculty");


}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::MainApplicationForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    if (globalUser != nullptr) {
        Student^ student = dynamic_cast<Student^>(globalUser);
        Faculty^ faculty = dynamic_cast<Faculty^>(globalUser);
        Admin^ admin = dynamic_cast<Admin^>(globalUser);

        if (student != nullptr) {
            student = nullptr;
        }
        else if (faculty != nullptr) {
            faculty = nullptr;
        }
        else if (admin != nullptr) {
            admin = nullptr;
        }

        globalUser = nullptr;
    }
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::gradesToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    OpenChildForm(GradeManagementForm::typeid, globalUser);
    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::classRosterToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    OpenChildForm(ClassRoster::typeid, globalUser);
    return System::Void();
}

System::Void AshesiUniversityStudentRecordManagementSystem::MainApplicationForm::MainApplicationForm_MdiChildActivate(System::Object^ sender, System::EventArgs^ e)
{
    lblMotivation->Visible = false;
    lblGetGoing->Visible = false;
}

