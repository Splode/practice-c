// stack using array
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define CAPACITY 10

int main()
{
  struct Stack *stack = createStack(10);
  int items[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // initial stack is empty, with a lenght of 0
  printf("Stack is empty: %d\t", isEmpty(stack));
  printf("Stack length: %d\n", length(stack));

  // push items onto stack and print
  for (size_t i = 0; i <= CAPACITY + 1; i++)
  {
    push(stack, i);
    printf("Pushing %2d onto stack.\t", i);
    printf("Stack is full: %d\t", isFull(stack));
    printf("Top item of stack: %2d\n", peek(stack));
  }

  // stack should not be empty and length should be 10
  printf("Stack is empty: %d\t", isEmpty(stack));
  printf("Stack length: %d\n", length(stack));

  // remove items from stack and print
  for (size_t i = 0; i < CAPACITY; i++)
  {
    printf("Popping %d from the stack.\n", pop(stack));
  }

  // stack should now be empty and length should be 0
  printf("Stack is empty: %d\t", isEmpty(stack));
  printf("Stack length: %d\n", length(stack));

  return 0;
}

struct Stack *createStack(unsigned int capacity)
{
  struct Stack *stack;
  stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->arr = (int *)malloc(stack->capacity * sizeof(int));
  return stack;
}

void push(struct Stack *stack, int item)
{
  // only push items onto stack if capacity has not been reached
  if (!isFull(stack))
  {
    stack->top++;
    stack->arr[stack->top] = item;
  }
}

int pop(struct Stack *stack)
{
  // guard against popping from empty stack
  if (isEmpty(stack))
  {
    return INT_MIN;
  }
  int item = peek(stack);
  stack->top--;
  return item;
}

int peek(struct Stack *stack)
{
  return stack->arr[stack->top];
}

int length(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    return 0;
  }
  return stack->top;
}

int isEmpty(struct Stack *stack)
{
  return stack->top <= 0;
}

int isFull(struct Stack *stack)
{
  return stack->top == stack->capacity;
}
