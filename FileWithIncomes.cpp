#include "FileWithIncomes.h"

FileWithIncomes::FileWithIncomes(string nameOfFileWithIncomes)
:XmlFile(nameOfFileWithIncomes)
    {

    }

void FileWithIncomes::addNewIncomeToFile(Incomes income)
{
    CMarkup xml;
    string amount;

    bool fileExists = xml.Load(XML_FILE);

    if(!fileExists)
    {
        startTheFile(xml);
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("Date", income.getDate());
    amount = to_string(income.getAmount());
    xml.AddElem("Amount", amount);
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
        userId = SupportingMethods::convertStringToInt(xml.GetData());

        if(userId == loggedUserId)
        {
        income.setUserId(userId);

        xml.FindElem("IncomeId");
        incomeId = SupportingMethods::convertStringToInt(xml.GetData());
        income.setIncomeId(incomeId);

        xml.FindElem("Date");
        date = SupportingMethods::convertStringToInt(xml.GetData());
        income.setDate(date);

        xml.FindElem("Amount");
        amount = SupportingMethods::convertStringToFloat(xml.GetData());
        income.setAmount(amount);

        xml.FindElem("Item");
        income.setItem(xml.GetData());

        incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;
}

int FileWithIncomes::getLastIncomeId()
{
    int lastIncomeId = 0;
    CMarkup xml;

    bool fileExists = xml.Load( XML_FILE);

    if(!fileExists)
    {
        return 0;
    }

    xml.FindElem(); //Incomes
    xml.IntoElem();
    while(xml.FindElem("Income"))
    {}
    xml.IntoElem();
    xml.FindElem("IncomeId");
    lastIncomeId = SupportingMethods::convertStringToInt(xml.GetData());

    return lastIncomeId;
}
