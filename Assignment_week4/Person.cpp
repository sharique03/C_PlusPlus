#include "Person.h"
#include <iostream>


Person::Person(void)
{
}
Person::Person(string name, int age)
{
    this->name = name;
    this->age = age;               
}
string Person::getName()
{
    return this->name;
}
int Person::getAge()
{
    return this->age;
}

Person::Person(const Person &myPerson)
{
    cout<<"Person created using copy constructor"<<endl;
    this->name=myPerson.name;
    this->age=myPerson.age;
}

Person& Person:: operator=(const Person &myPerson)
{
    cout<<"Person created using operator = overload"<<endl;
    if (&myPerson == this) return *this;
    this->name=myPerson.name;
    this->age=myPerson.age;
    return *this;
}

