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
    UserType userType;
    time_t createdAt;
    time_t lastLogin;
    bool isActive;

public:
    User(const string& id, const string& fname, const string& lname,
        const string& email);
    virtual ~User() = default;

    // Getters
    string getUserID() const { return userID; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getEmail() const { return email; }
    bool getIsActive() const { return isActive; }

    // Setters
    void setFirstName(const string& fname) { firstName = fname; }
    void setLastName(const string& lname) { lastName = lname; }
    void setEmail(const string& newEmail) { email = newEmail; }
    void setIsActive(bool active) { isActive = active; }

    // Virtual functions
    virtual bool login(const string& password) = 0;
    virtual bool logout() = 0;
    virtual bool updateProfile() = 0;
};

