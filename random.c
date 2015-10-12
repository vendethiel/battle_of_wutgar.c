#include <stdlib.h>
#include <time.h>

int rand_between(int a, int b) {
  static int init;

  if (!init) {
    srand(time(NULL));
    init = 1;
  }
  return rand() % (b - a + 1) + a;
}
