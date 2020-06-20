#ifndef XML_FILE_H
#define XML_FILE_H

#include <iostream>
#include <fstream>
#include "Markup.h"

using namespace std;


class XmlFile {

protected:

    CMarkup cMarkupXml;
    const string FILE_NAME;

    bool isEmpty(fstream &xmlFile);
    void deleteFile(string fileName);
    void changeFileName(string oldName, string newName);

    void saveFile(string fileName);
    void findElement();
    void findElement(string tagName);
    void findChildElement(string tagName);
    void intoElement();
    void resetPosition();
    void addElement(string tagName);
    void addElement(string tagName, string data);
    void setChildData(string newData);
    bool fileExists(string xmlFileName);
    bool elementExists(string tagName);
    string getChildData();


    XmlFile(string fileName) : FILE_NAME(fileName) {}
};


#endif
