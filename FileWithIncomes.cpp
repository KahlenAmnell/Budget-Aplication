#include "FileWithIncomes.h"

FileWithIncomes::FileWithIncomes(string nameOfFileWithIncomes)
:XmlFile(nameOfFileWithIncomes)
    {

    }

void FileWithIncomes::addNewIncomeToFile(Incomes income)
{
    CMarkup xml;

    bool fileExists = xml.Load(XML_FILE);

    if(!fileExists)
    {
        startTheFile(xml);
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId", income.getIncomeId());
    xml.AddElem("IncomeId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Amount", income.getAmount());
    xml.AddElem("Item", income.getItem());

    xml.Save(XML_FILE);
}

void FileWithIncomes::startTheFile(CMarkup &xml)
{
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(XML_FILE);
}

vector<Incomes> FileWithIncomes::loadIncomesFromFile(int loggedUserId)
{
    vector<Incomes> incomes;
    Incomes income;
    CMarkup xml;
    int userId = 0;
    int incomeId = 0;
    int date = 0;
    float amount = 0;

    bool fileExists = xml.Load( XML_FILE);

    if(!fileExists)
    {
        return incomes;
    }

    xml.FindElem(); //Incomes
    xml.IntoElem();
    while(xml.FindElem("Income"))
    {
        xml.IntoElem();

        xml.FindElem("UserId");
        userId = SupportingMethods::convertStringToNumber(xml.GetData());

        if(userId == loggedUserId)
        {
        income.setUserId(userId);

        xml.FindElem("IncomeId");
        incomeId = SupportingMethods::convertStringToNumber(xml.GetData());
        income.setIncomeId(incomeId);

        xml.FindElem("Date");
        date = SupportingMethods::convertStringToNumber(xml.GetData());
        income.setDate(date);

        xml.FindElem("Amount");
        amount = SupportingMethods::convertStringToNumber(xml.GetData());
        income.setAmount(amount);

        xml.FindElem("Item");
        income.setItem(xml.GetData());

        incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;
}
