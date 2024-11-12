
// CourseOffering.h
#pragma once
#include <string>

class CourseOffering {
private:
    std::string offeringID;
    std::string courseID;
    std::string facultyID;
    enum class Semester { Fall, Spring, Summer };
    Semester semester;
    int year;
    int maxCapacity;
    std::string schedule;
    std::string room;
    enum class Status { Open, Closed, Cancelled };
    Status status;

public:
    CourseOffering(const std::string& offID, const std::string& courseID,
        const std::string& facID, Semester sem, int year);

    // Getters
    std::string getOfferingID() const { return offeringID; }
    std::string getCourseID() const { return courseID; }
    Status getStatus() const { return status; }
    int getMaxCapacity() const { return maxCapacity; }

    // Setters
    void setSchedule(const std::string& sched) { schedule = sched; }
    void setRoom(const std::string& r) { room = r; }
    void setStatus(Status s) { status = s; }

    // Capacity management
    bool hasAvailableSpace() const;
    bool incrementEnrollment();
    bool decrementEnrollment();
};

