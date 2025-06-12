#include <stdio.h>

int main() {
    int n;
    int blocks[101];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &blocks[i]);

    // Please write your code here.
    int max;
    for (int i = 0; i < n; i++)
    {
        if (blocks[i] > i)
        {
            max = i;
        }
    }

    printf("%d", max + 1);

    return 0;
}