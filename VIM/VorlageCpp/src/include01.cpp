#include "primemath.h"

// Ermittle den kleinsten Teiler der übergegebenen Zahl (verbesserte Fassung)
// Vorbedingung: Die Zahl muss >1 sein (keine Fehlerprüfung)
int64_t smallest_divisor_v1(int64_t n)
{
  // Teste gerade Zahlen separat, um in der Schleife unten Doppelschritte machen zu können
  if (n % 2 == 0)
    return 2;

  // Begrenzen des Suchraums: Wenn n = a * b, dann können nicht a _und_ b größer als die Wurzel sein,
  //                          d.h. wenn bis zur Wurzel kein Teiler gefunden wurde, dann kommt keiner mehr

  // Statt die Wurzel aus n zu ziehen
  // (was über Floating-Point-Arithmetik läuft und bei großen Zahlen ungenau wird)
  // wird hier k quadriert.
  // Das ist einfach verständlich, aber potentiell ineffizient (-> siehe Alternative smallest_divisor_v2).
  for (int64_t k = 3; k * k <= n; k += 2)
    if (n % k == 0)
      return k;

  return n;          // Kein Teiler gefunden -> n ist Primzahl
}


// Alternative ohne Quadrierung
int64_t smallest_divisor_v2(int64_t n)
{
  // Teste gerade Zahlen separat, um in der Schleife unten Doppelschritte machen zu können
  if (n % 2 == 0)
    return 2;

  // Begrenzen des Suchraums: Wenn n = a * b, dann können nicht a _und_ b größer als die Wurzel sein,
  //                          d.h. wenn bis zur Wurzel kein Teiler gefunden wurde, dann kommt keiner mehr

  // Statt die Wurzel direkt zu berechnen, kann k quadriert werden.
  //
  // Allerdings ist es möglicherweise ungünstig, ständig k*k zu berechnen, da Multiplikationen relativ aufwendig sind
  // und hier u.U. Milliarden Iterationen erfolgen.
  //
  // Eine Art "inkrementelle Quadrierung" berechnet (k+1)^2 aus k^2 mit zwei Additionen statt einer Multiplikation
  // und Additionen sind im Prinzip "billiger" als Multiplikationen.
  //
  // Das gilt zumindest für "einfache Hardware"; die Realität ist aber komplex:
  //   - Moderne Prozessoren haben ein superskalares Design, d.h. parallelisieren auf Instruktionsebene mit multiplen Execution Units.
  //   - Es hängt von vielen Details ab, ob eine theoretisch "aufwendige" Multiplikation tatsächlich gegen zwei Additionen verliert;
  //     moderne Hardware-Multiplier verwenden mehr Transistoren und sind viel schneller als frühere Implementierungen.
  //   - Insbesondere kann es bedeutsam sein, was genau im Schleifenrumpf geschieht.
  //     Wenn dort z.B. Multiplikationen stattfinden, könnte es hilfreich sein, k^2 nicht direkt zu bilden,
  //     da hardwaremäßig vielleicht nur eine Multiplikation "in flight" sein kann, aber mehrere Additionen.
  //     Findet im Rumpf nicht viel statt, ist k^2 u.U. quasi "kostenlos".
  //  -> Im "Ernstfall" muss immer via Benchmarking geprüft werden wie sich die einzelne Situation darstellt.

  for (int64_t k = 3, k_square = 9, k_square_diff = 16;
       k_square <= n;
       k += 2, k_square += k_square_diff, k_square_diff += 8)
    if (n % k == 0)
      return k;

  return n;          // Kein Teiler gefunden -> n ist Primzahl
}
