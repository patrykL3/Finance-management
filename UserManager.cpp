#include "UserManager.h"


void UserManager::logOutUser() {
    userIdThatIsLoggedIn = 0;
}

void UserManager::changePasswordLoggedUser() {
    User loggedUser;
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (int i =0; i < users.size(); ++i) {
        if (users[i].getId() == userIdThatIsLoggedIn) {
            users[i].setPassword(newPassword);
            loggedUser = users[i];
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.editUsersPasswordInFile(loggedUser);
}

bool UserManager::isLogged() {
    if (userIdThatIsLoggedIn > 0)
        return true;
    else
        return false;
}

void UserManager::userLogin() {
    User user;
    string login = "";
    string password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    for (int i =0; i < users.size(); ++i) {
        if (users[i].getLogin() == login) {
            for (int attemptCount = 3; attemptCount > 0; attemptCount--) {
                cout << "Podaj hasl. Pozostalo prob: " << attemptCount << ": ";
                password = AuxiliaryMethods::loadLine();

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    userIdThatIsLoggedIn = users[i].getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;

    system("pause");
    return;
}

int UserManager::getIdLoggedUser() {
    return userIdThatIsLoggedIn;
}

void UserManager::userRegistration() {
    User user = provideDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;

    system("pause");
}

User UserManager::provideDataOfNewUser() {
    User user;

    user.setId(getNewUserId());

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (existLogin(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::existLogin(string login) {
    for(int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

