#include <stdio.h>

int main(int argc, char const *argv[]) {
  int arr[5], *pArr = arr;
  printf("De-me cinco valores inteiros: \n");
  for(int i =0; i < 5; i++, pArr+=1)  scanf("%d", pArr);
  pArr = arr;
  for(int i =0; i < 5; i++, pArr+=1)  printf(" %d |", (*pArr)*2);
  printf("\n");

  return 0;
}
