// DatabaseManager.h
#pragma once
#include <mysql/mysql.h>
#include <memory>
#include <string>
#include "Course.h"
#include "User.h"
#include "Enrollment.h"
#include "Faculty.h"
#include "CourseOffering.h"
#include "Student.h"






class DatabaseManager {
private:
    MYSQL* conn;
    static DatabaseManager* instance;
    DatabaseManager(); // Private constructor for singleton

public:
    static DatabaseManager* getInstance();
    ~DatabaseManager();

    // Connection management
    bool connect(const std::string& host, const std::string& user,
        const std::string& password, const std::string& database);

    void disconnect();

    // Generic query methods
    bool executeQuery(const std::string& query);
    MYSQL_RES* executeSelect(const std::string& query);

    // Specific database operations
    bool insertUser(const User& user);
    bool updateUser(const User& user);
    bool deleteUser(const std::string& userID);
    bool insertStudent(const Student& student);
    bool insertFaculty(const Faculty& faculty);
    bool insertCourse(const Course& course);
    bool insertEnrollment(const Enrollment& enrollment);
};

