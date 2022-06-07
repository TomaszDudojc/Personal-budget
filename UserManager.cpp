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

    string name;
    cout << "Enter name: ";
    cin >> name;
    name = AuxiliaryMethods :: changeFirstLetterToCapitalAndOtherToLowercase(name);
    user.setupName(name);

    string surname;
    cout << "Enter surname: ";
    cin >> surname;
    surname = AuxiliaryMethods :: changeFirstLetterToCapitalAndOtherToLowercase(surname);
    user.setupSurname(surname);

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
        cout<<"|Name: "<<users[i].getName();
        cout<<"|Surname: "<<users[i].getSurname();
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

int UserManager::loginUser()
{
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Enter the password. Attempts left: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You logged in." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getUserId();
                    return loggedInUserId;
                }
            }
            cout << "Wrong password entered 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");
    return 0;
}

bool UserManager::isUserLoggedIn()
{
    if (loggedInUserId>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void UserManager::logoutUser()
{
    loggedInUserId=0;
}


