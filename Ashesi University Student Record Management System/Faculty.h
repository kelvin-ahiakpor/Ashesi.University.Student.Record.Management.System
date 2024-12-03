#pragma once
#include "User.h"
#include <string>

using namespace System;

public ref class Faculty : public User {
private:
    int^ facultyID;  // Managed string type
    int^ departmentID; // Managed string type
   

public:
    // Constructor
    Faculty(int^ id, String^ fname, String^ lname, String^ mail, int^ facid, int^ departID)
        : User(id, fname, lname, mail), facultyID(facid), departmentID(departID)
    {
    }

    // Getters
    int^ getFacultyID() { return facultyID; }
    int^ getDepartmentID() { return departmentID; }
};