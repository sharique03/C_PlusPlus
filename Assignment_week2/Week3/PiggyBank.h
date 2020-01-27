/*
 * PiggyBank.h
 *
 */

#ifndef PiggyBank_H_
#define PiggyBank_H_
#include <string>
using namespace std;

class PiggyBank
{
private:
static int id;//contains an unique number to identify this object;
string owner; // PiggyBank owner
int balance; // Current balance in PiggyBank
bool broken; // true if PiggyBank is broken, else false
public:
PiggyBank(void);
/* post: a PiggyBank object is created, owner equals "",
broken is false, balance is 0 */
PiggyBank(string name);
/* post: a PiggyBank object is created, owner equals name,
broken is false, balance is 0 */
PiggyBank(string name, int startBalance);
/* post: a PiggyBank object is created, owner equals name,
broken is false, balance is startBalance */
string getOwnerName() const;
/* post: the PiggyBank owner's name is returned */
void setOwnerName(string name);
/*post: the PiggyBank owner's name is set to name */
bool isBroken() ;
/* the value of broken is returned */
int getBalance(int &amount) ;
/* if !broken then 0 is returned and amount = PiggyBanks balance
 else -1 is returned */
void depositMoney(int amount);
/*post: if !broken then amount is added to PiggyBanks balance
else nothing has changed */
int smash();
/* pre : PiggyBank is not broken
 post: return current balance and PiggyBank is broken */

static int getId(); //to get the number of object created



bool writeToFile(PiggyBank *pb);//to write current piggy bank details to a file


bool readFile();//to read  bank details from a file

};


#endif /* PiggyBank_H_ */
