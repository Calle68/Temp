#include <iostream>
#include "cliAusgabe.h"
#include "rechenarten.h"
#include "inOut.h"

using namespace std;

cli ioCli;
rArten rechenArt;

int main()
{
    std::cout << "Addieren" << std::endl;
    ioCli.abfrage();
    rechenArt.addieren(ioCli.zahl1, ioCli.zahl2);
    ioCli.ausgabe(rechenArt.ergebnis);

    std::cout << "Subtrahieren" << std::endl;
    ioCli.abfrage();
    rechenArt.subtrahieren(ioCli.zahl1, ioCli.zahl2);
    ioCli.ausgabe(rechenArt.ergebnis);

    return 0;
}