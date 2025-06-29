#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char command[20];
int num;

typedef struct
{
    int size;
    int* container;
} ARRAY;

int push_back(ARRAY* arr, int n)
{
    if (arr->size == 0)
    {
        (arr->container)[0] = n;
    }
    else
    {
        int* new_container = (int*)realloc(arr->container, (arr->size) + 1);
        if (new_container == NULL)
        {
            return 1;
        }
        arr->container = new_container;
    }

    (arr->container)[arr->size] = n;
    arr->size++;

    return 0;
}

int pop_back(ARRAY* arr)
{
    if (arr->size > 1)
    {
        int* new_container = (int*)realloc(arr->container, (arr->size) - 1);
        if (new_container == NULL)
        {
            return 1;
        }
        arr->container = new_container;
    }
    if (arr->size != 0)
    {
        arr->size--;
    }
}

int get(ARRAY* arr, int idx)
{
    if (idx > arr->size - 1)
    {
        return -1;
    }

    return (arr->container)[idx];
}

int main() 
{
    scanf("%d", &n);

    ARRAY arr;
    arr.container = (int*)malloc(sizeof(int) * 1);
    arr.size = 0;
    
    if (arr.container == NULL)
    {
        return 1;
    }

    for (int i = 0; i < n; i++) 
    {
        scanf("%s", command);
        if (strcmp(command, "push_back") == 0) 
        {
            scanf("%d", &num);
            push_back(&arr, num);

        } 
        else if (strcmp(command, "get") == 0) 
        {
            scanf("%d", &num);
            printf("%d\n", get(&arr, num - 1));
        } 
        else if (strcmp(command, "pop_back") == 0) 
        {
            pop_back(&arr);
        } 
        else if (strcmp(command, "size") == 0) 
        {
            printf("%d\n", arr.size);
        }
    }
    
    // Please write your code here.
    
    return 0;
}