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
    //void displayIncome();
    //void displayExpense();
    //void displayIncomesFromDateToDate;
    //void displayExpensesFromDateToDate;
    //void displayCurrentMonthIncomes;
    //void displayCurrentMonthEkspenses;
    //void displayPreviousMonthIncomes;
    //void displayPreviousMonthEkspenses;
    //void displaySelectedPeriodIncomes;
    //void displaySelectedPeriodEkspenses;
};



#endif

/*
using namespace std;

class AdresatMenedzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    int podajIdWybranegoAdresata();
    char wybierzOpcjeZMenuEdycja();

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami,int idZalogowanegoUzytkownika): plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
    void edytujAdresata();
};*/
