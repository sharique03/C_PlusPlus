/*
 * ModuleGrade.h
 *
 */

#ifndef ModuleGrade_H_
#define ModuleGrade_H_
#include <string>

using namespace std;

class ModuleGrade
{
private:
string moduleName;
int moduleGrade; 

public:
ModuleGrade(string modName, int modGrade);
void showModule();
string ToString();


};


#endif /* ModuleGrade_H_ */
