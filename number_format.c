#include <stdio.h>

int main() {
  FILE *f = fopen("input.txt", "r");

  if (f == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  char c;

  while ((c = fgetc(f)) != ':') {
    printf("%c", c);
  }

  printf(" +7(");

  while ((c = fgetc(f)) != '-') {}

  while ((c = fgetc(f)) != '-') {
    printf("%c", c);
  }

  printf(")");

  while ((c = fgetc(f)) != EOF) {
    printf("%c", c);
  }
}