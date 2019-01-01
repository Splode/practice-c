// singly-linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *allocateNode(void);
void printList(struct Node *n);

int main() {
  struct Node *head = NULL;
  struct Node *second = NULL;
  struct Node *third = NULL;

  head = allocateNode();
  second = allocateNode();
  third = allocateNode();
  
  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  printList(head);

  return 0;
}

// allocate memory for node struct
struct Node *allocateNode(void) {
  struct Node *n;

  n = (struct Node *)malloc(sizeof(struct Node));
  
  if (n == NULL) {
    perror("Unable to allocate structure");
    exit(1);
  }

  return n;
};

// traverse and log list starting at head
void printList(struct Node *n) {
  while (n != NULL) {
    printf("Data: %d\n", n->data);
    n = n->next;
  }
}
