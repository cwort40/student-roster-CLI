#include <iostream>
#include "student.cpp"
#include "roster.cpp"

int main() {

    const string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Connor,Worthen,cwort43@wgu.edu,24,11,24,50,SOFTWARE"
    };

    cout << "C867 Scripting and Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 009867755" << endl;
    cout << "Name: Connor Worthen" << endl << endl;


    Roster* classRoster = new Roster();


   for (int i = 0; i < 5; ++i) {
       classRoster->add(studentData[i]);
   }

    classRoster->printAll();

    classRoster->printInvalidEmails();
    cout << endl;

      for (int i = 0; i < 5; ++i) { //loop through printAverageDaysInCourse()
          //classRoster->printAverageDaysInCourse(classRoster->GetStudentId());
          Student* s = classRoster->findStudent(i);
          classRoster->printAverageDaysInCourse(s->GetStudentId());
      }
      cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);

    classRoster->remove("A3");

    cout << endl;

    classRoster->printAll();

      //not an error, supposed to remove again as a requirement of PA
      //expected: the above line should print a message saying such a student with this ID was not found.
      classRoster->remove("A3");

    cout << endl;

    return 0;
}
