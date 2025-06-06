#include <stdio.h>

int n;
int blocks[10000];

int main() {

    int i, j;
    int sum = 0;
    int goal;
    int cnt = 0;
    int leftovers;
    int move_amount;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
        sum += blocks[i];
    }
    // Please write your code here.

    goal = sum / n;

    for (i = 0; i < n; i++)
    {
        j = i + 1;
        if (blocks[i] > goal)
        {
            leftovers = blocks[i] - goal;
            cnt += leftovers;
            blocks[i] -= leftovers;
            while (j < n && leftovers > 0)
            {
                if (blocks[j] < goal)
                {
                    move_amount = leftovers % (goal + 1);
                    blocks[j] += move_amount;
                    leftovers -= move_amount;
                }
                j++;
            }    
        }
        else if (blocks[i] < goal)
        {
            leftovers = goal - blocks[i];
            cnt += leftovers;
            blocks[i] += leftovers;
            while (j < n && leftovers > 0)
            {
                if (blocks[j] > goal)
                {
                    move_amount = leftovers % (goal + 1);
                    blocks[j] -= move_amount;
                    leftovers -= move_amount;
                }
                j++;
            } 
        }
    }

    printf("%d", cnt);

    return 0;
}