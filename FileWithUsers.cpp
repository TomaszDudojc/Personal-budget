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
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(fileNameWithUsers);
}
vector <User> FileWithUsers::loadUsersFromFile()
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
            string name = xml.GetData();
            user.setupName(name);
            xml.FindElem("Surname");
            string surname = xml.GetData();
            user.setupSurname(surname);
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
/*
void FileWithUsers::addNewPasswordToFile(vector <User> users, int loggedInUserId)
{
    //CMarkup xml;
    //bool fileExists = xml.Load("expenses.xml");
    //xml.Load("expenses.xml");
    //xml.SetDoc( fileNameWithUsers )
    User user;
    CMarkup xml;
    string fileNameWithUsers=XmlFile::getFileName();
    bool fileExists = xml.Load(fileNameWithUsers);

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("UserID")==true);

    {
        int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
        if ( userId == loggedInUserId )
        {
            xml.FindElem("Password");
            xml.RemoveElem();
            xml.AddElem("Password", user.getPassword());
        }
    }

    xml.Save(fileNameWithUsers);
}*/

