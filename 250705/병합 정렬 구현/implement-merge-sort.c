#include <stdio.h>
#include <string.h>
#include <malloc.h>

int n;

int merge(int* arr, int low, int mid, int high)
{
    int* aux_arr1 = malloc(sizeof(arr) * (mid - low + 1));
    int* aux_arr2 = malloc(sizeof(arr) * (high - mid));

    if (!(aux_arr1 && aux_arr2))
    {
        return 1;
    }

    //printf("low : %d, mid : %d, high : %d\n", low, mid, high);

    memcpy(aux_arr1, arr + low, sizeof(arr) * (mid - low + 1));
    //printf("aux_arr1 : ");
    //for (int i = 0; i < mid - low + 1; i++)
    //{
    //    printf("%d ", aux_arr1[i]);
    //}
    //puts("");

    memcpy(aux_arr2, arr + (mid + 1), sizeof(arr) * (high - mid));
    //printf("aux_arr2 : ");
    //for (int i = 0; i < high - mid; i++)
    //{
    //    printf("%d ", aux_arr2[i]);
    //}
    //puts("");

    int i = 0;
    int j = 0;
    int k = low;

    char i_end_yet = 0;
    char j_end_yet = 0;

    while (i < mid - low + 1 && j < high - mid)
    {
        if (aux_arr1[i] > aux_arr2[j])
        {
            arr[k] = aux_arr2[j];
            j++;
        }
        else
        {
            arr[k] = aux_arr1[i];
            i++;
        }
        k++;
    }

    if (i < mid - low + 1)
    {
        for (; i < mid - low + 1; i++)
        {
            arr[k] = aux_arr1[i];
            k++;
        }
    }
    if (j < high - mid)
    {
        for (; j < high - mid; j++)
        {
            arr[k] = aux_arr2[j];
            k++;
        }
    }

    free(aux_arr1);
    free(aux_arr2);

    //for (int i = 0; i < n; i++)
    //{
    //    printf("%d ", arr[i]);
    //}
    //puts("");

    return 0;
}

int merge_sort(int* arr, int low, int high)
{
    int mid = (low + high - 1) / 2;

    if (low == high)
    {
        return 0;
    }

    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    if (merge(arr, low, mid, high) == 1)
    {
        return 1;
    }

    return 0;
}

int main()
{
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    if (!arr)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}