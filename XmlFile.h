#ifndef XML_FILE_H
#define XML_FILE_H

#include <iostream>
#include "Markup.h"

using namespace std;


class XmlFile {

    CMarkup cMarkupXml;
    const string FILE_NAME;

protected:

    XmlFile(string fileName) : FILE_NAME(fileName) {}

    void saveFile();
    void findElement();
    void findElement(string tagName);
    void findChildElement(string tagName);
    void intoElement();
    void resetPosition();
    void resetChildPosition();
    void addElement(string tagName);
    void addElement(string tagName, string data);
    void addElement(string tagName, int data);
    void setChildData(string newData);
    bool fileExists();
    bool elementExists(string tagName);
    string getChildData();
};


#endif
