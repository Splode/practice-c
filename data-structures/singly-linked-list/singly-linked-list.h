#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

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
int getListLength(struct Node *head);

#endif