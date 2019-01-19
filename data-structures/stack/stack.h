#ifndef STACK_H
#define STACK_H

struct Stack
{
  int top;
  unsigned int capacity;
  int *arr;
};

/**
 * Creates and returns a new stack.
 * 
 * @param unsigned int - The capacity of the stack.
 * @returns stack - The newly created, empty stack.
 */
struct Stack *createStack(unsigned int capacity);

/**
 * Add an integer item onto the given stack.
 * 
 * @param struct Stack *stack - A pointer reference to a stack.
 * @param int item - The integer item to be added.
 */
void push(struct Stack *stack, int item);

/**
 * Removes the top-most item from a stack and returns it.
 * 
 * @param struct Stack *stack - A pointer reference to a stack.
 * @returns int - The removed item.
 */
int pop(struct Stack *stack);

/**
 * Returns the top-most item of the stack.
 * 
 * @param struct Stack *stack - A pointer reference to a stack.
 * @returns int - The top-most item in the stack.
 */
int peek(struct Stack *stack);

/**
 * Returns the number of items in a stack.
 * 
 * @param struct Stack *stack - A pointer reference to a stack.
 * @returns int - The number of items in the stack.
 */
int length(struct Stack *stack);

/**
 * Returns true if there are zero items in the stack.
 * 
 * @param struct Stack *stack - A pointer reference to a stack.
 * @returns int True if stack has zero items, false otherwise.
 */
int isEmpty(struct Stack *stack);

/**
 * Returns true if the number of items in the stack is equal to its capacity.
 * 
 * @param struct Stack *stack - A pointer reference to a stack.
 * @returns int True if number of items in stack equals its capacity.
 */
int isFull(struct Stack *stack);

#endif
