
// Faculty.h
#pragma once
#include "User.h"
#include <vector>
using namespace std;


class Faculty : public User {
private:
    string facultyID;
    string department;
    string dateOfAppointment;
    string title;
    enum class Status { Active, OnLeave, Retired };
    Status status;
    vector<string> teachingCourses;

public:
    Faculty(const string& id, const string& fname, const string& lname,
        const string& email, const string& dept, const string& title);

    // Getters
    string getFacultyID() const { return facultyID; }
    string getDepartment() const { return department; }
    string getTitle() const { return title; }
    Status getStatus() const { return status; }

    // Course management methods
    bool assignGrade(const string& studentID, const string& courseID,
        const string& grade);
    bool viewClassRoster(const string& courseID) const;
    bool addCourse(const string& courseID);
    bool removeCourse(const string& courseID);

    // Override virtual functions
    bool login(const string& password) override;
    bool logout() override;
    bool updateProfile() override;
};
