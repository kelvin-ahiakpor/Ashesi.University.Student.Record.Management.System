-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Dec 04, 2024 at 12:27 AM
-- Server version: 8.3.0
-- PHP Version: 8.1.2-1ubuntu2.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `kelvinsites`
--

-- --------------------------------------------------------

--
-- Table structure for table `CourseMaterials`
--

CREATE TABLE `CourseMaterials` (
  `MaterialID` int NOT NULL,
  `CourseID` int NOT NULL,
  `Title` varchar(255) NOT NULL,
  `Type` enum('Video','Assignment','Reading') DEFAULT 'Video',
  `UploadDate` date DEFAULT NULL,
  `FilePath` varchar(255) NOT NULL,
  `Description` text,
  `FacultyID` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `CourseMaterials`
--

INSERT INTO `CourseMaterials` (`MaterialID`, `CourseID`, `Title`, `Type`, `UploadDate`, `FilePath`, `Description`, `FacultyID`) VALUES
(13, 1, 'Pointers', 'Assignment', '2024-12-03', 'pointers.com', 'How to use pointers', 1),
(14, 1, 'Inheritance', 'Assignment', '2024-12-03', 'inherit.com', 'A great paradigm in OOP', 1);

-- --------------------------------------------------------

--
-- Table structure for table `CourseOfferings`
--

CREATE TABLE `CourseOfferings` (
  `OfferingID` int NOT NULL,
  `CourseID` int DEFAULT NULL,
  `FacultyID` int DEFAULT NULL,
  `Semester` enum('Fall','Spring','Summer') NOT NULL DEFAULT 'Summer',
  `Year` int NOT NULL,
  `MaxCapacity` int DEFAULT '30',
  `Schedule` varchar(100) DEFAULT NULL,
  `Status` enum('Open','Closed','Cancelled') DEFAULT 'Open'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `CourseOfferings`
--

INSERT INTO `CourseOfferings` (`OfferingID`, `CourseID`, `FacultyID`, `Semester`, `Year`, `MaxCapacity`, `Schedule`, `Status`) VALUES
(2, 2, 1006, 'Summer', 2024, 20, NULL, 'Open'),
(3, 2, 1006, 'Summer', 2024, 20, NULL, 'Open'),
(4, 1, 1006, 'Summer', 2024, 20, NULL, 'Open'),
(5, 2, 1007, 'Spring', 2024, 50, NULL, 'Open');

-- --------------------------------------------------------

--
-- Table structure for table `Courses`
--

CREATE TABLE `Courses` (
  `CourseID` int NOT NULL,
  `CourseName` varchar(100) NOT NULL,
  `DepartmentID` int DEFAULT NULL,
  `Credits` int NOT NULL,
  `Description` text,
  `PreRequisites` text,
  `IsActive` tinyint(1) DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Courses`
--

INSERT INTO `Courses` (`CourseID`, `CourseName`, `DepartmentID`, `Credits`, `Description`, `PreRequisites`, `IsActive`) VALUES
(1, 'Intermediate Programming', 1, 1, 'Programming Stuff', 'DSA, Algo', 1),
(2, 'Data Structures And Algorithms', 1, 1, 'Java', 'Introduction To OOP', 1),
(3, 'Principles Of Economics', 9, 1, 'Econs Subject', 'None', 1),
(4, 'Circuit Design ', 2, 1, 'None', 'None', 1);

-- --------------------------------------------------------

--
-- Table structure for table `Departments`
--

CREATE TABLE `Departments` (
  `DepartmentID` int NOT NULL,
  `DepartmentName` varchar(100) NOT NULL,
  `HeadOfDepartment` varchar(20) DEFAULT NULL,
  `CreatedAt` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Departments`
--

INSERT INTO `Departments` (`DepartmentID`, `DepartmentName`, `HeadOfDepartment`, `CreatedAt`) VALUES
(1, 'Computer Science', 'Dr. Alice Johnson', '2022-01-15 22:30:00'),
(2, 'Electrical Engineering', 'Dr. Mark Spencer', '2021-09-21 02:00:00'),
(3, 'Mechanical Engineering', 'Dr. Linda Thompson', '2021-05-10 21:45:00'),
(4, 'Civil Engineering', 'Dr. John Roberts', '2020-11-01 20:20:00'),
(5, 'Business Administration', 'Dr. Sarah Wilson', '2022-03-13 01:15:00'),
(6, 'Psychology', 'Dr. Emily Davis', '2020-07-26 04:45:00'),
(7, 'Biology', 'Dr. Michael Brown', '2019-02-18 23:10:00'),
(8, 'Mathematics', 'Dr. Susan Miller', '2019-12-08 22:00:00'),
(9, 'Economics', 'Dr. Anthony White', '2023-04-23 05:30:00'),
(10, 'Fine Arts', 'Dr. Catherine Green', '2021-06-15 03:50:00');

-- --------------------------------------------------------

--
-- Table structure for table `Enrollments`
--

CREATE TABLE `Enrollments` (
  `EnrollmentID` int NOT NULL,
  `StudentID` int DEFAULT NULL,
  `CourseID` int NOT NULL,
  `OfferingID` int DEFAULT NULL,
  `EnrollmentDate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `Grade` enum('A+','A','B+','B','C+','C','D+','D','E','F') DEFAULT NULL,
  `GradePoints` decimal(3,2) DEFAULT NULL,
  `Status` enum('Enrolled','Withdrawn','Pending') DEFAULT 'Pending'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `Faculty`
--

CREATE TABLE `Faculty` (
  `FacultyID` int NOT NULL,
  `UserID` int NOT NULL,
  `DepartmentID` int NOT NULL,
  `DateOfAppointment` date NOT NULL,
  `Title` varchar(50) DEFAULT NULL,
  `Status` enum('Active','On Leave','Retired') DEFAULT 'Active',
  `IsDeleted` tinyint(1) DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Faculty`
--

INSERT INTO `Faculty` (`FacultyID`, `UserID`, `DepartmentID`, `DateOfAppointment`, `Title`, `Status`, `IsDeleted`) VALUES
(1, 5, 1, '2024-12-02', NULL, 'Active', 0),
(1004, 28, 2, '2024-12-03', NULL, 'Active', 0),
(1005, 31, 2, '2024-12-03', NULL, 'Active', 0),
(1006, 33, 1, '2024-12-02', NULL, 'Active', 0),
(1007, 34, 1, '2024-12-02', NULL, 'Active', 0),
(1008, 35, 2, '2024-12-03', NULL, 'Active', 0),
(1009, 36, 2, '2024-12-03', NULL, 'Active', 0),
(1010, 37, 2, '2024-12-03', NULL, 'Active', 0),
(1011, 38, 5, '2024-12-03', NULL, 'Active', 0),
(1012, 39, 5, '2024-12-03', NULL, 'Active', 0),
(1013, 40, 5, '2024-12-03', NULL, 'Active', 0),
(1014, 41, 6, '2024-12-03', NULL, 'Active', 0);

-- --------------------------------------------------------

--
-- Table structure for table `Students`
--

CREATE TABLE `Students` (
  `StudentID` int NOT NULL,
  `UserID` int NOT NULL,
  `DateOfBirth` date NOT NULL,
  `DepartmentID` int DEFAULT NULL,
  `EnrollmentDate` date NOT NULL,
  `ProfilePicture` varchar(255) DEFAULT NULL,
  `ExpectedGraduation` date DEFAULT NULL,
  `Status` enum('Active','Graduated','Suspended','Withdrawn') DEFAULT 'Active',
  `IsDeleted` tinyint(1) DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Students`
--

INSERT INTO `Students` (`StudentID`, `UserID`, `DateOfBirth`, `DepartmentID`, `EnrollmentDate`, `ProfilePicture`, `ExpectedGraduation`, `Status`, `IsDeleted`) VALUES
(1002, 2, '2024-11-27', 6, '2024-11-27', NULL, '2026-06-26', 'Active', 0),
(1005, 8, '2000-11-10', 1, '2023-11-06', NULL, '2026-06-18', 'Active', 0),
(1008, 12, '2024-11-27', 6, '2024-11-27', NULL, '2026-06-26', 'Active', 1),
(1009, 14, '2024-03-01', 10, '2005-07-06', NULL, '2026-06-24', 'Active', 0),
(1010, 16, '2024-03-01', 10, '2004-04-01', NULL, '2025-03-01', 'Active', 0),
(1011, 17, '2024-03-01', 9, '2004-02-04', NULL, '2027-04-01', 'Active', 0),
(1012, 20, '2024-03-01', 3, '2004-02-04', NULL, '2026-07-01', 'Active', 0),
(1013, 21, '2024-03-01', 3, '2004-02-04', NULL, '2026-07-01', 'Active', 0),
(1014, 27, '2024-12-03', 2, '2024-10-08', NULL, '2026-02-19', 'Active', 0),
(1015, 32, '2024-12-03', 5, '2024-12-03', NULL, '2024-12-03', 'Active', 0);

-- --------------------------------------------------------

--
-- Table structure for table `Users`
--

CREATE TABLE `Users` (
  `UserID` int NOT NULL,
  `FirstName` varchar(50) NOT NULL,
  `LastName` varchar(50) NOT NULL,
  `Email` varchar(100) NOT NULL,
  `Password` varchar(255) NOT NULL,
  `UserType` enum('Student','Faculty','Administrator') NOT NULL,
  `CreatedAt` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `LastLogin` timestamp NULL DEFAULT NULL,
  `IsActive` tinyint(1) DEFAULT '1',
  `IsDeleted` tinyint(1) DEFAULT '0',
  `SecurityAnswer` varchar(255) DEFAULT NULL,
  `Image` varchar(500) CHARACTER SET latin1 COLLATE latin1_swedish_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Users`
--

INSERT INTO `Users` (`UserID`, `FirstName`, `LastName`, `Email`, `Password`, `UserType`, `CreatedAt`, `LastLogin`, `IsActive`, `IsDeleted`, `SecurityAnswer`, `Image`) VALUES
(2, 'Kelvin', 'Ahiakpor', 'kelvin.ahiakpor08@gmail.com', 'c4235fbb30dbfb8786e55b8ad8c7b6012fc7e8580a53170dc22c97a074ec98a4', 'Student', '2024-11-28 11:36:12', NULL, 1, 0, '6d5cd9b9dc38850a4f9c332f03d30243d26d82bbb036706d342a2c9f9aa7acb8', '\\\\Mac\\Home\\Documents\\AshesiUniversity\\ProfileImages\\ashesi-logo-black.png'),
(3, 'Emmanuel', 'Ntow', 'admin@ashesi.edu.gh', '240be518fabd2724ddb6f04eeb1da5967448d7e831c08c8fa822809f74c720a9', 'Administrator', '2024-11-28 12:02:38', NULL, 1, 0, '6d5cd9b9dc38850a4f9c332f03d30243d26d82bbb036706d342a2c9f9aa7acb8', NULL),
(5, 'Joseph', 'Mensah', 'jomens@yahoo.com', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Faculty', '2024-12-02 21:45:41', NULL, 1, 0, '6d5cd9b9dc38850a4f9c332f03d30243d26d82bbb036706d342a2c9f9aa7acb8', NULL),
(8, 'Emmanuel', 'Acquaye', 'hkrmanuel1.0@gmail.com', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Student', '2024-12-03 00:37:42', NULL, 1, 0, '6d5cd9b9dc38850a4f9c332f03d30243d26d82bbb036706d342a2c9f9aa7acb8', '\\\\Mac\\Home\\Documents\\AshesiUniversity\\ProfileImages\\ashesi-logo-black.png'),
(12, 'Joel', 'Ahiakpor', 'kelvin.ahiakpor@gmail.com', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Student', '2024-12-03 01:25:50', NULL, 1, 1, NULL, NULL),
(14, 'Jason', 'Statum', 'jasonstatum@gmail.com', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Student', '2024-12-03 18:47:25', NULL, 1, 0, NULL, NULL),
(16, 'Daniel', 'Ofori', 'danielofori@gmail.com', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Student', '2024-12-03 18:49:27', NULL, 1, 0, NULL, NULL),
(17, 'Densi', 'Demitrus', 'demiboy@ashesi.edu,gh', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Student', '2024-12-03 18:51:49', NULL, 1, 0, NULL, NULL),
(18, 'Jude', 'Salia', 'judie@yahoo.com', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Student', '2024-12-03 18:52:41', NULL, 1, 0, NULL, NULL),
(20, 'Jude', 'Salia', 'judie@gmail.com', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Student', '2024-12-03 18:53:29', NULL, 1, 0, NULL, NULL),
(21, 'Christopher ', 'Robbins', 'chrisrobbins@gmail.com', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Student', '2024-12-03 18:54:04', NULL, 1, 0, NULL, NULL),
(27, 'Freddie', 'Gibbs', 'freddie@gmail.com', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Student', '2024-12-03 18:56:30', NULL, 1, 0, NULL, NULL),
(28, 'Tatenda', 'Kavu', 'tatenda@gmail.com', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 19:04:40', NULL, 1, 0, NULL, NULL),
(31, 'Don', 'Toliver', 'donny@womack3.com', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 19:29:49', NULL, 1, 0, NULL, NULL),
(32, 'Tyla', 'Swish', 'tyla@gmail.com', 'ef92b778bafe771e89245b89ecbc08a44a4e166c06659911881f383d4473e94f', 'Student', '2024-12-03 19:39:48', NULL, 1, 0, NULL, NULL),
(33, 'Victor ', 'Mensah', 'vic.men@yahoo.com', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 22:05:25', NULL, 1, 0, NULL, NULL),
(34, 'Jesse ', 'Houston', 'jess.houston@ashesi.edu,gh', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 22:06:55', NULL, 1, 0, NULL, NULL),
(35, 'Kevin', 'Nkrumah', 'kevin@gmail.com', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 23:18:42', NULL, 1, 0, NULL, NULL),
(36, 'Myles', 'Sonola', 'sonal@gmail.com', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 23:18:56', NULL, 1, 0, NULL, NULL),
(37, 'Sofia', 'Okeyere', 'sofia@gmail.com', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 23:19:10', NULL, 1, 0, NULL, NULL),
(38, 'Papa', 'T', 'papat@gmail.com', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 23:19:27', NULL, 1, 0, NULL, NULL),
(39, 'James', 'Brown', 'jamest@gmail.com', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 23:19:45', NULL, 1, 0, NULL, NULL),
(40, 'Arnold', 'Wood', 'arndod@gmail.com', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 23:20:04', NULL, 1, 0, NULL, NULL),
(41, 'Jake', 'Pail', 'jake@gmail.com', '008c70392e3abfbd0fa47bbc2ed96aa99bd49e159727fcba0f2e6abeb3a9d601', 'Faculty', '2024-12-03 23:20:21', NULL, 1, 0, NULL, NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `CourseMaterials`
--
ALTER TABLE `CourseMaterials`
  ADD PRIMARY KEY (`MaterialID`),
  ADD KEY `CourseID` (`CourseID`),
  ADD KEY `FacultyID` (`FacultyID`);

--
-- Indexes for table `CourseOfferings`
--
ALTER TABLE `CourseOfferings`
  ADD PRIMARY KEY (`OfferingID`),
  ADD KEY `CourseID` (`CourseID`),
  ADD KEY `FacultyID` (`FacultyID`);

--
-- Indexes for table `Courses`
--
ALTER TABLE `Courses`
  ADD PRIMARY KEY (`CourseID`),
  ADD KEY `DepartmentID` (`DepartmentID`);

--
-- Indexes for table `Departments`
--
ALTER TABLE `Departments`
  ADD PRIMARY KEY (`DepartmentID`);

--
-- Indexes for table `Enrollments`
--
ALTER TABLE `Enrollments`
  ADD PRIMARY KEY (`EnrollmentID`),
  ADD KEY `StudentID` (`StudentID`),
  ADD KEY `OfferingID` (`OfferingID`),
  ADD KEY `fk_Enrollemts_courseID` (`CourseID`);

--
-- Indexes for table `Faculty`
--
ALTER TABLE `Faculty`
  ADD PRIMARY KEY (`FacultyID`),
  ADD UNIQUE KEY `UserID` (`UserID`),
  ADD KEY `DepartmentID` (`DepartmentID`);

--
-- Indexes for table `Students`
--
ALTER TABLE `Students`
  ADD PRIMARY KEY (`StudentID`),
  ADD UNIQUE KEY `UserID` (`UserID`),
  ADD KEY `DepartmentID` (`DepartmentID`);

--
-- Indexes for table `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`UserID`),
  ADD UNIQUE KEY `Email` (`Email`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `CourseMaterials`
--
ALTER TABLE `CourseMaterials`
  MODIFY `MaterialID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `CourseOfferings`
--
ALTER TABLE `CourseOfferings`
  MODIFY `OfferingID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `Courses`
--
ALTER TABLE `Courses`
  MODIFY `CourseID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `Departments`
--
ALTER TABLE `Departments`
  MODIFY `DepartmentID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `Enrollments`
--
ALTER TABLE `Enrollments`
  MODIFY `EnrollmentID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `Faculty`
--
ALTER TABLE `Faculty`
  MODIFY `FacultyID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1015;

--
-- AUTO_INCREMENT for table `Students`
--
ALTER TABLE `Students`
  MODIFY `StudentID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1016;

--
-- AUTO_INCREMENT for table `Users`
--
ALTER TABLE `Users`
  MODIFY `UserID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=42;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `CourseMaterials`
--
ALTER TABLE `CourseMaterials`
  ADD CONSTRAINT `CourseMaterials_ibfk_1` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`),
  ADD CONSTRAINT `CourseMaterials_ibfk_2` FOREIGN KEY (`FacultyID`) REFERENCES `Faculty` (`FacultyID`);

--
-- Constraints for table `CourseOfferings`
--
ALTER TABLE `CourseOfferings`
  ADD CONSTRAINT `CourseOfferings_ibfk_1` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `CourseOfferings_ibfk_2` FOREIGN KEY (`FacultyID`) REFERENCES `Faculty` (`FacultyID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Courses`
--
ALTER TABLE `Courses`
  ADD CONSTRAINT `Courses_ibfk_1` FOREIGN KEY (`DepartmentID`) REFERENCES `Departments` (`DepartmentID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Enrollments`
--
ALTER TABLE `Enrollments`
  ADD CONSTRAINT `Enrollments_ibfk_1` FOREIGN KEY (`StudentID`) REFERENCES `Students` (`StudentID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Enrollments_ibfk_2` FOREIGN KEY (`OfferingID`) REFERENCES `CourseOfferings` (`OfferingID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `fk_Enrollemts_courseID` FOREIGN KEY (`CourseID`) REFERENCES `Courses` (`CourseID`);

--
-- Constraints for table `Faculty`
--
ALTER TABLE `Faculty`
  ADD CONSTRAINT `Faculty_ibfk_1` FOREIGN KEY (`UserID`) REFERENCES `Users` (`UserID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Faculty_ibfk_2` FOREIGN KEY (`DepartmentID`) REFERENCES `Departments` (`DepartmentID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Students`
--
ALTER TABLE `Students`
  ADD CONSTRAINT `Students_ibfk_1` FOREIGN KEY (`UserID`) REFERENCES `Users` (`UserID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Students_ibfk_2` FOREIGN KEY (`DepartmentID`) REFERENCES `Departments` (`DepartmentID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
