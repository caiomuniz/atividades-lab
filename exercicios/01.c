#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int val1 = 4, *pin = &val1;
  float val2 = 0.2, *pfl = &val2;
  printf("int: %d float: %.1f\n", val1, val2);
  *pin = ((*pin+3)*3)*2;
  *pfl = (*pfl)*210;
  printf("int modificada: %d, float modificada: %.1f\n", *pin, *pfl);
  return 0;
}
