#pragma once
using namespace System;

public ref class User {
protected:
    int^ userID;        // Managed string type
    String^ firstName;     // Managed string type
    String^ lastName;      // Managed string type
    String^ email;         // Managed string type
    String^ password;      // Managed string type
	String^ securityAnswer; // Managed string type
	String^ profilePicturePath; // Managed string type

    enum class UserType { Student, Faculty, Administrator };

public:
    // Constructor
    User(int^ id, String^ fname, String^ lname, String^ mail)
        : userID(id), firstName(fname), lastName(lname), email(mail), securityAnswer("")
    {}

    // Destructor
    virtual ~User() {}

    // Getters
    int^ getUserID() { return userID; }
    String^ getFirstName() { return firstName; }
    String^ getLastName() { return lastName; }
    String^ getEmail() { return email; }
    String^ getSecurityAnswer() { return securityAnswer; }
    String^ getFullName() {
        return this->getFirstName() + " " + this->getLastName();
    }
	String^ getProfilePicturePath() { return profilePicturePath; }

    // Setters
    void setFirstName(String^ fname) { firstName = fname; }
    void setLastName(String^ lname) { lastName = lname; }
    void setEmail(String^ newEmail) { email = newEmail; }
    void setSecurityAnswer(String^ answer) { securityAnswer = answer; }
	void setProfilePicturePath(String^ path) { profilePicturePath = path; }

    // Password management (if needed)
    void setPassword(String^ newPassword) { password = newPassword; }
    String^ getPassword() { return password; }  // For demonstration only; consider encryption for security.

    Void login() { return; }
    Void logout() {
        // Clear sensitive data
        password = ""; //In future this will be loaded from an environment variable
    }
};
