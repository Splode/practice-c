// bubble sort algorithm

#include <stdio.h>

#define ARR_LENGTH 10

int *bubbleSort(int array[], int length);
void printArray(int array[], int length);

int main() {
  int unsorted[ARR_LENGTH] = { 7, 10, 2, 5, 3, 1, 6, 4, 9, 8 };
  int *sorted;

  sorted = bubbleSort(unsorted, ARR_LENGTH);
  printArray(sorted, ARR_LENGTH);

  return 0;
}

int *bubbleSort(int array[], int length) {
  int isSorted = 0;

  // reduce initial length to keep iterator in bounds
  length--;

  while(!isSorted) { 
    isSorted = 1;
    for (int i = 0; i < length; i++) {
      if (array[i] > array[i + 1]) {
        isSorted = 0;
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }

    // reduce length to keep last sorted item from being evaluated
    length--;
  }
  
  return array;
}

void printArray(int array[], int length) {
  for (int i = 0; i < length; i++) {
    printf("[%d]: %2d\n", i, array[i]);
  }
}
