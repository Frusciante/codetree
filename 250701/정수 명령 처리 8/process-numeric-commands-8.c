#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char command[20];

enum
{
    PUSH_FRONT, PUSH_BACK, POP_FRONT, POP_BACK, SIZE, EMPTY, FRONT, BACK
};

typedef struct node
{
    struct node* next;
    struct node* prev;
    int data;
} NODE;

typedef struct
{
    NODE* head;
    NODE* tail;
    int size;
} LIST;

int push_front(LIST* list, int num)
{
    if (list == NULL)
    {
        return 1;
    }

    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    if (!new_node)
    {
        return 1;
    }

    new_node->data = num;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (list->head)
    {
        list->head->prev = new_node;
        new_node->next = list->head;
    }
  
    list->head = new_node;

    if (!list->tail)
    {
        list->tail = new_node;
    }

    list->size++;

    return 0;
}

int push_back(LIST* list, int num)
{
    if (list == NULL)
    {
        return 1;
    }

    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    if (!new_node)
    {
        return 1;
    }

    new_node->data = num;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (list->tail)
    {
        list->tail->next = new_node;
        new_node->prev = list->tail;
    }

    list->tail = new_node;

    if (!list->head)
    {
        list->head = new_node;
    }

    list->size++;

    return 0;
}

int pop_front(LIST* list)
{
    if (list->head == NULL || list->tail == NULL || list->size == 0)
    {
        return -1;
    }
    
    int return_val = list->head->data;
    NODE* temp = list->head;
    list->head = list->head->next;

    free((void*)temp);

    list->size--;

    if (list->size == 0)
    {
        list->tail = NULL;
        list->head = NULL;
    }

    return return_val;
}

int pop_back(LIST* list)
{
    if (list->head == NULL || list->tail == NULL || list->size == 0)
    {
        return -1;
    }

    int return_val = list->tail->data;
    NODE* temp = list->tail;
    list->tail = list->tail->prev;

    free((void*)temp);

    list->size--;

    if (list->size == 0)
    {
        list->tail = NULL;
        list->head = NULL;
    }

    return return_val;
}

int get_command(void)
{
    scanf("%s", command);
    if (!strcmp(command, "push_front"))
    {
        return PUSH_FRONT;
    }
    if (!strcmp(command, "push_back"))
    {
        return PUSH_BACK;
    }
    if (!strcmp(command, "pop_front"))
    {
        return POP_FRONT;
    }
    if (!strcmp(command, "pop_back"))
    {
        return POP_BACK;
    }
    if (!strcmp(command, "size"))
    {
        return SIZE;
    }
    if (!strcmp(command, "empty"))
    {
        return EMPTY;
    }
    if (!strcmp(command, "front"))
    {
        return FRONT;
    }
    if (!strcmp(command, "back"))
    {
        return BACK;
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    LIST list = { NULL, NULL, 0 };
    int num_data;
    int num_command = -1;
        for (int i = 0; i < n; i++)
        {
            num_command = get_command();
            switch (num_command)
            {
            case PUSH_FRONT:
            case PUSH_BACK:
                scanf("%d", &num_data);
                (num_command == PUSH_FRONT) ? push_front(&list, num_data) : push_back(&list, num_data);
                break;
            case POP_FRONT:
            case POP_BACK:
                printf("%d\n", ((num_command == POP_FRONT) ? pop_front(&list) : pop_back(&list)));
                break;
            case SIZE:
                printf("%d\n", list.size);
                break;
            case EMPTY:
                printf("%d\n", ((list.size == 0) ? 1 : 0));
                break;
            case FRONT:
                if (list.head != NULL)
                {
                    printf("%d\n", list.head->data);
                }
                break;
            case BACK:
                if (list.tail != NULL)
                {
                    printf("%d\n", list.tail->data);
                }
                break;
            }
        }

    return 0;
}