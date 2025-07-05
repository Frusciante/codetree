#include <stdio.h>

void swap(int* n1, int* n2)
{
    if (!(n1 && n2))
    {
        return;
    }
    
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int get_pivot_idx(int* arr, int low, int high)
{
    if (!arr)
    {
        return -1;
    }

    int result_idx;
    int mid = high + low / 2;
    if (arr[low] > arr[high])
    {
        result_idx = (arr[low] < arr[mid] ? low : mid);
    }
    else
    {
        result_idx = (arr[high] < arr[mid] ? high : mid);
    }

    return result_idx;
}

int partition(int* arr, int low, int high, int* pos)
{
    if (!arr)
    {
        return 1;
    }

    int pivot_idx = get_pivot_idx(arr, low, high);
    int pivot = arr[pivot_idx];
    swap(&arr[high], &arr[pivot_idx]);

    int i = low - 1;
    int j = low;

    for (; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    *pos = i + 1;

    return 0;
}

int quick_sort(int* arr, int low, int high)
{
    if (low >= high)
    {
        return 0;
    }

    if (!arr)
    {
        return 1;
    }

    int pos;
    if (partition(arr, low, high, &pos) != -0)
    {
        return 1;
    }

    quick_sort(arr, low, pos - 1);
    quick_sort(arr, pos + 1, high);

    return 0;
}

int main() 
{
    int n;
    int arr[100000];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}