#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>

#include "Transaction.h"

using namespace std;

class TranasactionMananger
{
    const int LOGGED_IN_USER_ID;
    vector <Transaction> icomes;
    vector <Transaction> expenses;

    //FileWithIncomes fileWithIncomes;
   // FileWithExpenses fileWithExpenses;

    //Transaction getNewIncomeData();
    //Transaction getNewExpenseData();
    //int getNewIncomeId();
    //int getNewExpenseId();
    //void sortByDate();

public:

    TransactionManager();
    //void addExpense();
    //void displayAllIncomes();
    //void displayAllExpenses();
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
