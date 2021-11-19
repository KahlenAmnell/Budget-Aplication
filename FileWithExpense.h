#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H

#include "Markup.h"
#include "Expense.h"
#include "XMLFile.h"
#include "SupportingMethods.h"
#include <vector>
#include <string>

using namespace std;

class FileWithExpense :public XmlFile
{
public:
    FileWithExpense(string nameOfFileWithExpense);
    void addNewExpenseToFile(Expense expense);
private:

};

#endif // FILEWITHEXPENSE_H
