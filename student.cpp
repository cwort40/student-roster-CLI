//
// Created by christian on 11/18/22.
//

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;
#include "student.h"

// constructor
Student::Student() {
    this->student_id = "";
    this->first_name = "";
    this->last_name = "";
    this->email_address = "";
    this->age = 0;
    this->days_until_finish[0] = 0;
    this->days_until_finish[1] = 0;
    this->days_until_finish[2] = 0;
    this->degree_program;
};

// setter methods
void Student::SetStudentId(string id) {
    this->student_id = id;
}

void Student::SetFirstName(string f_name) {
    this->first_name = f_name;
}

void Student::SetLastName(string l_name) {
    this->last_name = l_name;
}

void Student::SetEmailAddress(string email_addr) {
    this->email_address = email_addr;
}

void Student::SetAge(int period) {
    this->age = period;
}

void Student::SetDaysUntilFinish(int days_left1, int days_left2, int days_left3) {
    this->days_until_finish[0] = days_left1;
    this->days_until_finish[1] = days_left2;
    this->days_until_finish[2] = days_left3;
}

void Student::SetDegreeProgram(degreeProgram program) {
    this->degree_program = program;
}

// getter methods
string Student::GetStudentId() {
    return student_id;
}

string Student::GetFirstName() {
    return first_name;
}

string Student::GetLastName() {
    return last_name;
}

string Student::GetEmailAddr() {
    return email_address;
}

int Student::GetAge() {
    return age;
}

// can we centralize these 1-3 into 1 function???
int Student::GetDaysUntilFinish1() {
    return days_until_finish[0];
}
int Student::GetDaysUntilFinish2() {
    return days_until_finish[1];
}
int Student::GetDaysUntilFinish3() {
    return days_until_finish[2];
}

degreeProgram Student::GetDegreeProgram() {
    return degree_program;
}


void Student::print() {
    int tempday1 = GetDaysUntilFinish1();
    int tempday2 = GetDaysUntilFinish2();
    int tempday3 = GetDaysUntilFinish3();

    string matching_program;
    if (GetDegreeProgram() == degreeProgram::SOFTWARE) {
        matching_program = "Software";
    }
    else if (GetDegreeProgram() == degreeProgram::NETWORK) {
        matching_program = "Network";
    }
    else if (GetDegreeProgram() == degreeProgram::SECURITY) {
        matching_program = "Security";
    }

    cout << "Student ID: " << GetStudentId() << endl;
    cout << "First Name: " << GetFirstName() << endl;
    cout << " Last Name: " << GetLastName() << endl;
    cout << "Student Age: " << GetAge() << endl;
    cout << "Days In Courses: {" << tempday1 << ", " << tempday2 << ", " << tempday3 << "}." << endl;
    cout << "Degree Program: " << matching_program << '.' << endl;
}