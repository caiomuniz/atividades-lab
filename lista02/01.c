#include <stdio.h>

void troca(int *val1, int *val2);

int main(void)
{
  int val1, val2;
  printf("Coloque dois valores:\n> ");
  scanf("%d %d", &val1, &val2);
  troca(&val1, &val2);
  printf("%d %d\n", val1, val2);
}

void troca(int *val1, int *val2) {
  int aux;
  aux = *val1;
  *val1 = *val2;
  *val2 = aux;
}
