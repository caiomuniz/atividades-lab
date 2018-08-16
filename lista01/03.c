#include <stdio.h>
#include <string.h>

void reverte(char string[]);

int main(int argc, char const *argv[]) {
  char palavra[250];
  printf("Escreva uma palavra:\n> ");
  fgets(palavra, 250, stdin);
  printf("Invertido se torna: ");
  reverte(palavra);
  printf("\n");
  return 0;
}

//Reverte uma string
void reverte(char string[]) {
  int tam = strlen(string)-1;
  for (size_t i = tam; i > 0; i--) {
    printf("%c", string[i-1]);
  }
}
