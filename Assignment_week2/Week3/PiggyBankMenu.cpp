//============================================================================
// Name        : PiggyBankMenu.cpp
//
//============================================================================

#include <iostream>
#include "PiggyBank.h"

#include <string>    
using namespace std; 
#include<limits> 


void showSubMenu(PiggyBank *pb)
{
	    int userOptionFromSubMenu;
    	bool secondLoop=true;
        string ownerName;
        int depositAmount;
        int amount;
        int callBalance;
        bool isFile;
        string readFile;
        while (secondLoop)
        {
            cout << ("\n===========SUBMENU: Piggy Bank Activities ================");
            cout << ("\n[1] Set Owner's name.");
            cout << ("\n[2] Get Owner's name.");
            cout << ("\n[3] Is piggy bank broken?");
            cout << ("\n[4] Deposit money.");
            cout << ("\n[5] get balance.");
            cout << ("\n[6] Smash it!!!.");
            cout << ("\n[7] Write piggy bank details to a file.");
            cout << ("\n[8] Read piggy bank details from a file.");
            //delete pg "create with null if null then create"
            cout << ("\n[9] Quit to the main menu.");
            cout <<  ("\n\nChoice : ");	
	        cin >> userOptionFromSubMenu;
            //ignores parse error by clearing the error flag
            cin.clear();
            //clears buffer
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            switch (userOptionFromSubMenu)
            {
                case 1:
                    cout << ("\nenter owner's name: ");
                    cin >> ownerName;
                    //ignores parse error by clearing the error flag
                    cin.clear();
                    //clears buffer
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');                    
                    pb->setOwnerName(ownerName);
                    break;
                case 2:
                    cout << "\nOwner's name: "<< pb->getOwnerName() <<endl;
                    break;
                case 3:
                    cout << "\nPiggy bank broken status: "<< pb->isBroken() <<endl;
                    break;
                case 4:
                    cout << "\nenter the amount to be deposited: " <<endl;
                    cin >> depositAmount;
                    //ignores parse error by clearing the error flag
                    cin.clear();
                    //clears buffer
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');                    
                    pb->depositMoney(depositAmount);
                    break;
                case 5:
                    callBalance=pb->getBalance(amount);
                    cout << "\nBalance: "<< amount <<endl;
                    break;
                case 6:
                    cout << "\nSmash: "<< pb->smash() <<endl;
                case 7:
                    isFile= pb->writeToFile(pb);
                    break;
                case 8:                    
                    cout << "\nFile Content: \n" <<endl;
                    isFile=pb->readFile();
                    break;
                case 9:
                    //removing the current obj to avoid memory leakage
                    delete pb;
                    secondLoop=false;
				    break;
                default:
                    cout << "Invalid option selected." << endl;
                    break;   
            }
        }
}

void createPiggybank(PiggyBank *pb)
{
    if(pb!=NULL)
    {
       delete pb;
    }
    pb=new PiggyBank();
    cout << "\nPiggy Bank is created." << endl;
    showSubMenu(pb);
}
void createPiggybankWithName(PiggyBank *pb,string name)
{
     if(pb!=NULL)
    {
       delete pb;
    }
    pb=new PiggyBank(name);
    cout << "\nPiggy Bank is created.\n" << endl;
    cout << "\nOwner name: " << pb->getOwnerName() << endl;
    showSubMenu(pb);

}
void createPiggybankWithNameAndBalance(PiggyBank *pb,string name, int balance)
{
     if(pb!=NULL)
    {
       delete pb;
    }
    int *amt;
    pb=new PiggyBank(name, balance);
    cout << "\nPiggy Bank is created.\n" << endl;
    cout << "\nOwner name: " << pb->getOwnerName() << endl;
    showSubMenu(pb);

}

void showMenu( PiggyBank *pb )
{
	bool mainLoop=true;

	while (mainLoop)
	{
	int userOption;    
	cout << ("\n===========MAINMENU: Select Piggy Bank Type================");
	cout << ("\n[1] Create Piggy bank.");
	cout << ("\n[2] Create Piggy bank with Owner's name.");
    cout << ("\n[3] Create Piggy bank with Owner's name & Balance.");
    cout << ("\n[4] Get counts of Piggy banks.");
    cout << ("\n[5] Quit.");
	cout <<  ("\n\nChoice : ");	
	cin >> userOption;
	//ignores parse error by clearing the error flag
	cin.clear();
	//clears buffer
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string ownerName;

	switch (userOption)
        {
            case 1:
                createPiggybank(pb);
                break;			
			case 2:
                cout << "enter owner's name: "<< endl;
	            cin >> ownerName;
                cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                createPiggybankWithName(pb,ownerName);
				break;
			case 3:
                int startingBalance;
                cout << "enter owner's name: "<< endl;
	            cin >> ownerName;
                cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "enter starting balance: "<< endl;
	            cin >> startingBalance;
                cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                createPiggybankWithNameAndBalance(pb,ownerName,startingBalance);                            
                break;
            case 4:
                cout << "Number of accounts: "<< PiggyBank::getId() << endl;
				break;
            case 5:
                if(pb!=NULL)
                {
                    delete pb;
                }
				mainLoop=false;
				break;
			default:
				cout << "Invalid option selected." << endl;
				break;
		}
	}
	
	    delete pb;
}






int main( void )
{	
    PiggyBank *pb=NULL;
    showMenu(pb);
	return 0;
}
