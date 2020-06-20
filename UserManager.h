#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "FileWithUsers.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;


class UserManager {

    vector<User> users;
    FileWithUsers fileWithUsers;
    int userIdThatIsLoggedIn;

    bool existLogin(string login);
    int getNewUserId();
    User provideDataOfNewUser();
    User getUserData();

public:

    UserManager(string fileNameWithUsers): fileWithUsers(fileNameWithUsers) {
        userIdThatIsLoggedIn = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    int getIdLoggedUser();
    bool isLogged();
    void userLogin();
    void userRegistration();
    void displayAllUsers();
    void changePasswordLoggedUser();
    void logOutUser();
};

#endif
