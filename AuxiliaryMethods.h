#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class AuxiliaryMethods
{

public:
    static char loadCharacter();
    static string changeFirstLetterToCapitalAndOtherToLowercase(string text);
    static string loadLine();
    static string convertIntToString(int number);
    static string convertFloatToString(float amount);


};

#endif
