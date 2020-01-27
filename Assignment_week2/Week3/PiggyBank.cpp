#include "PiggyBank.h"
#include <string>
#include <fstream>
#include <iostream>


PiggyBank::PiggyBank(void)
{
    this->owner = "";
    this->broken = false;
    this->balance = 0;
    id++;

}
PiggyBank::PiggyBank(string name)
{
    this->owner = name;
    this->broken = false;
    this->balance = 0;
    id++;
}
PiggyBank::PiggyBank(string name, int startBalance)
{
    this->owner = name;
    this->broken = false;
    this->balance = startBalance;
    id++;

}

string PiggyBank::getOwnerName() const
{
    return this->owner;
}

void PiggyBank::setOwnerName(string name)
{
       this->owner = name; 
}

bool PiggyBank::isBroken()
{
    return this->broken;

}

int PiggyBank::getBalance(int &amount)
{
        amount=this->balance;

    if(!isBroken())
   {
        //amount=this->balance;

        return 0;
   }
   else
    {
        return -1;
    }
   
}
void PiggyBank::depositMoney(int amount)
{
    if(!isBroken())
    {
       this->balance+= amount;
    }
}
int PiggyBank::smash()
{
     int tempBal=0;
    if(!isBroken())
    {
        this->broken=true;
        //make bal zero
        tempBal=balance;
        this->balance=0;
        return tempBal;
    }
    
    return -1;
}

int PiggyBank::id=0;

int PiggyBank::getId()
{
     return id;

}

//write object with overloading operator//avoid memory leakage

bool PiggyBank::writeToFile(PiggyBank *pb)
{
    string filename="output.txt";
    ofstream myfile_out;
    myfile_out.open(filename.c_str());
 
    if (!myfile_out.is_open())
		return false;
	
	myfile_out << "Piggy Bank Id: "<<pb->id<<"\nOwner Name: "<<pb->getOwnerName()<<"\nBroken Status: "<<pb->isBroken()<<"\nBalance: "<<pb->balance;
    myfile_out.close();

	return true;
}	
//read object with overloading operator//avoid memory leakage
bool PiggyBank::readFile()
{
    string filename="output.txt";
    ifstream myfile_in;
    myfile_in >> std::noskipws;
    myfile_in.open(filename.c_str());
    char c;
    if (!myfile_in.is_open())
	    return false;
  

     while (myfile_in >> c) {
        cout << c ;
    }
    	myfile_in.close();
	
	return true;
}

