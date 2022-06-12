#ifndef TRANASACTIONMANAGER_H
#define TRANASACTIONMANAGER_H

#include <iostream>
#include <iostream>
#include <vector>
#include <string>

#include "Transaction.h"
#include "User.h"
#include "UserManager.h"
#include "DateManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

using namespace std;

class TransactionManager
{
    const int LOGGED_IN_USER_ID;
    vector <Transaction> incomes;
    vector <Transaction> expenses;

    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    //Transaction getNewIncomeData();
    //Transaction getNewExpenseData();
    Transaction getNewTransactionData();
    int getNewIncomeId();
    int getNewExpenseId();
    void sortIncomesByDate();
    void sortExpensesByDate();
    float correctAmountFormat(string amount);
    void displayBalanceFromDateToDate(string firstDate, string lastDate);
    float getIncomesFromDateToDate(string firstDate, string lastDate);
    float getExpensesFromDateToDate(string firstDate, string lastDate);
    void displayIncome(int i);
    void displayExpense(int i);

public:

    TransactionManager (string fileNameWithIncomes, string fileNameWithExpenses, int loggedInUserId) : fileWithIncomes (fileNameWithIncomes), fileWithExpenses (fileNameWithExpenses), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = fileWithIncomes.getIncomeFromFile(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.getExpenseFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();
    void displayAllIncomesSortedByDate();
    void displayAllExpensesSortedByDate();
    void displayBalanceForSelectedPeriod();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    //void displayIncomesFromDateToDate;
    //void displayExpensesFromDateToDate;
    //void displayCurrentMonthIncomes;
    //void displayCurrentMonthEkspenses;
    //void displayPreviousMonthIncomes;
    //void displayPreviousMonthEkspenses;
    //void displaySelectedPeriodIncomes();
};
#endif
