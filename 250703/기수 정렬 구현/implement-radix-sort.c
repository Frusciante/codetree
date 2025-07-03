#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#define MAX_N 100000
#define MAX_DIGIT 5

int n;
int arr[MAX_N];

typedef struct node
{
    struct node* next;
    int data;
} NODE;

typedef struct int_linked_list
{
    NODE* head;
    NODE* tail;
} INT_LINKED_LIST;

int push_back(INT_LINKED_LIST* list, int data)
{
    if (!list) { return 1; }

    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    if (!new_node) { return 1; }

    new_node->next = NULL;
    new_node->data = data;

    if (list->tail) { list->tail->next = new_node; }
    list->tail = new_node;

    if (!list->head) { list->head = new_node; }

    return 0;
}

int pop_front(INT_LINKED_LIST* list, int* data)
{
    if (!(list && data)) { return 1; }
    if (!list->head) { return 1; }

    *data = list->head->data;

    NODE* temp = list->head;
    list->head = list->head->next;
    free(temp);

    if (!list->head) { list->tail = NULL; }

    return 0;
}

int get_idx(int num, int digit)
{
    return num % (int)pow(10.0, digit + 1.0) / (int)pow(10.0, (double)digit);
}

void radix_sort(int* arr, int arr_size)
{
    INT_LINKED_LIST list[10] = { 0, };

    for (int i = 0; i <= MAX_DIGIT; ++i)
    {
        for (int j = 0; j < arr_size; ++j)
        {
            push_back(&list[get_idx(arr[j], i)], arr[j]);
        }

        int cnt = 0;
        for (int j = 0; j < 10; ++j)
        {
            int pop_front_result;
            while (pop_front(&list[j], &pop_front_result) == 0)
            {
                arr[cnt] = pop_front_result;
                ++cnt;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) { scanf("%d", &arr[i]); }

    // Please write your code here.
    radix_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}