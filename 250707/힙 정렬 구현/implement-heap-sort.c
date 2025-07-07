#include <stdio.h>

int n;
int arr[100001];

void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int heapify(int* arr, int n, int i)
{
    if (!arr)
    {
        return 1;
    }

    int left = i * 2;
    int right = i * 2 + 1;
    int biggest = i;

    if (left <= n && arr[biggest] < arr[left])
    {
        biggest = left;
    }

    if (right <= n && arr[biggest] < arr[right])
    {
        biggest = right;
    }

    if (i != biggest)
    {
        swap(&arr[i], &arr[biggest]);
        heapify(arr, n, biggest);
    }

    return 0;
}

int heap_sort(int* arr, int n)
{
    if (!arr)
    {
        return 1;
    }

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n; i > 0; i--)
    {
        swap(&arr[i], &arr[1]);
        heapify(arr, i - 1, 1);
    }

    return 0;
}

int main(void) 
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    // Please write your code here.

    heap_sort(arr, n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}