#include <stdio.h>
#include <stdlib.h>
#define SZ_ARR 15

int arr[SZ_ARR];

int asc(const void* n1, const void* n2)
{
    if (*(int*)n1 > *(int*)n2) { return 1; }
    if (*(int*)n1 < *(int*)n2) { return -1; }
    return 0;
}

int main(void) {
    int i;
    for(i = 0; i < SZ_ARR; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, SZ_ARR, sizeof(int), asc);

    // Please write your code here.
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    int d = arr[SZ_ARR - 1] - a - b - c;

    printf("%d %d %d %d", a, b, c, d);

    return 0;
}