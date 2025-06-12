#include <stdio.h>
#define BLOCK_SIZE 101

void arr_insert_first_elem(int* arr, int max_idx, int insert_idx)
{
    if (insert_idx > max_idx) { return; }

    int insert_value = arr[0];

    for (int i = 1; i <= insert_idx; ++i)
    {
        arr[i - 1] = arr[i];
    }

    arr[insert_idx] = insert_value;
}

int is_sorted(const int* const arr, int max_idx)
{
    for (int i = 0; i < max_idx - 1; ++i)
    {
        if (arr[i + 1] < arr[i])
        {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    int blocks[BLOCK_SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &blocks[i]);

    // Please write your code here.

    int cnt = 0;
    while (!is_sorted(blocks, n))
    {
        for (int i = n - cnt - 1; i > -1 && i <= n; i++)
        {
            if (blocks[i] > blocks[0] || i == n)
            {
                arr_insert_first_elem(blocks, n, i - 1);
                cnt++;
                break;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}