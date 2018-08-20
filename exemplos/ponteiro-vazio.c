#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  void *pp;
  int p2 = 10;
  pp = &p2;
  printf("%d\n", (*(int*)pp)); //Tem que castar quando executar.
  return 0;
}
