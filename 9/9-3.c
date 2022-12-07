#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Points
{
    double x;
    double y;
} Point;

typedef struct Stacks
{
    int size;
    Point *stack;
} Stack;

void initStack(Stack *stack);

void printStack(Stack *stack);

int getStackSize(Stack *Stack);

void push(Stack *stack, Point value);

Point top(Stack *stack);

Point pop(Stack *stack);

void destroyStack(Stack *stack);

Point createPoint(double x, double y);

double getDistance(Point a);

int main()
{
    Stack stack;
    Point p1, p2, p3, p4, p5;

    p1 = createPoint(1, 1);
    p2 = createPoint(3, 4);
    p3 = createPoint(8, 6);
    p4 = createPoint(8, 6);
    p5 = createPoint(10, 10);

    initStack(&stack);
    push(&stack, p1);
    push(&stack, p2);
    push(&stack, p3);
    push(&stack, p4);
    push(&stack, p5);
    printStack(&stack);
    destroyStack(&stack);

    return 0;
}

void initStack(Stack *stack)
{
    (*stack).size = 0;
    (*stack).stack = malloc((*stack).size * sizeof(Point));
}

void printStack(Stack *stack)
{
    int i;

    for (i = 0; i < (*stack).size; ++i)
    {
        printf("%lf ", getDistance((*stack).stack[i]));
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

void push(Stack *stack, Point value)
{
    (*stack).size += 1;
    (*stack).stack = realloc((*stack).stack, (*stack).size * sizeof(Point));

    (*stack).stack[(*stack).size - 1] = value;
}

Point top(Stack *stack)
{
    return (*stack).stack[(*stack).size - 1];
}

Point pop(Stack *stack)
{
    Point temp = top(stack);

    (*stack).size -= 1;
    (*stack).stack = realloc((*stack).stack, (*stack).size * sizeof(Point));

    return temp;
}

void destroyStack(Stack *stack)
{
    free((*stack).stack);
    (*stack).size = 0;
}

Point createPoint(double x, double y)
{
    Point p;

    p.x = x;
    p.y = y;

    return p;
}

double getDistance(Point a)
{
    return sqrt(pow(a.x, 2) + pow(a.y, 2));
}