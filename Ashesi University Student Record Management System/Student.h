#pragma once
#include "User.h"
#include <string>

using namespace System;
using namespace System::Collections::Generic;

public ref class Student : public User {
private:
    int^ studentID;  // Managed string type
    String^ major;      // Managed string type

public:
    // Constructor
    Student(int^ id, String^ fname, String^ lname, String^ mail, int^ studID, String^ maj)
        : User(id, fname, lname, mail), studentID(studID), major(maj)
    {
    }

    // Getters
    int^ getStudentID() { return studentID; }
    String^ getMajor() { return major; }

};
