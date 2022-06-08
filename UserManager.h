#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector<User>users;

    User getNewUserData();
    int getNewUserId();
    bool loginExists(string login);
    FileWithUsers fileWithUsers;

public:
    UserManager(string fileNameWithUsers): fileWithUsers(fileNameWithUsers)
     {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile ();
    };//konstruktor
    void registerUser();
    void displayAllUsers();
    int loginUser();
    bool isUserLoggedIn();
   void changePassword();
   //void addNewPasswordToFile();
    void addUserToFile();
    void logoutUser();

    char selectOptionFromUserMenu();
    int getLoggedInUserId();

};


#endif
