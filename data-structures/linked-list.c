// singly-linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// TODO: implement list traversal
//void printList(struct Node);

int main() {
  struct Node *head = NULL;
  struct Node *second = NULL;
  struct Node *third = NULL;

  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));
  
  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  printf("Head: %d\n", head->data);
  printf("Next: %d", head->next->data);

  return 0;
}
