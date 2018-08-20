#include <stdio.h>

int maior(int *val1, int *val2);

int main(int argc, char const *argv[]) {
  int val1, val2; //Dois valores dados pelo usuario
  printf("Dois valores:\n>");
  scanf("%d %d", &val1, &val2);
  printf("Maior dos valores: %d\n", maior(&val1, &val2));
  printf("Valores:\n%p = %d\n%p = %d\n", &val1, val1, &val2, val2); //Endereço de memória
  return 0;
}

int maior(int *val1, int *val2)
{
  if (*val1>*val2) return *val1;
  return *val2;
}
