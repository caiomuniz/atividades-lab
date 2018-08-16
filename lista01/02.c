#include <stdio.h>

int main(int argc, char const *argv[]) {
  char nome[250];
  printf("Digite seu nome: \n> ");
  scanf("%s", nome);
  if (nome[0]=='a'||nome[0] == 'A') printf("Bom dia, %s!\n", nome);
  return 0;
}
