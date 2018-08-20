#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a, b,*c = &a, *d = &b;
  printf("Dois valores:\n> ");
  scanf("%d %d", &a, &b);
  printf("Endereço de maior valor: ");
  if (a > b) printf("%p = %d\n", c, *c);
  else printf("%p = %d\n", d, *d);
  return 0;
}
