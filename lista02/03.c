#include <stdio.h>

int dobroSoma(int *piA, int*piB);

int main(void)
{
  int iA, iB;
  printf("Escreva dois números inteiros separados por espaço: \n");
  scanf("%d %d", &iA, &iB);
  printf("O dobro dos valores são: %d e %d.\nA soma do dobro destes valores é: %d\n", iA, iB, dobroSoma(&iA, &iB));
}

int dobroSoma(int *piA, int*piB)
{
  *piA *= 2;
  *piB *= 2;
  return *piA + *piB;
}
