#include <stdio.h>

int blocks[1000];

int main() {
    int n;
    scanf("%d", &n);

    int odd_cnt = 0;
    int even_cnt = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
        switch (blocks[i] % 2)
        {
            case 0:
                ++even_cnt;
                break;
            case 1:
                ++odd_cnt;
                break;
        }           
    }
    // Please write your code here.
    
    while (even_cnt < odd_cnt)
    {
        odd_cnt -= 2;
        ++even_cnt;
    }
    while (even_cnt > odd_cnt + 1)
    {
        --even_cnt;
    }

    printf("%d", even_cnt + odd_cnt);

    return 0;
}