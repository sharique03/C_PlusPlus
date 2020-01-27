//============================================================================
// Name        : menu.cpp
//
//============================================================================

#include "help.h"
#include <iostream>

#include <string>    
using namespace std; 
#include<limits> 


void showMenu( void )
{
	bool loop=true;
	int countOfChoiceByUser=0;
	while (loop)
	{
	int userOption;	
	cout << ("\n===========================");
	cout << ("\n[1] Show owner name.");
	cout << ("\n[2] Total Choice Count (function of my choice).");
	cout << ("\n[3] Quit.");
	cout <<  ("\n\nChoice : ");
	
	cin >> userOption;
	//ignores parse error by clearing the error flag
	cin.clear();
	//clears buffer
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	countOfChoiceByUser++;
	switch (userOption)
        {
            case 1:
				cout << "Owner's name is Sharique." << endl;
                break;			
			case 2:
				//option1();
				showOptionCount(&countOfChoiceByUser);
				break;
			case 3:
				loop=false;
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
