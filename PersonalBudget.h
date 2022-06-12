#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "TranasactionManager.h"
#include "DateManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    TransactionManager *transactionManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    PersonalBudget(string fileNameWithUsers, string FileNameWithIncomes, string FileNameWithExpenses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(FileNameWithIncomes), FILE_NAME_WITH_EXPENSES(FileNameWithExpenses)
    {
        transactionManager = NULL;
    }
    ~PersonalBudget()
    {
        delete transactionManager;
        transactionManager = NULL;
    };

    char selectOptionFromMainMenu();
    void registerUser();
    void displayAllUsers();
    void addUserToFile();
    int loginUser();
    bool isUserLoggedIn();
    void changePassword();
    void logoutUser();

    char selectOptionFromUserMenu();
    void addIncome();
    void addExpense();
    void displayBalanceForSelectedPeriod();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
};


#endif
