# student-roster-cli

This project is a C++ program that manages student information using a Roster system.

## Requirements

- C++11
- Integrated development environment (IDE)

## Usage

1. Download or clone the repository.
2. Open the project in your IDE.
3. Build and run the application.

## Project Specifications

### A. Modify the “studentData Table” to include your personal information as the last item.

### B. Files

The project consists of the following files:

- degree.h
- student.h and student.cpp
- roster.h and roster.cpp
- main.cpp

### C. Enum

The DegreeProgram data type contains the following values:

- SECURITY
- NETWORK
- SOFTWARE

This information is included in the degree.h file.

### D. Student Class

The Student class in student.h and student.cpp includes the following variables:

- Student ID
- First Name
- Last Name
- Email Address
- Age
- Array of Number of Days to Complete Each Course
- Degree Program

The class has the following functions:

- Accessor (i.e., getter) for each instance variable
- Mutator (i.e., setter) for each instance variable
- Constructor using all of the input parameters provided in the table
- Print() to print specific student data

### E. Roster Class

The Roster class in roster.cpp has an array of pointers to hold the data provided in the “studentData Table.” It creates a student object for each student in the data table and populates classRosterArray. It has the following functions:

- add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables and updates the roster.
- remove(string studentID) that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
- printAll() that prints a complete tab-separated list of student data.
- printAverageDaysInCourse(string studentID) that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
- printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
- printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.

### F. Main Function

The main function in main.cpp demonstrates the program’s required functionality. It does the following:

- Prints out the course title, programming language used, student ID, and name.
- Creates an instance of the Roster class called classRoster.
- Adds each student to classRoster.
- Calls the printAll() function to print all student data.
- Calls the printInvalidEmails() function to print invalid email addresses.
- Calls the printAverageDaysInCourse() function to print the average number of days in the three courses for each student.
- Calls the printByDegreeProgram() function to print student information for a specific degree program.
- Calls the remove() function to remove a student.
- Calls the printAll() function to print all student data.
- Calls the remove() function to remove a non-existent student.

### G. Memory Management

The Roster class has a destructor to release the memory that was allocated dynamically in Roster.
