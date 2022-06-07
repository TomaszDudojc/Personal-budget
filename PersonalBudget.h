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
    void addUserToFile();
    int loginUser();
    bool isUserLoggedIn();
   //void changePassword();
    void logoutUser();

    char selectOptionFromUserMenu();


};


#endif
