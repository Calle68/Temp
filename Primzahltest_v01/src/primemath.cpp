#include "primemath.h"

// Ermittle den kleinsten Teiler der übergegebenen Zahl auf naive Weise
// Vorbedingung: Die Zahl muss >1 sein (keine Fehlerprüfung)
// (Hinweis: Optimierungen finden sich in den Projekten "02_Primzahltest_v2 / v3")
int64_t smallest_divisor(int64_t n)
{
  for (int64_t k = 2; k < n; ++k)
    if (n % k == 0)
      return k;  // Teiler k gefunden -> n ist keine Primzahl

  return n;  // kein Teiler gefunden -> n ist Primzahl
}