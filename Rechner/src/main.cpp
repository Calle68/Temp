#include <iostream>
#include "cliAusgabe.h"
#include "rechenarten.h"
#include "inOut.h"

using namespace std;

cli ioCli;
rArten rechenArt;

int main()
{
    std::cout << "Rechner" << std::endl;
    ioCli.abfrage();    
    ioCli.ausgabe(rechenArt.ergebnis);

    return 0;
}