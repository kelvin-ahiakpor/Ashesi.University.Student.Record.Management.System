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

public:
    // Constructor
    Course(int^ id, String^ name, String^ Description, double^ cred)
        : courseID(id), courseName(name), description(Description), credits(cred), isActive(true) {
        prerequisites = gcnew List<String^>();  
    }

    // Getters
    int^ getCourseID() { return courseID; }
    String^ getCourseName() { return courseName; }
    double^ getCredits() { return credits; }
    bool getIsActive() { return isActive; }
	String^ getDescription() { return description; }

    // Setters
    void setCourseName(String^ name) { courseName = name; }
    void setDescription(String^ desc) { description = desc; }
    void setIsActive(bool active) { isActive = active; }

    // Course management
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
