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

