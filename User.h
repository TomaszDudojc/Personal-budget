#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int userId;
    string userName;
    string userSurname;
    string login;
    string password;

public:
    User(int userId=0,string userName="", string userSurname="", string login="", string password="")
    {
        this->userId=userId;
        this->userName=userName;
        this->userSurname=userSurname;
        this->login= login;
        this->password=password;
    }

    void setupUserId(int newUserId);
    void setupUserName(string newUserName);
    void setupUserSurname(string newUserSurname);
    void setupLogin(string newLogin);
    void setupPassword(string newPassword);

    int getUserId();
    string getUserName();
    string getUserSurname();
    string getLogin();
    string getPassword();
};

#endif
