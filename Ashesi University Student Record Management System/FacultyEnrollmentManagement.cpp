#include "FacultyEnrollmentManagement.h"
//#include "FacultyEnrollmentManagement.h"
//#include "DatabaseManager.h"
//
//
//System::Void AshesiUniversityStudentRecordManagementSystem::FacultyEnrollmentManagement::ViewEnroll_Click(System::Object^ sender, System::EventArgs^ e)
//{
//    DatabaseManager^ db = DatabaseManager::GetInstance();
//
//    try {
//        db->ConnectToDatabase();
//
//        String^ query = R"(
//            SELECT
//                Enrollment,
//                CourseName,
//                DepartmentID,
//                Credits,
//                Description,
//                Prerequisites
//            FROM
//                Courses;
//        )";
//    }
//    return System::Void();
//}

System::Void AshesiUniversityStudentRecordManagementSystem::FacultyEnrollmentManagement::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

