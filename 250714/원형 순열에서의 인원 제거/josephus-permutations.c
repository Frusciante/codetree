#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    struct node* next;
    int data;
} NODE;

typedef struct circular_queue
{
    NODE* head;
    NODE* tail;
    int size;
} C_QUEUE;

int push(C_QUEUE* queue, int data)
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
    new_node->data = data;

    if (!queue->head)
    {
        queue->head = queue->tail = new_node;
    }
    new_node->next = queue->head;
    queue->tail->next = new_node;
    queue->tail = new_node;
    ++queue->size;    

    return 0;
}

int pop(C_QUEUE* queue, int* output)
{
    if (!(queue && output && queue->size))
    {
        return 1;
    }

    NODE* temp = queue->head;
    *output = temp->data;
    queue->head = queue->head->next;
    queue->tail->next = queue->head;
    --queue->size;

    if (!queue->size)
    {
        queue->head = queue->tail = NULL;
    }
    free(temp);

    return 0;
}

int main() 
{
    int n, k;
    int output;
    scanf("%d %d", &n, &k); 

    C_QUEUE queue = { NULL, NULL, 0 };

    for (int i = 1; i <= n; i++)
    {
        push(&queue, i);
    }

    while (queue.size)
    {
        for (int i = 0; i < k - 1; i++)
        {
            queue.head = queue.head->next;
            queue.tail = queue.tail->next;
        }
        pop(&queue, &output);
        printf("%d ", output);
    }
    
    return 0;
}