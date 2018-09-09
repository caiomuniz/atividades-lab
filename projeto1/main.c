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
  int *senha, *aposta, *qtAcertos = malloc(sizeof(int)*2);
  int tamSenha, contador = 1, dif;
  bool TESTMODE;
  char newGame;

  //Quantas vezes usuario quiser jogar
  while (true)
  {
    contador = 1;
    TESTMODE = false;
    qtAcertos = malloc(sizeof(int)*2);
    
    system("clear");
    
	printf("Defina a dificuldade!\n");
	printf("1 - Facil(senha de 3 digitos)\n");
	printf("2 - Dificil(senha de 4 digitos)\n");
	printf("3 - Teste(senha de 4 digitos)\n> ");
    
    do
    {
    	scanf(" %i", &dif);
    	if(dif == 1 || dif == 2 || dif == 3)
    		break;
    	else
    		printf("Opcao invalida! Digite novamente.\n> ");
    }while(true);

    do
    {
      if (dif == 1)
      {
        printf("Modo Facil.\n");
        senha = malloc(sizeof(int)*3);	//Aloca tamanho do vetor senha
        aposta = malloc(sizeof(int)*3);	//Aloca tamanho do vetor aposta
        tamSenha = 3; break;
      }
      else if (dif == 2)
      {
        printf("Modo Dificil.\n");
        senha = malloc(sizeof(int)*4);	//Aloca tamanho do vetor senha
        aposta = malloc(sizeof(int)*4);	//Aloca tamanho do vetor aposta
        tamSenha=4; break;
      }
      else if (dif == 3)
      {
        printf("Modo de Teste\n");
        senha = malloc(sizeof(int)*4);	//Aloca tamanho do vetor senha
        aposta = malloc(sizeof(int)*4);	//Aloca tamanho do vetor aposta
        tamSenha=4;
        TESTMODE = true; break;
      }
    }while(true);

    //Cria o vetor com a senha.
    sorteia_valores(senha, tamSenha);

    if (TESTMODE) //mostra senha no modo de teste.
    {
      for (size_t i = 0; i < tamSenha; i++) {
        printf("%i ", *(senha+i));
      }
      printf("\n");
    }
	
    while (true) {
      	//Lê a senha dada pelo usuario.
      	ler_senha(aposta, tamSenha);
		qtAcertos = compara_senha(senha, aposta, qtAcertos, tamSenha, tamSenha);

      	printf("Tentativa no. %i:\n", contador);
      	printf("%i %i\n", *qtAcertos, *(qtAcertos+1));
      	
      	if (*(qtAcertos) == tamSenha) {
      		printf("Parabéns! Voce venceu em %i tentativas!\n", contador);
        	break;
      }
      contador++;
      *qtAcertos = 0; *(qtAcertos+1) = 0;
    }
	
	//Desaloca os vetores
    free(senha); senha = NULL;
    free(aposta); aposta = NULL;
    free(qtAcertos); qtAcertos = NULL;

    //Fim de jogo.
    printf("Quer jogar novamente?\nDigite N para nao ou qualquer tecla para reiniciar.\n> ");
    scanf(" %c", &newGame);

    if (newGame == 'N'||newGame == 'n') break;
  }
  system("clear");
  printf("Tenha um bom dia!\n");
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
    if (usados[*(sorteio+i)] == false) usados[*(sorteio+i)] = true;
    else i--; //Caso sim, repetir aquele rand.
  }
}

void ler_senha(int *aposta, int n)
{
  bool usados[10] = {false};
  bool FLAG = false;
  printf("Digite a senha de %i digitos:\n> ", n);

  do{
    FLAG = false;
      for (size_t i = 0; i < n; i++)
      {
        scanf(" %i", (aposta+i));

        if (usados[*(aposta+i)-1] == false) usados[*(aposta+i)-1] = true;
        else FLAG = true;
        if (*(aposta+i) < 1 || *(aposta+i) > 9) FLAG = true;

      }
      if (FLAG)
      {
        printf("Valor invalido! Digite a senha novamente.\n> ");
        for (size_t j = 0; j < 10; j++) usados[j] = false;
      } else break;
  } while(true);
}


int* compara_senha(int *senha, int *senhausuario, int *qtdacertos, int ns, int nu)
{
  *qtdacertos = 0; *(qtdacertos+1) = 0;

  for (size_t i = 0; i < nu; i++) {
    for (size_t j = 0; j < ns; j++) {
      if (*(senhausuario+i) == *(senha+j)) {
        if (i==j) *(qtdacertos) += 1;
        else *(qtdacertos+1) += 1;
      }
    }
  }

  return qtdacertos;
}
