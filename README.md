# Ashesi University Student Record Management System

## Project Overview

This project is a University Student Management System developed using Visual C++ on Microsoft Visual Studio platform. The system supports the management of student records, course enrollment, faculty management, grade tracking, and more. It provides an intuitive user interface (UI) with multiple forms and tools, as well as the ability to interact with a backend database. The project also follows key security, performance, and usability standards.

## Functional Requirements

### 1. User Authentication

- **FR 2.1.1:** Secure login using SHA-256 encryption for passwords.
- **FR 2.1.2:** Role-based access control (RBAC) for different user types (students, faculty, administrators).
- **FR 2.1.3:** Password reset and recovery feature (not yet implemented, but planned).

### 2. Student Enrollment and Registration

- **FR 2.2.1:** Students can search and enroll in available courses using real-time search. The backend queries the database to match course names dynamically as students type.
- **FR 2.2.2:** Enrollment verification by faculty, with status updates to 'Enrolled'.

### 3. Academic Records and Grades Management

- **FR 2.3.1:** Faculty can input, edit, and submit grades for students.
- **FR 2.3.2:** Students can view their grades and transcripts (no print functionality yet).
- **FR 2.3.3:** Admins can audit and generate reports on academic performance (e.g., transcripts).

### 4. Course and Curriculum Management

- **FR 2.4.1:** Faculty can create and update course materials.
- **FR 2.4.2:** Admins can manage curricula and prerequisites. We plan to enhance this in the future with stronger prerequisite validation.
- **FR 2.4.3:** Support for online course materials and digital classrooms.

## Non-Functional Requirements

### 1. Performance

- **Search Speeds:** Indexing frequently accessed tables in the database to ensure fast search performance.
- **Scalability:** The system is designed to handle up to 10,000 concurrent users during peak times like course registration.
- **Version 2.0:** Plans for database connection pooling to reduce overhead.

### 2. Data Integrity

- **Enums for Grades and Credits:** Used to enforce valid values for grades (A+, A, B+, B, C+, C, D+, D, E, F) and credits (0.5, 1.0), ensuring consistency.

### 3. Caching

- **Profile Management Caching:** Cached profile data to reduce redundant database calls and improve page load speeds.

### 4. Memory Management

- **Pass-by-Reference:** Minimized memory overhead by passing objects between classes by reference.
- **Object Cleanup:** Used destructors to nullify objects upon user logout to avoid memory leaks.

### 5. Security

- **Data Encryption:** Encrypted sensitive data both in transit and at rest to comply with regulations like GDPR and FERPA.
- **Authentication and Authorization:** Role-based access control (RBAC) ensuring that only authorized users can access specific features.

### 6. Usability and Accessibility

- **UI Responsiveness:** Ensured that the UI is responsive and works across different desktop devices.
- **Accessibility Features:** Plans to meet WCAG 2.1 standards in a future release.

### 7. Reliability and Availability

- **Uptime:** Designed to achieve 99.9% uptime during critical academic periods.
- **Data Backups:** Two redundant, regularly backed-up databases with plans to implement fail-safe backup systems in Version 2.0.

### 8. Maintainability

- **Object-Oriented Architecture:** Modular structure for maintainability, with reusable functions like `OpenChildForm(formTypeID, User)`.
- **Soft Deletes:** Implemented soft deletes to keep historical data without cluttering active records.

## Installation

### Prerequisites

- Microsoft Visual Studio 2022
- MySQL or equivalent database server

### Steps

1. Clone this repository.
2. Open the solution in Visual Studio.
3. Build and run the solution.
4. Edit University details and icons
5. Set up the database connection (ensure the database is configured as per the `DatabaseConnection` string in the code).
6. Package the Application
7. Run the packaged application independently and use.

## License

This project is licensed under the MIT License.

## Contributing

Feel free to fork this repository and contribute by creating pull requests with enhancements or fixes. For any issues, feel free to raise them via GitHub issues.


## HOW TO LOGIN
For Admin Login: admin@ashesi.edu.gh, Password: admin123
For Faculty Login: jomens@yahoo.com, Password:password123
For User Login: hkrmanuel1.0@gmail.com, Password:password123
