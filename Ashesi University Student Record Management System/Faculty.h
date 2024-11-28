#pragma once
#include "User.h"
#include <string>

using namespace System;

public ref class Faculty : public User {
private:
    String^ facultyID;  // Managed string type
    String^ department; // Managed string type

public:
    // Constructor
    Faculty(String^ id, String^ fname, String^ lname, String^ mail, String^ facID, String^ dept)
        : User(id, fname, lname, mail), facultyID(facID), department(dept)
    {
    }

    // Getters
    String^ getFacultyID() { return facultyID; }
    String^ getDepartment() { return department; }
};