#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char string[300];
  printf("Escreva uma string:\n> ");
  fgets(string, 300, stdin);
  printf("Sem as vogais fica:\n");

  for (size_t i = 0; i < strlen(string); i++) {
    if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
      continue;
    printf("%c", string[i]);
  }
  return 0;
}
