// singly-linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *createNode(int data);
void printList(struct Node *n);
void prependNode(struct Node *head, struct Node *n);
void appendNode(struct Node *listNode, struct Node *n);
void insertNode(struct Node *listNode, struct Node *n);
void removeNode(struct Node *head, struct Node *n);

int main() {
  struct Node *first = NULL;
  struct Node *second = NULL;
  struct Node *third = NULL;

  first = createNode(1);
  second = createNode(2);
  third = createNode(3);
  
  // create head
  first->next = NULL;
  appendNode(first, second);
  appendNode(first, third);

  // print initial list
  printf("Initial List\n");
  printList(first);

  // create new node to be prepended
  struct Node *fourth = NULL;
  fourth = createNode(4);

  prependNode(first, fourth);
  
  putchar('\n');
  printf("List with prepended node\n");
  printList(fourth);

  // create new node to be appended
  struct Node *fifth = NULL;
  fifth = createNode(5);

  appendNode(fourth, fifth);

  putchar('\n');
  printf("List with appended node\n");
  printList(fourth);

  // create new node to be inserted
  struct Node *sixth = NULL;
  sixth = createNode(6);

  insertNode(second, sixth);

  putchar('\n');
  printf("List with inserted node\n");
  printList(fourth);

  // remove node
  removeNode(fourth, second);
  putchar('\n');
  printf("List with node removed\n");
  printList(fourth);

  // remove tail
  removeNode(fourth, fifth);
  putchar('\n');
  printf("List with tail removed\n");
  printList(fourth);

  // remove head
  removeNode(fourth, fourth);
  putchar('\n');
  printf("List with head removed\n");
  printList(first);

  return 0;
}

// allocate memory for node struct
struct Node *createNode(int data) {
  static struct Node *n;

  n = (struct Node *)malloc(sizeof(struct Node));
  
  if (n == NULL) {
    perror("Unable to allocate structure");
    exit(1);
  }

  n->data = data;

  return n;
};

// traverse and log list starting at given node
void printList(struct Node *n) {
  while (n) {
    printf("Data: %d\n", n->data);
    n = n->next;
  }
}

// prepend node given existing head and new node
void prependNode(struct Node *head, struct Node *n) {
  n->next = head;
}

// append node given an existing linked node and new node
void appendNode(struct Node *listNode, struct Node *n) {
  // immediately set new tail
  n->next = NULL;
  // traverse from given node until tail is found
  while (listNode->next) {
    listNode = listNode->next;
  }
  // link previous tail to new tail
  listNode->next = n;
}

// insert node after given location
void insertNode(struct Node *listNode, struct Node *n) {
  // link new node to next node
  n->next = listNode->next;
  listNode->next = n;
}

// remove given node
void removeNode(struct Node *head, struct Node *n) {
  // immediately remove head if given
  if (head == n) {
    free(head);
    return;
  }
  
  // set current node to head
  struct Node *current = head;

  // traverse list
  while (current) {
    if (current->next == n) {      
      current->next = n->next;
      break;
    }
    current = current->next;
  }

  // free dynamically allocated memory of removed node
  free(n);
}
