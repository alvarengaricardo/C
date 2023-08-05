#include <stdio.h>

void insertion_sort(int *array, int n) {
  int i, j, key;

  for (i = 1; i < n; i++) {
    key = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = key;
  }
}

int main() {
  printf("Insertion Sort\n");
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  
  int n = sizeof(array) / sizeof(array[0]);

  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n ");

  insertion_sort(array, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}
