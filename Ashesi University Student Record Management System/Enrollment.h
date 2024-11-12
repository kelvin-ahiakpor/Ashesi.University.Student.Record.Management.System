// Enrollment.h
#pragma once
#include <string>
#include <ctime>

class Enrollment {
private:
    std::string enrollmentID;
    std::string studentID;
    std::string offeringID;
    time_t enrollmentDate;
    std::string grade;
    float gradePoints;
    enum class Status { Enrolled, Withdrawn, Completed };
    Status status;
    time_t lastUpdated;

public:
    Enrollment(const std::string& enrollID, const std::string& studID,
        const std::string& offID);

    // Getters
    std::string getEnrollmentID() const { return enrollmentID; }
    std::string getGrade() const { return grade; }
    float getGradePoints() const { return gradePoints; }
    Status getStatus() const { return status; }

    // Grade management
    bool setGrade(const std::string& grade);
    bool withdraw();
    bool complete();
};

