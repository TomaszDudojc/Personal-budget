#include "TranasactionManager.h"

void TransactionManager::addIncome()
{
    Transaction income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = getNewIncomeData();

    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
    //if(fileWithIncomes.addIncomeToFile(income))
    cout << "Income added to the file" << endl;
    //else
    //cout << "Error, failed to add income to the file" << endl;
    displayAllIncomesSortedByDate();
    system("pause");
}
/*adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany" << endl;
    else
        cout << "Blad, nie udalo sie dodac adresata do pliku" << endl;
    system ("pause");*/
Transaction TransactionManager::getNewIncomeData()
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
}

int TransactionManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
}

void TransactionManager::displayAllIncomesSortedByDate()
{
    sortByDate();
    float totalIncomesAmount=0.00;
    for (int i = 0; i < incomes.size(); i++)
    {
        cout<<"date: "<<incomes[i].getDate()<<"| id: "<<incomes[i].getId()<<".| user id: "<<incomes[i].getUserId()<<".| name: "<<incomes[i].getName()<<"| amount: "<<incomes[i].getAmount()<<endl;
        totalIncomesAmount+=incomes[i].getAmount();
    }
    cout<<"Total incomes amouont: "<<totalIncomesAmount<<endl<<endl;
}

void TransactionManager::sortByDate()
{
    std::sort(incomes.begin(), incomes.end(), [](auto && l, auto && r) { return l.getIntDate() < r.getIntDate(); });
}

float TransactionManager::correctAmountFormat(string stringAmount)
{
    stringAmount = AuxiliaryMethods::replaceCommaWithDot(stringAmount);
    float amount=AuxiliaryMethods::convertStringToFloat(stringAmount);

    return amount;
}

