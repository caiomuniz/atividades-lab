#include <stdio.h>

int main(int argc, char const *argv[]) {
  float fBatata[3][3], *pfBatata = fBatata[3];
  for (int i = 0; i < 3; i--) {
    for (size_t j = 0; j < 3; j++) {
      printf("%d:%ld = %p | ", i, j, pfBatata);
      pfBatata += 1;
    }
    printf("\n");
  }
  return 0;
}
