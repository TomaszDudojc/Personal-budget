#include "FileWithUsers.h"
#include "Markup.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;
    string fileNameWithUsers=XmlFile::getFileName();
    bool fileExists = xml.Load(fileNameWithUsers);
     if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserID", user.getUserId());
    xml.AddElem("Name", user.getUserName());
    xml.AddElem("Surname", user.getUserSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(fileNameWithUsers);
}
vector <User> FileWithUsers :: loadUsersFromFile()
{
    User user;
    vector <User> users;

    CMarkup xml;
    string fileNameWithUsers = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithUsers);

    if (fileExists == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") == true)
        {
            xml.IntoElem();
            xml.FindElem("UserID");
            int userId = atoi(xml.GetData().c_str());
            user.setupUserId(userId);
            xml.FindElem("Name");
            string userName = xml.GetData();
            user.setupUserName(userName);
            xml.FindElem("Surname");
            string userSurname = xml.GetData();
            user.setupUserSurname(userSurname);
            xml.FindElem("Login");
            string login = xml.GetData();
            user.setupLogin(login);
            xml.FindElem("Password");
            string password = xml.GetData();
            user.setupPassword(password);

            users.push_back(user);

            xml.OutOfElem();
        }
    }

    return users;
}
