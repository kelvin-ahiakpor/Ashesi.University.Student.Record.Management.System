#pragma once
#include "User.h"
#include <string>

using namespace System;

public ref class Faculty : public User {
private:
    int^ facultyID;  // Managed string type
    String^ department; // Managed string type
   

public:
    // Constructor
    Faculty(int^ id, String^ fname, String^ lname, String^ mail, int^ facID, String^ dept)
        : User(id, fname, lname, mail), facultyID(facID), department(dept)
    {
    }

    // Getters
    int^ getFacultyID() { return facultyID; }
    String^ getDepartment() { return department; }
};