#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Transaction expense)
{
    CMarkup xml;
    string fileNameWithExpenses = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithExpenses);
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem( "userId", expense.getUserId() );
    xml.AddElem( "id", expense.getId() );
    xml.AddElem( "date", expense.getDate() );
    xml.AddElem("intDate", expense.getIntDate());
    xml.AddElem( "name", expense.getName() );
    xml.AddElem("amount", AuxiliaryMethods::convertFloatToString(expense.getAmount()));

    xml.Save(fileNameWithExpenses);
}

vector <Transaction> FileWithExpenses::getExpenseFromFile(int loggedInUserId)
{
    Transaction transaction;
    vector <Transaction> expense;
    CMarkup xml;
    string fileNameWithExpenses = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithExpenses);

    if (fileExists == true)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") == true)
        {
            xml.IntoElem();
            xml.FindElem("userId");
            if (xml.GetData() == AuxiliaryMethods::convertIntToString(loggedInUserId))

            {
                //xml.ResetMainPos(); when "userId" is not the first element
                //xml.FindElem("userId"); when "userId" is not the first element
                int userId = atoi(xml.GetData().c_str());
                transaction.setupUserId(userId);

                xml.FindElem( "id");
                int id = atoi(xml.GetData().c_str());
                transaction.setupId(id);

                string date = xml.GetData();
                xml.FindElem( "date");
                transaction.setupDate(date);

                xml.FindElem( "intDate");
                int intDate = atoi(xml.GetData().c_str());
                transaction.setupIntDate(intDate);

                xml.FindElem( "name");
                string name = xml.GetData();
                transaction.setupName(name);

                xml.FindElem( "amount");
                float amount = atof(xml.GetData().c_str());
                transaction.setupAmount(amount);
                expenses.push_back(transaction);

                xml.OutOfElem();
            }
            else
            {
                xml.OutOfElem();
            }
        }
    }
    return expenses;
}
