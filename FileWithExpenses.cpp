#include "FileWithExpenses.h"
#include "Markup.h"
//#include "AuxiliaryMethods.h"

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
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") == true)
        {
            xml.IntoElem();

            xml.FindElem("userId");
            int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
            //if ( userId == loggedInUserId )
            transaction.setupUserId(userId);

            xml.FindElem( "id");
            int id = atoi(xml.GetData().c_str());
            transaction.setupId(id);


            xml.FindElem( "date");
            string date = xml.GetData();
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
    }
    return expenses;
}
