// reverse the contents of an array
#include <stdio.h>

#include "array-reversal.h"

#define SIZE 7

int main() {
  int numArray[SIZE] = { 1, 2, 3, 4, 5, 6, 7 };

  printf("Original array\n");
  printArray(numArray, SIZE);

  printf("Reversed array\n");
  reverseArray(numArray, SIZE);
  printArray(numArray, SIZE);

  return 0;
}

void printArray(int arr[], int size) {
  for(short i = 0; i < size; i++) {
    printf("[%d]:  %d\n", i, arr[i]);
  }
}

// TODO: make this accept a void pointer
void *reverseArray(int arr[], int size) {
  int start = 0;
  int end = size - 1;
  while (start < end) {
    int temp = arr[end];
    arr[end] = arr[start];
    arr[start] = temp;
    start++;
    end--;
  }
}
