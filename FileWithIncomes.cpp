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
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Amount", income.getAmount());
    xml.AddElem("Name", income.getName());

    xml.Save(XML_FILE);
}

void FileWithIncomes::startTheFile(CMarkup &xml)
{
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(XML_FILE);
}
