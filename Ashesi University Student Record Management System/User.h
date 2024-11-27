#pragma once
using namespace System;

public ref class User {
protected:
    String^ userID;        // Managed string type
    String^ firstName;     // Managed string type
    String^ lastName;      // Managed string type
    String^ email;         // Managed string type
    String^ password;      // Managed string type

    enum class UserType { Student, Faculty, Administrator };

public:
    // Constructor
    User(String^ id, String^ fname, String^ lname, String^ mail)
        : userID(id), firstName(fname), lastName(lname), email(mail)
    {}

    // Destructor
    virtual ~User() {}

    // Getters
    String^ getUserID() { return userID; }
    String^ getFirstName() { return firstName; }
    String^ getLastName() { return lastName; }
    String^ getEmail() { return email; }

    // Setters
    void setFirstName(String^ fname) { firstName = fname; }
    void setLastName(String^ lname) { lastName = lname; }
    void setEmail(String^ newEmail) { email = newEmail; }

    // Password management (if needed)
    void setPassword(String^ newPassword) { password = newPassword; }
    String^ getPassword() { return password; }  // For demonstration only; consider encryption for security.
};
