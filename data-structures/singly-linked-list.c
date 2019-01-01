// singly-linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *allocateNode(void);
void printList(struct Node *n);
void prependNode(struct Node *head, struct Node *n);

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

  // print initial list
  printf("Initial List\n");
  printList(head);

  // create new node to be prepended
  struct Node *fourth = NULL;

  fourth = allocateNode();
  fourth->data = 4;

  prependNode(head, fourth);
  
  printf("List with prepended node\n");
  printList(fourth);

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

// prepend node
void prependNode(struct Node *head, struct Node *n) {
  n->next = head;
}

// TODO: append node

// TODO: insert node at location

// TODO: remove node
