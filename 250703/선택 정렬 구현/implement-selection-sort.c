#include <stdio.h>

int n;
int arr[100];

void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void selection_sort(int* arr, int arr_size)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n - 1; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }   
        }
        
        if (min != i)
        {
            swap(&arr[i], &arr[min]);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    selection_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}