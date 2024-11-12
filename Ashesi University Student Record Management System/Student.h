#pragma once
#include "User.h"
#include <vector>
#include <memory>
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
    Student(const string& id, const string& fname, const string& lname,
        const string& email, const string& dob, const string& major);

    // Getters
    string getStudentID() const { return studentID; }
    string getMajor() const { return major; }
    Status getStatus() const { return status; }

    // Course-related methods
    bool enrollInCourse(const string& courseID);
    bool withdrawFromCourse(const string& courseID);
    float getGPA() const;
    vector<pair<string, string>> getGrades() const; // Course ID, Grade
    bool viewTranscript() const;

    // Override virtual functions
    bool login(const string& password) override;
    bool logout() override;
    bool updateProfile() override;
};

