#include <stdio.h>

int main() {
  FILE *file = fopen("input.txt", "r");

  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  int counter = 0, is_prev_punctuation = 1;
  char c;

  while ((c = fgetc(file)) != EOF) {
    int is_punctuation = c == '.' || c == '!' || c == '?';

    if (!is_prev_punctuation && is_punctuation) {
      is_prev_punctuation = 1;
      counter++;
    } else if (!is_punctuation) {
      is_prev_punctuation = 0;
    }
  }

  if (!is_prev_punctuation) {
    counter++;
  }

  printf("%d\n", counter);

  fclose(file);

  return 0;
}
