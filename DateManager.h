#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
//#include <string>
//#include <sstream>
#include <ctime>
//#include <windows.h>

#include "Date.h"
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
    time_t calculatedTime;
    struct tm * data;
    int MIN_FEASIBLE_YEAR = 2000; //min date 2000-01-01

    string convertIntDateToStringDate;
    string addZeroToStringDate;
    string addDashToDate;
    string createDateOfFirstDayOfMonth;
    string createDateOfLastDayOfMonth;
    int convertStringDateToIntDate;
    bool isLeapYear;

public:
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    void displayCurrentDate();
    //bool isDateCorrect;
};

#endif
