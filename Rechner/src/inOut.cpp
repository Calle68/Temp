#include <iostream>
#include "inOut.h"

using namespace std;

int cli::abfrage()
{
    std::cout << "Neue Abfrage!" << std::endl;
    std::cout << "Bitte eine Zahl eingeben" << std::endl;
std::cin >> zahl >> std:: endl;

    return 0;
}

int cli::ausgabe(int ergebnis)
{
    std::cout << "Das Ergebnis ist :" << ergebnis << endl;

    return 0;
}