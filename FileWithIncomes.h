#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "Markup.h"
#include "Incomes.h"
#include "XMLFile.h"
#include "SupportingMethods.h"
#include <vector>

using namespace std;

class FileWithIncomes :public XmlFile
{
public:
    FileWithIncomes(string nameOfFileWithIncomes);
    void addNewIncomeToFile(Incomes income);

private:
    void startTheFile(CMarkup &xml);
};

#endif // FILEWITHINCOMES_H
