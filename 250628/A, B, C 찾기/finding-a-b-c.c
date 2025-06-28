#include <stdio.h>
#include <stdlib.h>
#define NUM_ARR 7

int arr[NUM_ARR];

int main(void) {
    int i;
    for (i = 0; i < NUM_ARR; i++) {
        scanf("%d", &arr[i]);
    }
    // Please write your code here.

    int a, b, c;

    a = arr[0];
    b = arr[3] - a;
    c = arr[4] - b;

    printf("%d %d %d", a, b, c);

    return 0;
}