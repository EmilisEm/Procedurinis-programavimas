#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Stacks
{
    int size;
    int *stack;
} Stack;

void initStack(Stack *stack);

void printStack(Stack *stack);

int getStackSize(Stack *Stack);

void push(Stack *stack, int value);

int top(Stack *stack);

int pop(Stack *stack);

void destroyStack(Stack *stack);

int main()
{
    Stack stack;

    initStack(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    pop(&stack);
    push(&stack, 4);
    push(&stack, 5);
    printStack(&stack);
    destroyStack(&stack);

    return 0;
}

void initStack(Stack *stack)
{
    (*stack).size = 0;
    (*stack).stack = malloc((*stack).size * sizeof(int));
}

void printStack(Stack *stack)
{
    int i;

    for (i = 0; i < (*stack).size; ++i)
    {
        printf("%d ", (*stack).stack[i]);
    }

    if (i == 0)
    {
        printf("0");
    }
}

int getStackSize(Stack *stack)
{
    return (*stack).size;
}

void push(Stack *stack, int value)
{
    (*stack).size += 1;
    (*stack).stack = realloc((*stack).stack, (*stack).size * sizeof(int));

    (*stack).stack[(*stack).size - 1] = value;
}

int top(Stack *stack)
{
    return (*stack).stack[(*stack).size - 1];
}

int pop(Stack *stack)
{
    int temp = top(stack);

    (*stack).size -= 1;
    (*stack).stack = realloc((*stack).stack, (*stack).size * sizeof(int));

    return temp;
}

void destroyStack(Stack *stack)
{
    free((*stack).stack);
    (*stack).size = 0;
}
