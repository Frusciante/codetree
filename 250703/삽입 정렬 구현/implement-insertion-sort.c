#include <stdio.h>

int n;
int arr[100];

void insertion_sort(int* arr, int arr_size)
{
    for (int i = 1; i < arr_size; i++)
    {
        int j = i - 1;
        int key = arr[i];
        for (; j > -1 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}