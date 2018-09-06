#include <stdio.h>
#include <stdlib.h>

//TADs
typedef struct termo
{
  int coeficiente;
  char incognita;
  int expoente;
} Tterm;

//Prototipos
Tterm *initialEq(int nTerms);
Tterm *simplifiedEq(Tterm *arr, int nTerms);

int main (void)
{
  int numTerms;
  char *incognitas;
  Tterm *array;// *fixed;
  printf("Qual o numero de termos?\n> ");
  scanf(" %d", &numTerms);
  incognitas = malloc(sizeof(char)*numTerms);

  //Cria equation
  array = initialEq(numTerms);
  //Creates the second array
  //Tterm *fixed = simplifiedEq(array, numTerms);

  int tamf = sizeof(fixed)/sizeof(Tterm);

  //Prints the equation on the screen.
  for (size_t i = 0; i < numTerms; i++)
  {
    if (i == numTerms-1)
      printf("%i%c^%i ", (array+i)->coeficiente, (array+i)->incognita, (array+i)->expoente);
   else
    printf("%i%c^%i + ", (array+i)->coeficiente, (array+i)->incognita, (array+i)->expoente);
  }
  printf("= 0\n");

  /*
   *  Prints the equation on the screen.
   *  for (size_t i = 0; i < tamf; i++)
   *  {
   *    if (i == numTerms-1)
   *      printf("%i%c^%i ", (fixed+i)->coeficiente, (fixed+i)->incognita, (fixed+i)->expoente);
   *    else
   *      printf("%i%c^%i + ", (fixed+i)->coeficiente, (fixed+i)->incognita, (fixed+i)->expoente);
   *  }
   *  printf("= 0\n");
   */

  return 0;
}

Tterm *initialEq(int nTerms)
{
  Tterm *array = malloc(sizeof(Tterm)*nTerms);

  //Gets the values for the equation
  for (size_t i = 0; i < nTerms; i++) {
    printf("Coeficiente do termo %li:\n> ", i+1);
    scanf(" %d", &(array+i)->coeficiente);
    printf("Incognita do termo %li:\n> ", i+1);
    scanf(" %c", &(array+i)->incognita);
    printf("Expoente do termo %li:\n> ", i+1);
    scanf(" %d", &(array+i)->expoente);
  }
  return array;
}

Tterm *simplifiedEq(Tterm *arr, int nTerms)
{
  Tterm *simp = malloc(sizeof(Tterm));
  int tam = 1;
  simp->incognita = arr->incognita;
  simp->expoente  = arr->expoente;
  //Passa por toda a array, pegando seu tamanho.
  for (size_t i = 0; i < nTerms; i++)
  {
    if ((simp)->incognita != (arr+i)->incognita || (simp)->expoente != (arr+i)->expoente)
      tam++;
    else continue;
  }
  //Tamanho ok.

  simp = realloc(simp, sizeof(Tterm)*tam);
  simp->coeficiente = 0;
  simp->incognita = arr->incognita;
  simp->expoente  = arr->expoente;

  //Recomeçar por aqui. Não faço ideia do que fazer com este código.
  int count = 0;
  size_t j = 0;

  for (size_t i = 1; i < nTerms; i++)
  {
    if (!((simp+i)->incognita == (arr+j)->incognita && (simp+i)->expoente == (arr+j)->expoente)) {
      (simp+i)->incognita = (arr+j)->incognita;
      (simp+i)->expoente  = (arr+j)->expoente;
    }
    for (j = count; j < tam; j++)
    {
      if ((simp+i)->incognita == (arr+j)->incognita && (simp+i)->expoente == (arr+j)->expoente)
        (simp+i)->coeficiente += (arr+j)->coeficiente;

      else continue;
    }

    count++;
  }
  return simp;
}
