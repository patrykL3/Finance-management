#include "FileWithUsers.h"


void FileWithUsers::addUserToFile(User user) {
    if(!fileExists()) {
        addElement("Users");
    }
    findElement();
    intoElement();
    addElement("User");
    intoElement();
    addElement("UserId", user.getId());
    addElement("Login", user.getLogin());
    addElement("Password", user.getPassword());
    addElement("Name", user.getName());
    addElement("Surname", user.getSurname());

    saveFile();
}

vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector <User> users;

    if(fileExists()) {
        resetPosition();
        findElement("Users");
        intoElement();

        while (elementExists("User")) {
            findChildElement("UserId");
            user.setId(AuxiliaryMethods::convertStringToInt(getChildData()));
            findChildElement("Login");
            user.setLogin(getChildData());
            findChildElement("Password");
            user.setPassword(getChildData());
            findChildElement("Name");
            user.setName(getChildData());
            findChildElement("Surname");
            user.setSurname(getChildData());
            users.push_back(user);
        }
    }

    return users;
}

void FileWithUsers::editUsersPasswordInFile(User user) {
    if(fileExists()) {
        findElement("Users");
        intoElement();

        while (elementExists("User")) {
            findChildElement("UserId");
            if (getChildData() == AuxiliaryMethods::convertIntToString(user.getId())) {
            findChildElement("Password");
            setChildData(user.getPassword());
            }
        }
    }
    saveFile();
}

