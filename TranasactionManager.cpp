#include "TranasactionManager.h"

void TransactionManager::addIncome()
{
    Transaction income;
    Transaction transaction;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    transaction.setupId(getNewIncomeId());//pozniej transaction.setupId(fileWithIncomes.getIdOfLastIncomeFromFile()+1);
    income = getNewTransactionData();


    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
    //if(fileWithIncomes.addIncomeToFile(income))
    cout << "Income added to the file" << endl;
    //else
    //cout << "Error, failed to add income to the file" << endl;
    displayAllIncomesSortedByDate();
    system("pause");
}

void TransactionManager::addExpense()
{
    Transaction expense;
    Transaction transaction;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    transaction.setupId(getNewExpenseId());//pozniej transaction.setupId(fileWithExpenses.getIdOfLastIncomeFromFile()+1);
    expense = getNewTransactionData();

    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);
    //if(fileWithIncomes.addIncomeToFile(expense))
    cout << "Expense added to the file" << endl;
    //else
    //cout << "Error, failed to add expense to the file" << endl;
    displayAllExpensesSortedByDate();
    system("pause");
}
/*adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany" << endl;
    else
        cout << "Blad, nie udalo sie dodac adresata do pliku" << endl;
    system ("pause");*/

/*Transaction TransactionManager::getNewIncomeData()
{
    DateManager dateManager;
    Transaction transaction;
    string date, name;
    float amount;
    int id, intDate;
    char choice;

    transaction.setupId(getNewIncomeId());//pozniej transaction.setupId(fileWithIncomes.getIdOfLastIncomeFromFile()+1);
    transaction.setupUserId(LOGGED_IN_USER_ID);

    cout << "Do you want to add income with current date?" <<endl;
    cout << "If yes, please click 'y', if you want to chose other date, please click 'n': " << endl;

    choice = AuxiliaryMethods::loadCharacter();

    if (choice == 'y'||choice == 'Y')
    {
        date = dateManager.createCurrentDate();
        cout<<"Current date: "<<date<<endl;
    }
    else if (choice == 'n'||choice == 'N')
    {
        do
        {
            cout << "Enter date in format YYYY-MM-DD: ";
            date = AuxiliaryMethods::loadLine();
        }
        while (dateManager.isDateCorrect(date) == false);
    }

    transaction.setupDate(date);
    intDate=dateManager.convertStringDateToIntDate(date);
    transaction.setupIntDate(intDate);

    cout << "Enter income name: ";
    name = AuxiliaryMethods::loadLine();
    transaction.setupName(name);

    cout << "Enter amount: ";
    string stringAmount = AuxiliaryMethods::loadLine();
    amount = correctAmountFormat(stringAmount);
    transaction.setupAmount(amount);

    return transaction;
}*/

Transaction TransactionManager::getNewTransactionData()
{
    DateManager dateManager;
    Transaction transaction;
    string date, name;
    float amount;
    int id, intDate;
    char choice;

    //transaction.setupId(getNewIncomeId());//pozniej transaction.setupId(fileWithIncomes.getIdOfLastIncomeFromFile()+1);
    transaction.setupUserId(LOGGED_IN_USER_ID);

    cout << "Do you want to add transaction with current date?" <<endl;
    cout << "If yes, please click 'y', if you want to chose other date, please click 'n': " << endl;

    choice = AuxiliaryMethods::loadCharacter();

    if (choice == 'y'||choice == 'Y')
    {
        date = dateManager.createCurrentDate();
        cout<<"Current date: "<<date<<endl;
    }
    else if (choice == 'n'||choice == 'N')
    {
        do
        {
            cout << "Enter date in format YYYY-MM-DD: ";
            date = AuxiliaryMethods::loadLine();
        }
        while (dateManager.isDateCorrect(date) == false);
    }

    transaction.setupDate(date);
    intDate=dateManager.convertStringDateToIntDate(date);
    transaction.setupIntDate(intDate);

    cout << "Enter transaction name: ";
    name = AuxiliaryMethods::loadLine();
    transaction.setupName(name);

    cout << "Enter amount: ";
    string stringAmount = AuxiliaryMethods::loadLine();
    amount = correctAmountFormat(stringAmount);
    transaction.setupAmount(amount);

    return transaction;
}

int TransactionManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
}

int TransactionManager::getNewExpenseId()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getId() + 1;
}

void TransactionManager::displayAllIncomesSortedByDate()
{
    sortIncomesByDate();

    float totalIncomesAmount=0.00;

    for (int i = 0; i < incomes.size(); i++)
    {
        displayIncome(i);
        totalIncomesAmount+=incomes[i].getAmount();
    }
    cout<<"Total incomes amouont: "<<totalIncomesAmount<<endl<<endl;
}

void TransactionManager::displayAllExpensesSortedByDate()
{
    sortExpensesByDate();

    float totalExpensesAmount=0.00;

    for (int i = 0; i < expenses.size(); i++)
    {
        cout<<"date: "<<expenses[i].getDate()<<"| id: "<<expenses[i].getId()<<".| user id: "<<expenses[i].getUserId()<<".| name: "<<expenses[i].getName()<<"| amount: "<<expenses[i].getAmount()<<endl;
        totalExpensesAmount+=expenses[i].getAmount();
    }
    cout<<"Total expenses amouont: "<<totalExpensesAmount<<endl<<endl;
}

void TransactionManager::displayIncome(int i)
{
   cout<<"date: "<<incomes[i].getDate()<<"| id: "<<incomes[i].getId()<<".| user id: "<<incomes[i].getUserId()<<".| name: "<<incomes[i].getName()<<"| amount: "<<incomes[i].getAmount()<<endl;

}

void TransactionManager::displayExpense(int i)
{
   cout<<"date: "<<expenses[i].getDate()<<"| id: "<<expenses[i].getId()<<".| user id: "<<expenses[i].getUserId()<<".| name: "<<expenses[i].getName()<<"| amount: "<<expenses[i].getAmount()<<endl;
}

void TransactionManager::sortIncomesByDate()
{
    std::sort(incomes.begin(), incomes.end(), [](auto && l, auto && r) { return l.getIntDate() < r.getIntDate(); });
}

void TransactionManager::sortExpensesByDate()
{
    std::sort(expenses.begin(), expenses.end(), [](auto && l, auto && r) { return l.getIntDate() < r.getIntDate(); });
}

float TransactionManager::correctAmountFormat(string stringAmount)
{
    stringAmount = AuxiliaryMethods::replaceCommaWithDot(stringAmount);
    float amount=AuxiliaryMethods::convertStringToFloat(stringAmount);

    return amount;
}

void TransactionManager::displayBalanceForSelectedPeriod()
{
    DateManager dateManager;
    string firstDateOfPeriod,lastDateOfPeriod;

    do
    {
        cout << "Enter first date in format YYYY-MM-DD: ";
        firstDateOfPeriod = AuxiliaryMethods::loadLine();
    }
    while (dateManager.isDateCorrect(firstDateOfPeriod) == false);

    do
    {
        cout << "Enter last date in format YYYY-MM-DD: ";
        lastDateOfPeriod = AuxiliaryMethods::loadLine();
    }
    while (dateManager.isDateCorrect(lastDateOfPeriod) == false);

    displayBalanceFromDateToDate(firstDateOfPeriod, lastDateOfPeriod);
}

void TransactionManager::displayBalanceFromDateToDate(string firstDate, string lastDate)
{
    DateManager dateManager;

    float totalIncomesAmount=getIncomesFromDateToDate(firstDate, lastDate);

    if (totalIncomesAmount==0) cout<<"There are no incomes in selected period."<<endl<<endl;
    else cout<<"Total incomes amouont: "<<totalIncomesAmount<<endl<<endl;

    float totalExpensesAmount=getExpensesFromDateToDate(firstDate, lastDate);

    if (totalExpensesAmount==0) cout<<"There are no expenses in selected period."<<endl<<endl;
    else cout<<"Total expenses amouont: "<<totalExpensesAmount<<endl<<endl;

    cout<<"Transaction balance of period from "<<firstDate<<" to "<<lastDate<<": "<<totalIncomesAmount-totalExpensesAmount<<endl;
    cout<<"---------------------------------------------------------------------"<<endl<<endl;
    system("pause");
}

