#include <iostream>
#include "rechenarten.h"
#include "inOut.h"

using namespace std;


int rArten::addieren(int zahl1, int zahl2)
{
    ergebnis = zahl1 + zahl2;
    return ergebnis;
}

int rArten::subtrahieren(int zahl1, int zahl2)
{
    ergebnis = zahl1 - zahl2;
    return ergebnis;
}