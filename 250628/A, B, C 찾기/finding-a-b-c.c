#include <stdio.h>
#include <stdlib.h>
#define NUM_ARR 7

int arr[NUM_ARR];

int asc(const void* first, const void* second)
{
    if (*(int*)first > *(int*)second) { return 1; }
    if (*(int*)first <*(int*)second) { return -1; }
    return 0;
}

int main(void) {
    int i;
    for (i = 0; i < NUM_ARR; i++) {
        scanf("%d", &arr[i]);
    }
    // Please write your code here.

    int a, b, c;

    qsort(arr, NUM_ARR, sizeof(int), asc);

    a = arr[0];
    b = arr[1];
    c = arr[6] - b - a;

    printf("%d %d %d", a, b, c);

    return 0;
}