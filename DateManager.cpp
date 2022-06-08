#include "DateManager.h"

string addZeroToStringDate(string date)
{
    string dateWithZero;
    if (date.size()==1) dateWithZero=date.insert (0,1,'0');
    else dateWithZero=date;

    return dateWithZero;
}

string addDashToDate(string date)
 {
    string stringDateWithDash;
    stringDateWithDash = date.insert (4,1,'-');
    stringDateWithDash = stringDateWithDash.insert (7,1,'-');

    return stringDateWithDash;
}

string convertIntDateToStringDate(int year, int month, int day)
{
    string stringYear, stringMonth, stringDay,  stringDate;
    stringYear=AuxiliaryMethods::convertIntToString(year);
    stringMonth=AuxiliaryMethods::convertIntToString(month);
    stringMonth=addZeroToStringDate(stringMonth);
    stringDay=AuxiliaryMethods::convertIntToString(day);
    stringDay=addZeroToStringDate(stringDay);
    stringDate=stringYear+stringMonth+stringDay;
    addDashToDate(stringDate);

    return stringDate;
}

int getCurrentYear()
{
    time_t calculatedTime;
    struct tm * data;
    int year;
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    year = data -> tm_year+1900;

    return year;
}

int getCurrentMonth()
{
    time_t calculatedTime;
    struct tm * data;
    int month;
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    month = data -> tm_mon+1;

    return month;
}

int getCurrentDay()
{
    time_t calculatedTime;
    struct tm * data;
    int day;
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    day = data -> tm_mday;

    return day;
}

void displayCurrentDate()
{
    int year, month, day;
    string currentDate;
    year = getCurrentYear();
    month = getCurrentMonth();
    day = getCurrentDay();
    currentDate=convertIntDateToStringDate(year,month,day);
    currentDate=addDashToDate(currentDate);
    cout<<"Current date: "<<currentDate<<endl;
}

int convertStringDateToIntDate (string date)
{
    int year = (date[0]-'0')*10000000 + (date[1]-'0')*1000000 + (date[2]-'0')*100000 + (date[3]-'0')*10000;
    int month = (date[5]-'0')*1000 + (date[6]-'0')*100;
    int day = (date[8]-'0')*10 + (date[9]-'0');

    int intDate= year+month+day;
    return intDate;
}

bool isLeap(int year)
{
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        return true;
    }
    else return false;
}
int checkNumberOfDaysInMonth(int year, int month)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

    case 2:
        if (isLeap(year)) return 29;
        else return 28;
        break;
    default:
        cout<<"Uncorrect number of month!";
    }
}

string createDateOfFirstDayOfMonth (int month)
{
    int year = getCurrentYear();
    const int firstDayOfMonth=1;
    string dateOfFirstDayOfMonth = convertIntDateToStringDate(year, month, firstDayOfMonth);
    dateOfFirstDayOfMonth = addDashToDate(dateOfFirstDayOfMonth);

    return dateOfFirstDayOfMonth;
}

string createDateOfLastDayOfMonth (int month)
{
    int year = getCurrentYear();
    int lastDayOfMonth=checkNumberOfDaysInMonth(year, month);
    string dateOfLastDayOfMonth = convertIntDateToStringDate(year, month, lastDayOfMonth);
    dateOfLastDayOfMonth = addDashToDate(dateOfLastDayOfMonth);

    return dateOfLastDayOfMonth;
}
