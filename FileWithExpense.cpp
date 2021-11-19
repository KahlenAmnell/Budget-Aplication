#include "FileWithExpense.h"

FileWithExpense::FileWithExpense(string nameOfFileWithExpenses)
:XmlFile(nameOfFileWithExpenses)
    {

    }

void FileWithExpense::addNewExpenseToFile(Expense expense)
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
    xml.AddElem("Expese");
    xml.IntoElem();
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("Date", expense.getDate());
    amount = to_string(expense.getAmount());
    xml.AddElem("Amount", amount);
    xml.AddElem("Item", expense.getItem());

    xml.Save(XML_FILE);
}
