#pragma once
#include <string>
#include <ctime>
using namespace std;

class User {
protected:
    string userID;
    string firstName;
    string lastName;
    string email;
    string password;
    enum class UserType { Student, Faculty, Administrator };

public:
    User(const string& id, const string& fname, const string& lname, const string& mail)
        : userID(id), firstName(fname), lastName(lname), email(mail)
        {}

    virtual ~User() = default;

    // Getters
    string getUserID() const { return userID; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getEmail() const { return email; }

    // Setters
    void setFirstName(const string& fname) { firstName = fname; }
    void setLastName(const string& lname) { lastName = lname; }
    void setEmail(const string& newEmail) { email = newEmail; }

};

