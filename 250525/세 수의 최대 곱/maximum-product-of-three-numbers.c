#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_N 100000

int n;
int arr[MAX_N];

int compare(const void* first, const void* second)
{
    if (abs(*(int*)first) > abs(*(int*)second)) { return -1; }
    else if (abs(*(int*)first) < abs(*(int*)second)) { return 1; }
    else { return 0; }
}

int get_max_num(int* arr, int arr_size)
{
    for (int i = 0; i < arr_size - 2; i++)
    {
        for (int j = i + 1; j < arr_size - 1; j++)
        {
            for (int k = j + 1; k < arr_size; k++)
            {
                if (arr[i] * arr[j] * arr[k] > 0)
                {
                    return arr[i] * arr[j] * arr[k];
                }
            }
        }
    }

    return arr[arr_size - 1] * arr[arr_size - 2] * arr[arr_size -3];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Please write your code here.

    qsort(arr, n, sizeof(int), compare);

    printf("%d", get_max_num(arr, n));

    return 0;
}