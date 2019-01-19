#ifndef QUEUE_H
#define QUEUE_H

struct Queue
{
  int front, rear, length;
  unsigned int capacity;
  int *arr;
};

/**
 * Creates and returns a new queue.
 * 
 * @param unsigned int - The capacity of the queue.
 * @returns queue - The newly created, empty queue.
 */
struct Queue *createQueue(unsigned int capacity);

/**
 * Adds an integer item to  the front of the given queue.
 *
 * @param struct Queue *queue - A pointer reference to a stack.
 * @param int item - The integer item to be added.
 */
void enqueue(struct Queue *queue, int item);

/**
 * Removes and returns the first item from a given queue.
 *
 * @param struct Queue *queue - A pointer reference to a queue.
 * @returns int item - The removed item.
 */
int dequeue(struct Queue *queue);

/**
 * Get the first item of a given queue.
 *
 * @returns int item - The first item in the queue.
 */
int front(struct Queue *queue);

/**
 * Get the last item of a given queue.
 *
 * @returns int item - The last item in the queue.
 */
int rear(struct Queue *queue);

/**
 * Returns true if the queue's capacity has been reached.
 *
 * @param struct Queue *queue - A pointer reference to a queue.
 * @returns int - True if queue is full, false otherwise.
 */
int isFull(struct Queue *queue);

/**
 * Returns true if there are zero items in the queue.
 *
 * @param struct Queue *queue - A pointer reference to a queue.
 * @returns int - True if queue has zero items, false otherwise.
 */
int isEmpty(struct Queue *queue);

/**
 * Prints the items in the given queue to the console.
 */
void print(struct Queue *queue);

#endif