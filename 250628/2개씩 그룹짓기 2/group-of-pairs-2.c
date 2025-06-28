#include <stdio.h>
#include <stdlib.h>

int arr[200001];

int desc(const void* first, const void* second)
{
    if (*(int*)first > *(int*)second) { return -1; }
    if (*(int*)first < *(int*)second) { return 1; }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &arr[i]);
    }
    // Please write your code here.

    qsort(arr, n * 2, sizeof(int), desc);

    int min = arr[0] - arr[n];

    for (int i = 1; i < n; ++i)
    {
        int val = arr[i] - arr[i + n];
        if (val < min)
        {
            min = val;
        }
    }

    printf("%d", min);

    return 0;
}