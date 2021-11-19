#ifndef XMLFILE_H
#define XMLFILE_H

#include "Markup.h"

using namespace std;

class XmlFile
{
public:
    XmlFile(string nameOfXmlFile);
    void startTheFile(CMarkup &xml);

protected:
    const string XML_FILE;
};
#endif // XMLFILE_H
