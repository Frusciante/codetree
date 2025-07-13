#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct stack
{
    int* container;
    int idx;
    int capacity;
    int (*push)(struct stack* stack, int data);
    int (*pop)(struct stack* stack, int* output);
    int (*size)(struct stack* stack);
    int (*empty)(struct stack* stack);
    int (*top)(struct stack* stack, int* output);
} STACK;

int push(STACK* stack, int data)
{
    if (!stack)
    {
        return 1;
    }

    if (stack->container == NULL)
    {
        stack->container = (int*)malloc(sizeof(int) * stack->capacity);
    }
    if (stack->capacity == stack->idx)
    {
        int* new_container = (int*)realloc(stack->container, sizeof(int) * stack->capacity * 2);
        if (!new_container)
        {
            return 1;
        }
        stack->container = new_container;
        stack->capacity *= 2;
    }

    (stack->container)[stack->idx] = data;
    ++stack->idx;

    return 0;
}

int pop(STACK* stack, int* output)
{
    if (!(stack && output))
    {
        return 1;
    }
    if ((stack->idx == 0) || !stack->container)
    {
        return 1;
    }

    *output = (stack->container)[stack->idx - 1];
    --stack->idx;

    return 0;
}

int size(STACK* stack)
{
    if (!stack)
    {
        return -1;
    }

    return stack->idx;
}

int empty(STACK* stack)
{
    if (!stack)
    {
        return 0;
    }

    return (stack->idx) ? 0 : 1;
}

int top(STACK* stack, int* output)
{
    if (!(stack && output))
    {
        return 1;
    }
    if (stack->idx == 0 || !stack->container)
    {
        return 1;
    }

    *output = (stack->container)[stack->idx - 1];

    return 0;
}

int main() 
{
    int n;
    char command[10];
    int value;
    int output;
    STACK stack = {NULL, 0, 10, push, pop, size, empty, top};

    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", command);
        if (strcmp(command, "push") == 0) 
        {
            scanf("%d", &value);
            stack.push(&stack, value);
        }
        else if (strcmp(command, "pop") == 0) 
        {
            stack.pop(&stack, &output);
            printf("%d\n", output);
        }
        else if (strcmp(command, "size") == 0) 
        {
            printf("%d\n", stack.size(&stack));
        }
        else if (strcmp(command, "empty") == 0) 
        {
            printf("%d\n", stack.empty(&stack));
        }
        else if (strcmp(command, "top") == 0) 
        {
            stack.top(&stack, &output);
            printf("%d\n", output);
        }
        // Please write your code here.
    }

    free(stack.container);

    return 0;
}