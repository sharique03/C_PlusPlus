#include "Student.h"
#include <iostream>


Student::Student(string s, int age, int nr):Person(s, age)
{
    this->studentNumber = nr;
}
Student::Student()
{

}

//copy constructor
Student::Student(const Student &myStudent): Person(myStudent)
{
    cout<<"Student created using copy constructor"<<endl;
    this->studentNumber=myStudent.studentNumber;
    int size = myStudent.gradeList.size(); 
    for (int i=0; i < size; i++)
    {
    ModuleGrade *mg;
    mg = new ModuleGrade(*(myStudent.gradeList[i]));
    this->gradeList.push_back(mg);
    } 
}
//copy using operator = overload
Student& Student::operator=(const Student &myStudent)
{
    cout<<"Student created using operator = overload"<<endl;
    if (&myStudent == this) return *this;
	this->studentNumber = myStudent.studentNumber;
    Person::operator=(myStudent);
	for (int i=0;i<this->gradeList.size();i++)
		delete this->gradeList[i];
	this->gradeList.clear();
	for (int i=0;i<myStudent.gradeList.size();i++)
	{
		ModuleGrade *mg = new ModuleGrade(*(myStudent.gradeList[i]));
		this->gradeList.push_back(mg);
	}
	return *this;
}

//deletes deleteAllgrades
Student::~Student() 
{ 
    this->deleteAllgrades();
} 

void Student::deleteAllgrades()
{
    for (int i=0; i<this->gradeList.size(); i++)
    {
        delete this->gradeList[i];
        this->gradeList[i]=NULL;
    }
    this->gradeList.clear();

}
//returns studentNumber
int Student::getStudentNr()
{
    return this->studentNumber;
}

//shows Student details
void Student::showStudent()
{
    cout << "\n---------Details of Student Number : "<<this->getStudentNr()<<"---------"<< endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Number: " << this->getStudentNr() << endl;
    this->showGradelist();
}

//add module to student's gradelist
void Student::addModule(string modName, int modGrade)
{
    ModuleGrade* mod = new ModuleGrade(modName, modGrade);
    this->gradeList.push_back(mod);
}

//shows gradelist
void Student::showGradelist()
{

   for(int i=0;i<this->gradeList.size();i++)
    {
        ModuleGrade *mg= this->gradeList.at(i);
        mg->showModule();      
    }
   
}

//retuns gradeList as a string
string Student::gradelistToString()
{
    string temp;
    for(int i=0;i<this->gradeList.size();i++)
    {
        ModuleGrade *mg= this->gradeList.at(i);
        temp=temp+" "+mg->ToString();        
    }
    return temp;
}


