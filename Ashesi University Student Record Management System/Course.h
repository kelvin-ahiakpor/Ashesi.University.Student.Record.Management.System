
// Course.h
#pragma once
#include <string>
#include <vector>

class Course {
private:
    std::string courseID;
    std::string courseName;
    std::string departmentID;
    int credits;
    std::string description;
    std::vector<std::string> prerequisites;
    bool isActive;

public:
    Course(const std::string& id, const std::string& name, const std::string& deptID,
        int credits);

    // Getters
    std::string getCourseID() const { return courseID; }
    std::string getCourseName() const { return courseName; }
    int getCredits() const { return credits; }
    bool getIsActive() const { return isActive; }

    // Setters
    void setCourseName(const std::string& name) { courseName = name; }
    void setDescription(const std::string& desc) { description = desc; }
    void setIsActive(bool active) { isActive = active; }

    // Course management
    bool addPrerequisite(const std::string& courseID);
    bool removePrerequisite(const std::string& courseID);
    std::vector<std::string> getPrerequisites() const { return prerequisites; }
};

