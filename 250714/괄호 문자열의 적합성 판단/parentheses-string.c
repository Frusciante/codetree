#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct stack
{
    char* container;
    int idx;
    int capacity;
    int (*push)(struct stack* stack, char data);
    int (*pop)(struct stack* stack, char* output);
    int (*size)(struct stack* stack);
    int (*empty)(struct stack* stack);
    int (*top)(struct stack* stack, char* output);
} STACK;

int push(STACK* stack, char data)
{
    if (!stack)
    {
        return 1;
    }

    if (stack->container == NULL)
    {
        stack->container = (char*)malloc(sizeof(char) * stack->capacity);
    }
    if (stack->capacity == stack->idx)
    {
        char* new_container = (char*)realloc(stack->container, sizeof(char) * stack->capacity * 2);
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

int pop(STACK* stack, char* output)
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

int top(STACK* stack, char* output)
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

int check_parentheses(char* str, int str_len)
{
    STACK stack = {NULL, 0, 10, push, pop, size, empty, top};
    char output;
    for (int i = 0; i < str_len; i++)
    {
        switch (str[i])
        {
        case '(':
            stack.push(&stack, '(');
            break;
        case ')':
            if (stack.pop(&stack, &output) == 1 || output != '(')
            {
                return 0;
            }
            break;
        }
    }

    if (!stack.empty(&stack))
    {
        return 0;
    }

    return 1;
}

int main() 
{
    char str[51] = { 0, };
    scanf("%s", str);

    printf("%s", ((check_parentheses(str, strlen(str))) ? "Yes" : "No"));

    return 0;
}