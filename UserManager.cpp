#include "UserManager.h"

void UserManager::registerUser()
{
    User user = getNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Account has been successfully created" << endl << endl;
    system("pause");
}

User UserManager::getNewUserData()
{
    User user;

    user.setupUserId(getNewUserId());

    string userName;
    cout << "Enter name: ";
    cin >> userName;
    userName = AuxiliaryMethods :: changeFirstLetterToCapitalAndOtherToLowercase(userName);
    user.setupUserName(userName);

    string userSurname;
    cout << "Enter surname: ";
    cin >> userSurname;
    userSurname = AuxiliaryMethods :: changeFirstLetterToCapitalAndOtherToLowercase(userSurname);
    user.setupUserSurname(userSurname);

    string login;
    do
    {
        cout <<"Enter login: ";
        cin>>login;
        user.setupLogin(login);
    }
    while (loginExists(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    cin>>password;
    user.setupPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager::displayAllUsers()
{
    for (int i=0; i<users.size(); i++)
    {
        cout<<"User ID: "<<users[i].getUserId();
        cout<<"|Name: "<<users[i].getUserName();
        cout<<"|Surname: "<<users[i].getUserSurname();
        cout<<"|Login: "<<users[i].getLogin();
        cout<<"|Password: "<<users[i].getPassword()<<endl;
    }
}
bool UserManager::loginExists(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin()==login)
        {
            cout << endl << "There is a user with this login." << endl;
            return true;
        }
    }
    return false;
}
