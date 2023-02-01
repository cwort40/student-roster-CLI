//
// Created by christian on 11/18/22.
//

#ifndef NEW_C867_STUDENT_H
#define NEW_C867_STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

//Student class header file and declarations

class Student {
public:
    Student();
    void SetStudentId(string id);
    void SetFirstName(string f_name);
    void SetLastName(string l_name);
    void SetEmailAddress(string email_addr);
    void SetAge(int period);
    void SetDaysUntilFinish(int days_left1, int days_left2, int days_left3);
    void SetDegreeProgram(degreeProgram program);
    string GetStudentId();
    string GetFirstName();
    string GetLastName();
    string GetEmailAddr();
    int GetAge();
    int GetDaysUntilFinish1();
    int GetDaysUntilFinish2();
    int GetDaysUntilFinish3();
    degreeProgram GetDegreeProgram();
    void print();

private:
    string student_id;
    string first_name;
    string last_name;
    string email_address;
    int age;
    int days_until_finish[3];
    degreeProgram degree_program;
};

#endif //NEW_C867_STUDENT_H
