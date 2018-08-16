#include <stdio.h>

int main(void)
{
  char string[300000];
  int counter = 0;
  printf("Digite a string cujo tamanho deve ser calculado:\n> ");
  fgets(string, 300000, stdin);

  while (string[counter]) counter++;
  printf("Tem tamanho %d\n", --counter);
}
