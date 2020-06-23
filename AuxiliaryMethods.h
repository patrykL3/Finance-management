#ifndef AUXILIARY_METHODS_H
#define AUXILIARY_METHODS_H

#include <sstream>
#include <iostream>

using namespace std;


class AuxiliaryMethods {

public:

    static char loadCharacter();
    static string loadLine();
    static float convertStringToFloat(string number);
    static string convertIntToString(int number);
    static string convertFloatToString(float number);
    static int convertStringToInt(string number);
    static void replaceCommasWithPeriods(string &data);
    /*static string pobierzLiczbe(string tekst, int pozycjaZnaku);

    static int wczytajLiczbeCalkowita();*/
};


#endif
