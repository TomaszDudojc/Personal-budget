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
