#include "XmlFile.h"


void XmlFile::setChildData(string newData) {
    cMarkupXml.SetChildData(newData);
}

bool XmlFile::elementExists(string tagName) {
    return cMarkupXml.FindElem(tagName);
}

string XmlFile::getChildData() {
    return cMarkupXml.GetChildData();
}

void XmlFile::findChildElement(string tagName) {
    cMarkupXml.FindChildElem(tagName);
}

void XmlFile::resetPosition() {
    cMarkupXml.ResetPos();
}

void XmlFile::resetChildPosition() {
    cMarkupXml.ResetChildPos();
}

void XmlFile::saveFile() {
    cMarkupXml.Save(FILE_NAME);
}

void XmlFile::findElement() {
    cMarkupXml.FindElem();
}

void XmlFile::findElement(string tagName) {
    cMarkupXml.FindElem(tagName);
}

void XmlFile::intoElement() {
    cMarkupXml.IntoElem();
}

void XmlFile::addElement(string tagName) {
    cMarkupXml.AddElem(tagName);
}

void XmlFile::addElement(string tagName, string data) {
    cMarkupXml.AddElem(tagName, data);
}

void XmlFile::addElement(string tagName, int data) {
    cMarkupXml.AddElem(tagName, data);
}

bool XmlFile::fileExists() {
    return cMarkupXml.Load(FILE_NAME);
}
/*
void XmlFile::deleteFile(string fileName) {

    if (remove(fileName.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << fileName << endl;
}

void XmlFile::changeFileName(string oldName, string newName) {

    if (rename(oldName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << oldName << endl;
}

bool XmlFile::isEmpty(fstream &xmlFile) {

    xmlFile.seekg(0, ios::end);
    if (xmlFile.tellg() == 0)
        return true;
    else
        return false;
}
*/
