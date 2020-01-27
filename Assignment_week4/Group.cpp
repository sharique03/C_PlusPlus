#include "Group.h"
#include <iostream>
#include <algorithm>
#include <fstream> 
#include <bits/stdc++.h>


Group::Group()
{

}
//deletes dynamic memory allocation
Group::~Group() 
{ 
    this->deleteAllStudents();
} 

void Group::deleteAllStudents()
{
    for (int i=0; i<this->groupOfStudents.size(); i++)
    {
        delete this->groupOfStudents[i];
        this->groupOfStudents[i]=NULL;
    }
    this->groupOfStudents.clear();
}

//shows student in groupOfStudents
void Group::showGroupOfStudents()
{
    
     int size = this->groupOfStudents.size(); 
    for (int i=0; i < size; i++)
    {
        Student *stundent=this->groupOfStudents.at(i);
        stundent->showStudent();
       
    }

}

//add student in groupOfStudents
void Group ::addStudentToGroupOfStudents(Student* myStudent)
{
    this->groupOfStudents.push_back(myStudent);
}

//remove student from groupOfStudents
void Group ::removeStudentFromGroupOfStudents(int studentNr)
{
    auto it = find_if(groupOfStudents.begin(), groupOfStudents.end(), [&studentNr](Student* obj) {return obj->getStudentNr() == studentNr;});

    if (it != groupOfStudents.end())
    {
        int index = distance(groupOfStudents.begin(), it);
        this->groupOfStudents.erase(this->groupOfStudents.begin() + index);
    }
    else
    {
        cout<<"Student number not found."<<endl;
    }    
}

//writes groupOfStudents in a file
void Group ::writeGroupOfStudentsInFile()
{
    ofstream file_obj; 
    file_obj.open("Output.txt");
    if (file_obj.is_open())
	{
        int size = this->groupOfStudents.size(); 
        for (int i=0; i < size; i++)
        {
            Student *s1=this->groupOfStudents.at(i);
            file_obj<< s1->getName()<<" "<<s1->getAge()<<" "<<s1->getStudentNr()<<s1->gradelistToString()<<"\n";
        }
    }
    file_obj.close();
    cout<<"Data has been writted to the file."<<endl;
    
}

//converts string to int
int Group::stringToInt(string s)
{
    stringstream ss(s);
    int out;
    ss>>out;
    return out;
}

//reads groupOfStudents from a file
void Group ::readGroupOfStudentsFromFile()
{

    this->deleteAllStudents();
    ifstream file_obj; 
    Student *s;
    string line;
    file_obj.open("Output.txt", ios::in); 
    while (getline(file_obj, line)) //reads each line from file_obj and puts in variable line
    {       
        istringstream lineStream(line);//read line as istringstream(avoids space)
        vector<string> listOfWords;//vector to store list of words
        do 
        { 
            string word;
            lineStream >> word;//takes word from linsStream and puts in word
            listOfWords.push_back(word);//puts word in listOfWords
        } while (lineStream);//till word is available in the line
    int age=stringToInt(listOfWords.at(1));
    int studentNr=stringToInt(listOfWords.at(2));
    s=new Student(listOfWords.at(0),age,studentNr);
    listOfWords.erase(listOfWords.begin(),listOfWords.begin()+3);//remove first three words that are taken as name, age & nr
    //iterate to capture moduleGrades
    for (int i = 0; i < listOfWords.size()-1; i+=2)
    {
        int modGrade=stringToInt(listOfWords.at(i+1));
        s->addModule(listOfWords.at(i),modGrade);
    }   
        this->groupOfStudents.push_back(s);
        s->showStudent();
        s=NULL;
    }
    delete s;
    
   
}