//
// Created by christian on 11/18/22.
//

#ifndef NEW_C867_ROSTER_H
#define NEW_C867_ROSTER_H

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include <array>
using namespace std;

//Roster class header file and declarations

class Roster {
public:
    Roster();
    void add(string studentData);
    void remove(string studentId);
    void printAll();
    void printAverageDaysInCourse(string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(degreeProgram degree_program);
    Student* findStudent(int index);
    ~Roster();

private:
    Student* classRosterArray[5];
    int class_size;
    int index;

};

#endif //NEW_C867_ROSTER_H
