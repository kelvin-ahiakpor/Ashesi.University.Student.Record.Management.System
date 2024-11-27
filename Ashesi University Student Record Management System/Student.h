#pragma once
#include "User.h"
#include <vector>
#include <string>

using namespace System;
using namespace System::Collections::Generic;

public ref class Student : public User {
private:
    String^ studentID;  // Managed string type
    String^ major;      // Managed string type

public:
    // Constructor
    Student(String^ id, String^ fname, String^ lname, String^ mail, String^ studID, String^ maj)
        : User(id, fname, lname, mail), studentID(studID), major(maj)
    {
    }

    // Getters
    String^ getStudentID() { return studentID; }
    String^ getMajor() { return major; }

};
