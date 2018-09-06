//Include libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Booleana
typedef int bool;
#define true 1
#define false 0

//Prototipos
void ler_senha(int *aposta, int n);
int* compara_senha(int *senha, int *senhausuario, int *qtdacertos, int ns, int nu);
void sorteia_valores(int *sorteio, int n); //Cria o vetor com a senha.


int main(int argc, char const *argv[]) {
  //Variaveis
  int *senha, *aposta;
  int tamSenha, contador = 1;
  bool TESTMODE = false;


  if(argc!=2)
  {
    printf("Defina a dificuldade! Uso: ./senha [1|2]\n");
    printf("1 - Facil\n");
    printf("2 - Dificil\n");
    return 1;
  }
  if (*argv[1] == '1')
  {
    printf("Modo Facil.\n");
    senha = malloc(sizeof(int)*3);
    aposta = malloc(sizeof(int)*3);
    tamSenha = 3;
  }
  else if (*argv[1] == '2')
  {
    printf("Modo Dificil.\n");
    senha = malloc(sizeof(int)*4);
    aposta = malloc(sizeof(int)*4);
    tamSenha=4;
  }
  else if (*argv[1] == '3')
  {
    printf("Modo de Teste\n");
    senha = malloc(sizeof(int)*4);
    aposta = malloc(sizeof(int)*4);
    tamSenha=4;
    TESTMODE = true;
  }

  //Cria o vetor com a senha.
  sorteia_valores(senha, tamSenha);

  if (TESTMODE) //mostra senha no modo de teste.
  {
    for (size_t i = 0; i < tamSenha; i++) {
      printf("%i ", *(senha+i));
    }
    printf("\n");
  }

  //OK
  while (true) {
    ler_senha(aposta, tamSenha);






    contador++;
  }

  return 0;
}

//Cria o vetor com a senha.
void sorteia_valores(int *sorteio, int n)
{
  bool usados[10] = {false};
  srand(time(NULL));
  for (size_t i = 0; i < n; i++) {
    *(sorteio+i) = rand() % 9 + 1;
    //Verifica se o numero  ja foi colocado antes.
    if (usados[*(sorteio+i)-1] == false) usados[*(sorteio+i)-1] = true;
    else i--;
  }
}

void ler_senha(int *aposta, int n)
{
  bool usados[10] = {false};
  printf("Digite a senha de %i digitos:\n> ", n);
  for (size_t i = 0; i < n; i++)
  {
    scanf(" %i", (aposta+i));
    if (usados[*(aposta+i)-1] == false) usados[*(aposta+i)-1] = true;
    else
    {
      printf("Valor invalido! Digite a senha novamente.\n");
      i = 0; for (size_t j = 0; j < 10; j++) usados[j] = 0;
    }
    if (*(aposta+i) < 1 || *(aposta+i) > 9) {
      printf("Valor invalido! Digite a senha novamente.\n");
      i = 0; for (size_t j = 0; j < 10; j++) usados[j] = 0;
    }
  }
}
