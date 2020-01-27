#include "ModuleGrade.h"
#include <iostream>
#include <string>
#include <sstream>


ModuleGrade::ModuleGrade(string modName, int modGrade)
{
    this->moduleName = modName;
    this->moduleGrade = modGrade;
}

void ModuleGrade::showModule()
{
    cout << "\n##---Module Details---##" <<endl;
    cout << "Module Name: "<< this->moduleName <<endl;
    cout << "Module Grade: "<< this->moduleGrade <<endl;
}

string ModuleGrade::ToString()
{
    string modNm=this->moduleName;
    int modGrade=this->moduleGrade;
    stringstream ss;
    ss<<modGrade;
    return modNm+" "+ss.str();
}