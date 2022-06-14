#ifndef FILEWITHIEXPENSES_H
#define FILEWITHIEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "XmlFile.h"
#include "Transaction.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses : public XmlFile
{
    string fileNameWithExpenses;
    int lastExpenseId;
    int loggedInUserId;
    vector <Transaction> expenses;

public:
    FileWithExpenses(string fileNameWithExpenses) : XmlFile(fileNameWithExpenses)
    {
        loggedInUserId = 0;
        lastExpenseId = 0;
    };
    void addExpenseToFile(Transaction expense);
    vector <Transaction> getExpenseFromFile(int loggedInUserId);
    int getIdOfLastExpenseFromFile();
};

#endif
