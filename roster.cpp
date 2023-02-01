//
// Created by christian on 11/18/22.
//
#include <iostream>
#include <array>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;


Roster::Roster() {
    this->class_size = 5;
    this->index = 0;
    for (int i = 0; i < class_size; ++i) {
        this->classRosterArray[i] = new Student;
    }
}


Roster::~Roster() {
    return;
}


void Roster::add(string studentData) {

    string id, f_name, l_name, email_addr;
    int period, days_left1, days_left2, days_left3;

    if (index < class_size) {
        classRosterArray[index] = new Student();

        int i = studentData.find(',');
        id = studentData.substr(0, i);
        classRosterArray[index]->SetStudentId(id);

        int j = i + 1;
        i = studentData.find(',', j);
        f_name = studentData.substr(j, i - j);
        classRosterArray[index]->SetFirstName(f_name);

        j = i + 1;
        i = studentData.find(',', j);
        l_name = studentData.substr(j, i - j);
        classRosterArray[index]->SetLastName(l_name);

        j = i + 1;
        i = studentData.find(',', j);
        email_addr = studentData.substr(j, i - j);
        classRosterArray[index]->SetEmailAddress(email_addr);

        j = i + 1;
        i = studentData.find(',', j);
        period = stoi(studentData.substr(j, i - j));
        classRosterArray[index]->SetAge(period);

        j = i + 1;
        i = studentData.find(',', j);
        days_left1 = stoi(studentData.substr(j, i - j));

        j = i + 1;
        i = studentData.find(',', j);
        days_left2 = stoi(studentData.substr(j, i - j));

        j = i + 1;
        i = studentData.find(',', j);
        days_left3 = stoi(studentData.substr(j, i - j));
        classRosterArray[index]->SetDaysUntilFinish(days_left1, days_left2, days_left3);

        j = i + 1;
        i = studentData.find(',', j);
        string type = studentData.substr(j, i - j);
        if (type == "SECURITY") {
            classRosterArray[index]->SetDegreeProgram(SECURITY);
        }
        else if (type == "NETWORK") {
            classRosterArray[index]->SetDegreeProgram(NETWORK);
        }
        else if (type == "SOFTWARE") {
            classRosterArray[index]->SetDegreeProgram(SOFTWARE);
        }
        ++index;
    }
}


void Roster::remove(string student_id) {
    for (auto & i : classRosterArray) {
        if (i->GetStudentId() == student_id) {
            cout << "Deleting: " << i->GetStudentId() << endl;
            i->SetStudentId("invalid"); // passing string to value that expects int. Why?
            return;
        }
    }
    cout << "Error: Student was not found" << endl;
}


void Roster::printAll() {
    for (auto & i : classRosterArray) {
        if (i->GetStudentId() != "invalid") {
            cout << "\t";
            i->print();
            cout << endl;
        }
    }
}


void Roster::printAverageDaysInCourse(string student_id) {
    for (int i = 0; i < class_size; ++i) {
        if (student_id == classRosterArray[i]->GetStudentId()) {
            int x[3] = { classRosterArray[i]->GetDaysUntilFinish1(), classRosterArray[i]->GetDaysUntilFinish2(), classRosterArray[i]->GetDaysUntilFinish3() };
            double average = (x[0] + x[1] + x[2]) / 3;
            cout << "Student: " << student_id << " has an average of " << average <<" days in courses.";
        }
    }
    cout << endl;
}



void Roster::printInvalidEmails() {
    for (int i = 0; i < class_size; ++i) {
        string email = classRosterArray[i]->GetEmailAddr();
        if ((email.find(' ') != string::npos) || (email.find('.') == string::npos) || (email.find('@') == string::npos)) { // can we find a better way to do this?
            cout << classRosterArray[i]->GetStudentId() << "'s email address " << email << " is invalid.\n";
        }
    }
}


void Roster::printByDegreeProgram(degreeProgram degree_program) {
    string degreeString;
    if (degree_program == SECURITY) {
        degreeString = "SECURITY";
    }
    else if (degree_program == NETWORK) {
        degreeString = "NETWORK";
    }
    else if (degree_program == SOFTWARE) {
        degreeString = "SOFTWARE";
    }
    else if (degreeString.empty()) {
        cout << "No students found in a " << degree_program << " degree program.\n";
        return;
    }

    int numStudents = 0;
    for (int i = 0; i < class_size; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degree_program) {
            classRosterArray[i]->print();
            ++numStudents;
            cout << endl;
        }
    }


}

Student* Roster::findStudent(int i) {
    return classRosterArray[i];

}
