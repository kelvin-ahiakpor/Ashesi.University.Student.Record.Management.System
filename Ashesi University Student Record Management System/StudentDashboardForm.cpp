#include "StudentDashboardForm.h"
#include "StudentEnrollmentForm.h"

using namespace AshesiUniversityStudentRecordManagementSystem;
using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

System::Void btnEnrollInCourse_Click(System::Object^ sender, System::EventArgs^ e) {
	StudentDashboardForm^ studentdashboard = gcnew StudentDashboardForm();
	studentdashboard->Show();
}

