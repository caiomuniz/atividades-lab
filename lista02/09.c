/*Faça um programa que leia três valores inteiros  e chame uma função que  receba estes 3 valores  de  entrada  e ordene de  forma  decrescente,  ou  seja,  o  menor  valor  na  primeira variável, o segundo menor valor na variável do meio, e o maior valor na última variável. A função deve retornar o valor 1 se os três valores forem iguais e 0 se existirem valores diferentes. Exibir os valores ordenados na tela.*/

#include <stdio.h>
#include <stdlib.h>

int comparacao(int *a, int *b, int *c);
void troca(int *x, int *y);

int main(void)
{
  int a, b, c, comp;
  //Pega os valores
  scanf("%d %d %d", &a, &b, &c);

  //Faz a ordenação.
  comp = comparacao(&a, &b, &c);

  //Valores iguais.
  if (comp == 1)
    printf("Valores iguais!\n");
  //Imprime ordenado.
  printf("%d💕%d💕%d\n", a, b, c);
  return 0;
}


int comparacao(int *a, int *b, int *c)
{
  //Menor valor por último.
  if (*c > *b) troca(b, c);
  //Maior valor primeiro
  if (*b > *a) troca(a, b);
  //caso b < c nesta troca entre a e b.
  if (*c > *b) troca(b, c);

  if (*a == *b && *b == *c) return 1;
  else return 0;
}

void troca(int *x, int *y){
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}
