#include "AuxiliaryMethods.h"


void AuxiliaryMethods::replaceCommasWithPeriods(string &data) {
    for(int i = 0; i < data.length(); ++i) {
        if(data[i] == ',')
            data.replace(i, 1, ".");
    }
}

float AuxiliaryMethods::convertStringToFloat(string number) {
    float numberFloat;
    istringstream iss(number);
    iss >> numberFloat;

    return numberFloat;
}

int AuxiliaryMethods::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertFloatToString(float number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char AuxiliaryMethods::loadCharacter() {
    string inputData = "";
    char character  = {0};

    while (true) {
        cin.sync();
        getline(cin, inputData);

        if (inputData.length() == 1) {
            character = inputData[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string AuxiliaryMethods::loadLine() {
    string inputData = "";
    getline(cin, inputData);
    return inputData;
}

