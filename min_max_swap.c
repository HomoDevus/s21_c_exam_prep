#include <stdio.h>

int main(void) {
  char curr;
  int counter = 0;

  while (curr != '\n') {
    scanf("%d", &curr);

    if (curr == '.' || curr == '!') {
      scanf("%d", &curr);
      if (curr == '!') {
        scanf("%d", &curr);

      }
  }

  printf("%d\n", counter);
}