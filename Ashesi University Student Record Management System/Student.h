#pragma once
#include "User.h"
#include <string>

using namespace System;
using namespace System::Collections::Generic;

public ref class Student : public User {
private:
    int^ studentID;  // Managed string type
    int^ departmentID;      // Managed string type

public:
    // Constructor
    Student(int^ id, String^ fname, String^ lname, String^ mail, int^ studID, int^ deptID)
        : User(id, fname, lname, mail), studentID(studID), departmentID(deptID)
    {
    }

    // Getters
    int^ getStudentID() { return studentID; }
    int^ getDepartmentID() { return departmentID; }

};
