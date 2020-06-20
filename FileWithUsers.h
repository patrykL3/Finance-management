#ifndef FILE_WITH_USERS_H
#define FILE_WITH_USERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;


class FileWithUsers:private XmlFile {

public:

    FileWithUsers(string fileNameWithUsers) : XmlFile(fileNameWithUsers) {};
    void addUserToFile(User user);
    void editUsersPasswordInFile(User user);
    vector <User> loadUsersFromFile();
};


#endif
