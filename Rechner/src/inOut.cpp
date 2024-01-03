#include <iostream>
#include "inOut.h"
#include "rechenarten.h"

using namespace std;


rArten rechenArt;

int cli::abfrage()
{
    std::cout << "Bitte eine Zahl eingeben" << std::endl;
    std::cin >> zahl;
    std::cin >> rechenart;

    switch (rechenart)
    {
        case '+':
            rechenArt.addieren(zahl);

        case '-':
            rechenArt.subtrahieren(zahl);
    }

    return 0;
}

int cli::ausgabe(int ergebnis)
{
    std::cout << "Das Ergebnis ist :" << ergebnis << endl;

    return 0;
}