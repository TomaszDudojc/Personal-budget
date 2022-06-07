#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("Users.xml");
    char choice = 0;
    int loggedInUserId = 0;

    while (true)
    {
        if (personalBudget.isUserLoggedIn() == false)
        {
            choice = personalBudget.selectOptionFromMainMenu();

  switch (choice)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                //loggedInUserId = personalBudget.loginUser();
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            }
       }
        /*else
        //{
            choice = personalBudget.selectOptionFromUserMenu();
            switch (choice)
            {
            case '1':
                //personalBudget.addIncome();
                break;
            case '2':
                //personalBudget.addExpense();
                break;
            case '3':
                //personalBudget.displayBalanceForCurrentMonth();
                break;
            case '4':
                //personalBudget.displayBalanceForPreviousMonth();
                break;
            case '5':
                //personalBudget.displayBalanceForSelectedPeriod();
                break;
            case '6':
                //personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logOutUser();
                //transaction.clear();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }*/
    }


    personalBudget.displayAllUsers();
    return 0;
}
