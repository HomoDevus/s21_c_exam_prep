#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int row, int col) {
  int** matrix = (int**)malloc(row * sizeof(int*));

  for (int i = 0; i < row; i++) {
    matrix[i] = (int*)malloc(col * sizeof(int));
  }

  return matrix;
}

void free_matrix(int** matrix, int row) {
  if (matrix == NULL) return;

  for (int i = 0; i < row; i++) {
    if (matrix[i] != NULL) {
      free(matrix[i]);
    }
  }
}

void input_matrix(int **matrix, int rows, int cols) {
  printf("Enter matrix:\n");

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

void print_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }

    printf("\n");
  }
}

int main() {
  int a_rows, a_cols, b_rows, b_cols;

  printf("Enter rows and columns of first matrix: ");
  scanf("%d %d", &a_rows, &a_cols);
  printf("Enter rows and columns of second matrix: ");
  scanf("%d %d", &b_rows, &b_cols);

  if (a_rows != b_cols) {
    printf("n/a\n");
    return 1;
  }

  int** matrix_a = create_matrix(a_rows, a_cols);
  int** matrix_b = create_matrix(b_rows, b_cols);

  input_matrix(matrix_a, a_rows, a_cols);
  input_matrix(matrix_b, b_rows, b_cols);

  int result_rows = a_rows;
  int result_cols = b_cols;
  int** result = create_matrix(result_rows, result_cols);

  for (int i = 0; i < a_rows; i++) {
    for (int j = 0; j < b_cols; j++) {
      for (int k = 0; k < a_cols; k++) {
        result[i][j] += matrix_a[i][k] * matrix_b[k][j];
      }
    }
  }

  printf("Result:\n");

  print_matrix(result, result_rows, result_cols);

  free_matrix(matrix_a, a_rows);
  free_matrix(matrix_b, b_rows);
  free_matrix(result, result_rows);

  return 0;
}