#include "PersonalBudget.h"
#include "AuxiliaryMethods.h"

char PersonalBudget::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. End " << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods :: loadCharacter();

    return choice;
}

void PersonalBudget::registerUser()
{
    userManager.registerUser();
}

 void PersonalBudget::displayAllUsers()
 {
    userManager.displayAllUsers();
 }