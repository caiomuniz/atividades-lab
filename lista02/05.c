#include <stdio.h>

int main(void)
{
  float pinto[10], *pPinto = pinto;
  for (int i = 0; i < 10; i++) {
    printf("Posição %d da array: %p\n", i+1, pPinto);
    pPinto += 1;
  }
}
