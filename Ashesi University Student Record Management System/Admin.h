#pragma once
#include "User.h"
#include <string>

using namespace System;

public ref class Admin : public User {
private:
    String^ Adminid;// Managed string typeAdmin

public:
    // Constructor
    Admin(String^ id, String^ fname, String^ lname, String^ mail)
        : User(id, fname, lname, mail)
    {
    }
    // Getters
    String^ getAdminid() { return Adminid;}
};
