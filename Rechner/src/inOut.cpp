#include <iostream>
#include "inOut.h"

using namespace std;

int cli::abfrage()
{
    std::cout << "Bitte erste Zahl eingeben" << std::endl;
    std::cin >> zahl1;
    std::cout << "Bitte zweite Zahl eingeben" << std::endl;
    std::cin >> zahl2;

    return 0;
}

int cli::ausgabe(int ergebnis)
{
    std::cout << "Das Ergebnis ist :" << ergebnis << endl;

    return 0;
}