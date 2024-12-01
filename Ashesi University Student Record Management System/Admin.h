#pragma once
#include "User.h"
#include <string>

using namespace System;

public ref class Admin : public User {

public:
    // Constructor
    Admin(int^ id, String^ fname, String^ lname, String^ mail)
        : User(id, fname, lname, mail)
    {
    }

    Void login() { return; }
    Void logout() { return; }

};
