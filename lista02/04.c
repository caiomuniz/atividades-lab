/* Crie um programa que contenha um procedimento que permita passar por parâmetro dois números reais A  e  B.  A  função deverá calcular  a soma  entre  estes  dois  números  e armazenar  o  resultado  na  variável  A. Este  procedimento deverá modificar  o  valor  do primeiro  parâmetro. Imprima os valores de A e B na função principal. */
#include <stdio.h>

void soma(int *piA, int *piB)
{
  *piA = *piA + *piB;
}

int main(void)
{
  int iA, iB;
  printf("Escolha dois números:\n> ");
  scanf("%d %d", &iA, &iB);
  soma(&iA, &iB);
  printf("Suas variáveis são: %d e %d.\n", iA, iB);
}
