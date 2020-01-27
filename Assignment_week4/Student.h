/*
 * Student.h
 *
 */

#ifndef Student_H_
#define Student_H_
#include <string>
#include <vector>
#include "Person.h"
#include "ModuleGrade.h"


using namespace std;

class Student:public Person
{
private:
int studentNumber;
vector <ModuleGrade *> gradeList;


public:
Student(string s, int age, int nr);
Student();
//copy constructor
Student(const Student &myStudent);
//operator= overload
Student& operator=(const Student &myStudent);

~Student();

int getStudentNr();
void showStudent();

void deleteAllgrades();
void addModule(string modName, int modGrade);
void showGradelist();
string gradelistToString();

};


#endif /* Student_H_ */
