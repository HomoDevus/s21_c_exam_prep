#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int x, y, z;
} vector;

int main() {
  int size;

  printf("Enter amount of vectors: \n");
  scanf("%d", &size);

  if (size < 1) {
    printf("0");
    return 0;
  }

  vector* vectors = (vector*)malloc(size * sizeof(vector));

  for (int i = 0; i < size; i++) {
    printf("Enter vector x y and z %d: ", i + 1);
    scanf("%d %d %d", &vectors[i].x, &vectors[i].y, &vectors[i].z);
  }

  double distance = 0.0;

  for (int i = 1; i < size; i++) {
    distance += sqrt(pow(vectors[i].x - vectors[i - 1].x, 2) + pow(vectors[i].y - vectors[i - 1].y, 2) + pow(vectors[i].z - vectors[i - 1].z, 2));
  }

  printf("Distance between two vectors: %lf\n", distance);

  free(vectors);

  return 0;
}