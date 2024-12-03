#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class Course {
private:
    int^ courseID;
    String^ courseName;
    String^ departmentID;
    double^ credits;
    String^ description;
    List<String^>^ prerequisites;
    bool isActive;

    int^ year;
    String^ schedule;
    int^ maxCapacity;
    int^ offeringID;

public:
    // Constructor
    Course(int^ id, String^ name, String^ Description, double^ cred)
        : courseID(id), courseName(name), description(Description), credits(cred), isActive(true) {
        prerequisites = gcnew List<String^>();
    }

    // Existing getters
    int^ getCourseID() { return courseID; }
    String^ getCourseName() { return courseName; }
    double^ getCredits() { return credits; }
    bool getIsActive() { return isActive; }
    String^ getDescription() { return description; }

    // New getters
    String^ getDepartmentID() { return departmentID; }
    int^ getYear() { return year; }
    String^ getSchedule() { return schedule; }
    int^ getMaxCapacity() { return maxCapacity; }
    int^ getOfferingID() { return offeringID; }

    // Existing setters
    void setCourseName(String^ name) { courseName = name; }
    void setDescription(String^ desc) { description = desc; }
    void setIsActive(bool active) { isActive = active; }

    // New setters
    void setDepartmentID(String^ deptID) { departmentID = deptID; }
    void setYear(int^ yr) { year = yr; }
    void setSchedule(String^ sched) { schedule = sched; }
    void setMaxCapacity(int^ capacity) { maxCapacity = capacity; }
    void setOfferingID(int^ offID) { offeringID = offID; }

    // Existing course management methods
    bool addPrerequisite(String^ courseID) {
        if (!prerequisites->Contains(courseID)) {
            prerequisites->Add(courseID);
            return true;
        }
        return false; // Already exists
    }

    bool removePrerequisite(String^ courseID) {
        return prerequisites->Remove(courseID);
    }

    List<String^>^ getPrerequisites() { return prerequisites; }
};