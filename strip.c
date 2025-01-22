#include <stdio.h>

int main() {
  char filename[50];
  printf("Enter filename: ");
  scanf("%s", filename);

  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("File not found\n");
    return 1;
  }

  char c;
  int is_prev_space = 0, is_first_letter = 1;

  while ((c = fgetc(fp)) != EOF) {
    if (c == ' ') {
      is_prev_space = 1;
    } else {
      if (is_prev_space && !is_first_letter) {
        putc(' ', stdout);
      }

      putc(c, stdout);

      is_prev_space = 0;
      is_first_letter = 0;
    }
  }
}
