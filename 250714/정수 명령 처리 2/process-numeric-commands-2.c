#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct node
{
    struct node* next;
    int data;
} NODE;

typedef struct queue
{
    NODE* head;
    NODE* tail;
    int size;
    int (*push)(struct queue* queue, int data);
    int (*pop)(struct queue* queue, int* output);
    int (*get_size)(struct queue* queue);
    int (*empty)(struct queue* queue);
    int (*front)(struct queue* queue, int* output);
} QUEUE;

int push(QUEUE* queue, int data)
{
    if (!queue)
    {
        return 1;
    }

    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    if (!new_node)
    {
        return 1;
    }
    new_node->next = NULL;
    new_node->data = data;

    if (!queue->head)
    {
        queue->tail = queue->head = new_node;
    }
    else
    {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }

    ++queue->size;

    return 0;
}

int pop(QUEUE* queue, int* output)
{
    if (!queue || !queue->head)
    {
        return 1;
    }

    NODE* temp = queue->head;
    queue->head = queue->head->next;
    *output = temp->data;

    if (!queue->head)
    {
        queue->tail = NULL;
    }

    free(temp);
    --queue->size;

    return 0;
}

int front(QUEUE* queue, int* output)
{
    if (!queue || !queue->head)
    {
        return 1;
    }

    *output = queue->head->data;

    return 0;
}

int get_size(QUEUE* queue)
{
    if (!queue)
    {
        return -1;
    }
    return queue->size;
}

int empty(QUEUE* queue)
{
    if (!queue)
    {
        return 0;
    }
    return (queue->size) ? 0 : 1;
}

int main()
{
    int n;
    char command[10];
    int push_val;
    int output;
    scanf("%d", &n);
    QUEUE queue = { NULL, NULL, 0, push, pop, get_size, empty, front };

    for (int i = 0; i < n; i++)
    {
        scanf("%s", command);
        if (strncmp(command, "push", 10) == 0)
        {
            scanf("%d", &push_val);
            queue.push(&queue, push_val);
        }
        else if (strncmp(command, "pop", 10) == 0)
        {
            if (queue.pop(&queue, &output) == 0)
            {
                printf("%d\n", output);
            }
        }
        else if (strncmp(command, "size", 10) == 0)
        {
            printf("%d\n", queue.get_size(&queue));
        }
        else if (strncmp(command, "empty", 10) == 0)
        {
            printf("%d\n", queue.empty(&queue));
        }
        else if (strncmp(command, "front", 10) == 0)
        {
            if (queue.front(&queue, &output) == 0)
            {
                printf("%d\n", output);
            }
        }
    }

    return 0;
}