float TransactionManager::getIncomesFromDateToDate(string firstDate, string lastDate)
{
    DateManager dateManager;
    float totalIncomesAmount=0.00;

     int intFirstDate=dateManager.convertStringDateToIntDate(firstDate);
     int intLastDate=dateManager.convertStringDateToIntDate(lastDate);

    if (intFirstDate<=intLastDate)
    {
        sortIncomesByDate();

        cout<<endl<<"Incomes of period from "<<firstDate<<" to "<<lastDate<<":"<<endl;

        for (int i = 0; i < incomes.size(); i++)
        {
            if (incomes[i].getIntDate()>=intFirstDate && incomes[i].getIntDate()<=intLastDate)
            {
                displayIncome(i);
                totalIncomesAmount+=incomes[i].getAmount();
            }
        }
        return totalIncomesAmount;
    }
    else  cout<<"Uncorrect range of dates!";
}

float TransactionManager::getExpensesFromDateToDate(string firstDate, string lastDate)
{
    DateManager dateManager;
    float totalExpensesAmount=0.00;

    int intFirstDate=dateManager.convertStringDateToIntDate(firstDate);
    int intLastDate=dateManager.convertStringDateToIntDate(lastDate);

    if (intFirstDate<=intLastDate)
    {
        sortExpensesByDate();

        cout<<"Expenses of period from "<<firstDate<<" to "<<lastDate<<":"<<endl;

        for (int i = 0; i < expenses.size(); i++)
        {
            if (expenses[i].getIntDate()>=intFirstDate && expenses[i].getIntDate()<=intLastDate)
            {
                displayExpense(i);
                totalExpensesAmount+=expenses[i].getAmount();
            }
        }
        return totalExpensesAmount;
    }
    else  cout<<"Uncorrect range of dates!";
}

void TransactionManager::displayBalanceForCurrentMonth()
{
    DateManager dateManager;

    int year = dateManager.getCurrentYear();
    int month = dateManager.getCurrentMonth();
    const int firstDayOfMonth=1;
    int lastDayOfMonth = dateManager.checkNumberOfDaysInMonth(year, month);

    string dateOfFirstDayOfMonth = dateManager.convertIntDateToStringDate(year, month, firstDayOfMonth);
    string dateOfLastDayOfMonth = dateManager.convertIntDateToStringDate (year, month, lastDayOfMonth);

    /*month=dateManager.getCurrentMonth();
    string dateOfFirstDayOfMonth = dateManager.createDateOfFirstDayOfMonth(month);
    string dateOfLastDayOfMonth = dateManager.createDateOfLastDayOfMonth(month);*/

    displayBalanceFromDateToDate(dateOfFirstDayOfMonth, dateOfLastDayOfMonth);
}

void TransactionManager::displayBalanceForPreviousMonth()
{
    DateManager dateManager;
    int year = 0;
    int month = 0;

    if (dateManager.getCurrentMonth()==1)
    {
       year = dateManager.getCurrentYear()-1;
       month = 12;
    }
    else
    {
       year = dateManager.getCurrentYear();
       month = dateManager.getCurrentMonth()-1;
    }

    const int firstDayOfMonth = 1;
   int lastDayOfMonth = dateManager.checkNumberOfDaysInMonth(year, month);

    string dateOfFirstDayOfMonth = dateManager.convertIntDateToStringDate(year, month, firstDayOfMonth);
    string dateOfLastDayOfMonth = dateManager.convertIntDateToStringDate (year, month, lastDayOfMonth);

    displayBalanceFromDateToDate(dateOfFirstDayOfMonth, dateOfLastDayOfMonth);
}
