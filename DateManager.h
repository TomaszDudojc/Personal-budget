#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <string>
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

    string addZeroToStringDate(string date);
    string addDashToDate(string date);
    bool isLeapYear(int year);
    bool isDateFormatCorrect(string date);
    bool isYearCorrect(int year);
    bool isMonthCorrect(int month, int year);
    bool isDayCorrect(int day, int month, int year);

public:
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    string createCurrentDate();
    int convertStringDateToIntDate(string date);
    bool isDateCorrect(string date);
    string createDateOfFirstDayOfMonth(int month);
    string createDateOfLastDayOfMonth(int month);
    int checkNumberOfDaysInMonth(int year, int month);
    string convertIntDateToStringDate (int year, int month, int day);
};

#endif
