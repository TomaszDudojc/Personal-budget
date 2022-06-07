#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"


using namespace std;

class PersonalBudget
{

    UserManager userManager;

   public:
    PersonalBudget(string fileNameWithUsers): userManager(fileNameWithUsers){}

    char selectOptionFromMainMenu();
    void registerUser();
    void displayAllUsers();
    //bool ifUserIsLogged();
    //int userLogIn();

};


#endif
