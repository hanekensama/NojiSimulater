#include "asm.h"

int main() {
  LI(r1, 0);
  LI(r2, 1);
  LI(r3, 1);
  LI(r4, -101);
 LP1:
  ST(r1, r2);
  ADD(r1, r1, r3);
  ADD(r5, r1, r4);
  BNZ(r5, LP1);

  LI(r1, 0);
  LI(r2, 0);
  LI(r3, 2);
  LI(r4, -102);
 LP2:
  ST(r1, r2);
  ADD(r1, r1, r3);
  ADD(r5, r1, r4);
  BNZ(r5, LP2);

  LI(r1, 0);
  LI(r2, 0);
  LI(r3, 3);
  LI(r4, -102);
 LP3:
  ST(r1, r2);
  ADD(r1, r1, r3);
  ADD(r5, r1, r4);
  BNZ(r5, LP3);
  
  LI(r0, 0);
  LI(r1, 0);
  LI(r3, 1);
  LI(r4, -101);
 LP4:
  LD(r2, r1);
  ADD(r0, r0, r2);
  ADD(r1, r1, r3);
  ADD(r5, r1, r4);
  BNZ(r5, LP4);

  reg();
  printf("\n");
  mem();
  printf("\n");
  memAt(1);
  return 0;
}
