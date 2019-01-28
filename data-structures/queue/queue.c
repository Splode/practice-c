// queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "queue.h"

#define CAPACITY 10

int main()
{
  struct Queue *queue = createQueue(10);

  // queue is empty
  printf("Queue is empty: %d\n", isEmpty(queue));

  // queue items and print queue
  for (size_t i = 0; i < CAPACITY; i++)
  {
    enqueue(queue, i + 1);
    printf("%2zd  =>  ", i + 1);
    print(queue);
    putchar('\n');
  }

  // queue is full, so this item will not be added
  enqueue(queue, 11);

  // queue is NOT empty
  printf("Queue is empty: %d\n", isEmpty(queue));

  // dequeue all items and print queue
  for (size_t i = 0; i < CAPACITY; i++)
  {
    print(queue);
    printf("  =>  %2d", dequeue(queue));
    putchar('\n');
  }

  // queue is empty, so a limit-value is returned
  dequeue(queue);

  return 0;
}

struct Queue *createQueue(unsigned int capacity)
{
  struct Queue *queue;
  queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->length = 0;
  queue->rear = capacity - 1;
  queue->arr = (int *)malloc(queue->capacity * sizeof(int));
  return queue;
}

void enqueue(struct Queue *queue, int item)
{
  if (isFull(queue))
  {
    return;
  }

  queue->length++;
  // increment rear index until capacity, then reset to zero
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->arr[queue->rear] = item;
}

int dequeue(struct Queue *queue)
{
  if (isEmpty(queue))
  {
    return INT_MIN;
  }

  queue->length--;
  int item = front(queue);
  // increment front index until capacity, then reset to zero
  queue->front = (queue->front + 1) % queue->capacity;
  return item;
}

int front(struct Queue *queue)
{
  return queue->arr[queue->front];
}

int rear(struct Queue *queue)
{
  return queue->arr[queue->rear];
}

int isFull(struct Queue *queue)
{
  return queue->length == queue->capacity;
}

int isEmpty(struct Queue *queue)
{
  return queue->length == 0;
}

void print(struct Queue *queue)
{
  for (size_t i = queue->front; i <= queue->rear; i++)
  {
    printf("%d ", queue->arr[i]);
  }
}
