#include <iostream>

#include "userinput.h"
#include "primemath.h"

/*
 * Primzahlen verschiedener Größe zum Testen:
 *             739397,
 *           27644437, 
 *          479001599,
 *         2147483647,   (= 2^31 - 1) -> größte Primzahl, die noch in 32-Bit-Signed-Integer passt
 *         6620830889,
 *        51539607551,
 *       200560490131,
 *       514523452343,
 *       824633720831,
 *   9999999900000001,
 * 909090909090909091
 */


int main()
{
  // Frage interaktiv wiederholt nach Zahl zum Primzahltest und prüfe sie bis Abbruch angefordert wird (Eingabe 0)
  while (true) {
    int64_t val = enter_prime_candidate();

    if (val == 0)  // Abbruch wurde angefordert
      return 0;

    int64_t smallest_div = smallest_divisor(val);

    // Eine Zahl ist prim genau dann, wenn ihr kleinster Teiler (>1) sie selbst ist

    std::cout << "Die Zahl " << val << " ist ";
    if (smallest_div == val)
      std::cout << "eine Primzahl." << std::endl;
    else
      std::cout << "keine Primzahl: " << smallest_div << " ist ein Teiler." << std::endl;
  }
}