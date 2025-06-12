#include <stdio.h>

int main() {
    int n;
    int blocks[101];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &blocks[i]);

    // Please write your code here.
    int max = -1;
    for (int i = 0; i < n; ++i)
    {
        if (blocks[i] > i + 1)
        {
            max = i;
        }
    }

    for (int i = max + 1; i < n; ++i)
    {
        int j;
        for (j = i + 1; j < n && j > 1; ++j)
        {
            if (blocks[j - 1] > blocks[j])
            {
                ++max;
            }
        }
    }

    printf("%d", max + 1);

    return 0;
}