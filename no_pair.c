#include <stdio.h>

int main() {
  int number;
  int result = 0;

  printf("Введите последовательность чисел (завершите ввод -1):\n");

  while (1) {
    scanf("%d", &number);
    if (number == -1) {
      break; // Завершаем ввод
    }
    result ^= number; // Используем XOR для поиска числа без пары
  }

  printf("Число без пары: %d\n", result);

  return 0;
}
