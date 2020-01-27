#include "Student.h"
#include "Group.h"
#include <iostream>
#include<limits> 
#include <string>    



void showSubMenu(Student *myStudent)
{
    bool subMenuLoop=true;
    Student *copyStudent;
    Student studentviaOperatorOverload;
    while(subMenuLoop)
	{
        int userOption;
        cout << ("\n===========SUBMENU================");    
        cout << ("\n[1] Add Module.");
        cout << ("\n[2] Show Gradelist.");
        cout << ("\n[3] Copy student via copy constructor.");
        cout << ("\n[4] Copy student via overator= overload.");
        cout << ("\n[5] Exit to main menu.");
        cout << ("\n\nChoice : ");
        cin >> userOption;
        //ignores parse error by clearing the error flag
        cin.clear();
        //clears buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        string modName;
        int modGrade;        
        switch (userOption)
        {
        case 1:
            cout << ("\nEnter Module Name:");
            cin >> modName;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << ("\nEnter Module Grade:");
            cin >> modGrade;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            myStudent->addModule(modName,modGrade);
            break;
        case 2:
            myStudent->showGradelist();
            break;
        case 3:
            copyStudent=new Student(*myStudent);
            copyStudent->showStudent();
            delete copyStudent;
            copyStudent=NULL;
            break;
        case 4:
            studentviaOperatorOverload=*myStudent;
            studentviaOperatorOverload.showStudent();
            break;
        case 5:
			subMenuLoop=false;				
            break;
         default:
			cout << "Invalid option selected." << endl;
			break;
        }
    }
}

void showMenu()
{
    Student *myStudent=NULL;
    bool mainLoop=true;
    Group myGroup;

    while (mainLoop)
	{
        int userOption;    
        cout << ("\n===========MAINMENU================");
        cout << ("\n[1] Create Student.");
        cout << ("\n[2] Show Student(s).");
        cout << ("\n[3] Write Student(s) to a file.");
        cout << ("\n[4] Read Student(s) from a file.");
        cout << ("\n[5] Remove student from group of students.");    
        cout << ("\n[6] Quit.");
        cout <<  ("\n\nChoice : ");	
        cin >> userOption;
        //ignores parse error by clearing the error flag
        cin.clear();
        //clears buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        string name;
        int age,number;

        switch (userOption)
        {
            case 1:
                cout << "enter student's name: "<< endl;
	            cin >> name;
                cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "enter age: "<< endl;
	            cin >> age;
                cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "enter student number: "<< endl;
	            cin >> number;
                cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                myStudent=new Student(name,age,number);
                showSubMenu(myStudent);
                myGroup.addStudentToGroupOfStudents(myStudent);
                break;	
            case 2:
                myGroup.showGroupOfStudents();                
                break;
            case 3:
                myGroup.writeGroupOfStudentsInFile();                
                break;
            case 4:
                myGroup.readGroupOfStudentsFromFile();                
                break;
            case 5:
                cout << "enter student number to be removed: "<< endl;
	            cin >> number;
                cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                myGroup.removeStudentFromGroupOfStudents(number);                
                break;
			case 6:
                if(myStudent!=NULL)
                {
                delete myStudent;
				myStudent=NULL;
                }                                
                mainLoop=false;
				break;
            default:
				cout << "Invalid option selected." << endl;
				break;
        }
    }
}


int main( void )
{	
    showMenu();
	return 0;
}
