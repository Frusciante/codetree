#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    struct node* next;
    struct node* prev;
    int data;
} NODE;

typedef struct deque
{
    struct node* head;
    struct node* tail;
    int size;
} DEQUE;

int push_front(DEQUE* deque, int data)
{
    if (!deque)
    {
        return 1;
    }

    NODE* new_node = (NODE*)calloc(1, sizeof(NODE));
    if (!new_node)
    {
        return 1;
    }
    new_node->data = data;

    if (!deque->head)
    {
        deque->head = deque->tail = new_node;
    }
    else
    {
        deque->head->prev = new_node;
        new_node->next = deque->head;
        deque->head = new_node;
    }

    ++deque->size;

    return 0;
}

int push_back(DEQUE* deque, int data)
{
    if (!deque)
    {
        return 1;
    }

    NODE* new_node = (NODE*)calloc(1, sizeof(NODE));
    if (!new_node)
    {
        return 1;
    }
    new_node->data = data;

    if (!deque->head)
    {
        deque->head = deque->tail = new_node;
    }
    else
    {
        deque->tail->next = new_node;
        new_node->prev = deque->tail;
        deque->tail = new_node;
    }

    ++deque->size;

    return 0;
}

int pop_front(DEQUE* deque, int* output)
{
    if (!deque)
    {
        return 1;
    }

    if (!deque->head)
    {
        return 1;
    }

    *output = deque->head->data;
    NODE* temp = deque->head;
    deque->head = deque->head->next;

    if (deque->head)
    {
        deque->head->prev = NULL;
    }

    free(temp);

    --deque->size;

    if (!deque->size)
    {
        deque->head = deque->tail = NULL;
    }

    return 0;
}

int pop_back(DEQUE* deque, int* output)
{
    if (!deque)
    {
        return 1;
    }

    if (!deque->tail)
    {
        return 1;
    }

    *output = deque->tail->data;
    NODE* temp = deque->tail;
    deque->tail = deque->tail->prev;

    if (deque->tail)
    {
        deque->tail->next = NULL;
    }

    free(temp);

    --deque->size;

    if (!deque->size)
    {
        deque->head = deque->tail = NULL;
    }

    return 0;
}

int get_size(DEQUE* deque)
{
    if (!deque)
    {
        return -1;
    }

    return deque->size;
}

int empty(DEQUE* deque)
{
    if (!deque)
    {
        return 0;
    }

    return (deque->size == 0);
}

int front(DEQUE* deque, int* output)
{
    if (!deque)
    {
        return 1;
    }

    if (!deque->head)
    {
        return 1;
    }

    *output = deque->head->data;

    return 0;
}

int back(DEQUE* deque, int* output)
{
    if (!deque)
    {
        return 1;
    }

    if (!deque->tail)
    {
        return 1;
    }

    *output = deque->tail->data;

    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    DEQUE deque = { 0, };
    int output;

    for (int i = 1; i <= n; i++)
    {
        push_back(&deque, i);
    }

    while (get_size(&deque) > 1)
    {
        pop_front(&deque, &output);
        pop_front(&deque, &output);
        push_back(&deque, output);
    }
    
    front(&deque, &output);
    printf("%d", output);

    return 0;
}