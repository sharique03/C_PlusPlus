/*
 * Person.h
 *
 */

#ifndef Person_H_
#define Person_H_
#include <string>
using namespace std;

class Person
{
private:
string name;
int age; 

public:
Person(void);
/* post: a Person object is created*/
Person(string s, int age);
/* post: a Person object is created, with name and age*/

//operator= overload
Person& operator=(const Person &myPerson);

//copy constructor
Person(const Person &myPerson);

string getName();
int getAge();

};


#endif /* Person_H_ */
