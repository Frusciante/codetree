#include <stdio.h>
#include <stdlib.h>

int n;
int blocks[10000];

int main() {
    int avg;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
        sum += blocks[i];
    }
    // Please write your code here.

    avg = sum / n;
    int net_movement = 0;

    for (int i = 0; i < n; i++)
    {
        net_movement += abs(blocks[i] - avg);
    }

    printf("%d", net_movement / 2);

    return 0;
}   