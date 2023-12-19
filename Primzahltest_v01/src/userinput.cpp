#include <iostream>

#include "userinput.h"

int64_t enter_prime_candidate()
{
  int64_t val;

  // Eingabe ohne Fehlerbehandlung
  std::cout << "\nGeben Sie eine Zahl zum Primzahltest ein oder 0 zum Beenden: " << std::endl;
  std::cin >> val;

  return val;
}