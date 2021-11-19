#include "XMLFile.h"

XmlFile::XmlFile(string nameOfXmlFile)
    : XML_FILE(nameOfXmlFile) {}

void XmlFile::startTheFile(CMarkup &xml)
{
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem(XML_FILE);
}
