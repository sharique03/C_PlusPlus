/*
 * Group.h
 *
 */

#ifndef Group_H_
#define Group_H_
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class Group
{
public:
vector <Student *> groupOfStudents;
Group();
virtual~Group();

void deleteAllStudents();
void showGroupOfStudents();
void writeGroupOfStudentsInFile();
void readGroupOfStudentsFromFile();
void addStudentToGroupOfStudents(Student *myStudent);
void removeStudentFromGroupOfStudents(int studentNr);
//converts from string to int
int stringToInt(string s);

};
#endif /* Group_H_ */
