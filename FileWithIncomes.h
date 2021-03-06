#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "Markup.h"
#include "Incomes.h"
#include "XMLFile.h"
#include "SupportingMethods.h"
#include <vector>
#include <string>

using namespace std;

class FileWithIncomes :public XmlFile
{
public:
    FileWithIncomes(string nameOfFileWithIncomes);
    void addNewIncomeToFile(Incomes income);
    vector<Incomes> loadIncomesFromFile(int loggedUserId);
    int getLastIncomeId();

private:

};

#endif // FILEWITHINCOMES_H
