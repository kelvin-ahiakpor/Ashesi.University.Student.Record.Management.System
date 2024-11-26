#pragma once
#include "User.h"
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Student : public User {
private:
    string studentID;
    string dateOfBirth;
    string major;
    string enrollmentDate;
    vector<uint8_t> profilePicture;
    string expectedGraduation;
    enum class Status { Active, Graduated, Suspended, Withdrawn };
    Status status;

public:
    Student(const string& id, const string& fname, const string& lname, const string& mail, const string& studID, const string& dob, const string& maj, UserType& user)
        : User(id, fname, lname, mail, user), studentID(studID), dateOfBirth(dob), major(maj), status(Status::Active) {}

    // Getters
    string getStudentID() const { return studentID; }
    string getMajor() const { return major; }
    Status getStatus() const { return status; }


};
