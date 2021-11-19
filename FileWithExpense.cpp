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

vector<Expense> FileWithExpense::loadExpenseFromFile(int loggedUserId)
{
    vector<Expense> expenses;
    Expense expense;
    CMarkup xml;
    int userId = 0;
    int expenseId = 0;
    int date = 0;
    float amount = 0;

    bool fileExists = xml.Load( XML_FILE);

    if(!fileExists)
    {
        return expenses;
    }

    xml.FindElem(); //expenses
    xml.IntoElem();
    while(xml.FindElem("expense"))
    {
        xml.IntoElem();

        xml.FindElem("UserId");
        userId = SupportingMethods::convertStringToInt(xml.GetData());

        if(userId == loggedUserId)
        {
        expense.setUserId(userId);

        xml.FindElem("ExpenseId");
        expenseId = SupportingMethods::convertStringToInt(xml.GetData());
        expense.setExpenseId(expenseId);

        xml.FindElem("Date");
        date = SupportingMethods::convertStringToInt(xml.GetData());
        expense.setDate(date);

        xml.FindElem("Amount");
        amount = SupportingMethods::convertStringToFloat(xml.GetData());
        expense.setAmount(amount);

        xml.FindElem("Item");
        expense.setItem(xml.GetData());

        expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}
