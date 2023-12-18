#include <iostream>

#include "addieren.h"

void addieren()
{
    int a, b, c;
    std::cout << "Erste Zahl eingeben: \n";
    std::cin >> a;
    std::cout << "Zweite Zahl eingeben: \n";
    std::cin >> b;

    c = a + b;
    std::cout << "Ergebnis = " << c << std::endl;
}