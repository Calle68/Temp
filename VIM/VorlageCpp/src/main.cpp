#include <iostream>

#include "userinput.h"          // enthält Deklaration:  int64_t enter_prime_candidate();
#include "primemath.h"          // enthält Deklaration:  int64_t smallest_divisor(int64_t n);

/*
 * Primzahlen verschiedener Größe zum Testen:
 *             739397,
 *           27644437, 
 *          479001599,
 *         2147483647,   (= 2^31 - 1) -> größte Primzahl, die noch in 32-Bit-Signed-Integer passt
 *         6620830889,
 *        51539607551,
 *       200560490131,
 *       824633720831,    
 *   9999999900000001,
 * 909090909090909091
 */

int main()
{
  // Frage User wiederholt nach Zahl zum Primzahltest und prüfe sie bis User Abbruch anfordert (Eingabe 0)
  while (true) {
    int64_t val = enter_prime_candidate();

    if (val == 0)   // User hat Abbruch angefordert
      return 0;

    int64_t smallest_div = smallest_divisor_v1(val);    // alternativ: ... smallest_divisor_v2(val);

    std::cout << "Die Zahl " << val << " ist ";
    if (smallest_div == val)
      std::cout << "eine Primzahl." << std::endl;
    else
      std::cout << "keine Primzahl: " << smallest_div << " ist ein Teiler." << std::endl;
  }
}
