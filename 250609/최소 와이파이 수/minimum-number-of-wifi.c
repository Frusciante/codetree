#include <stdio.h>

int n, m;
int arr[101];

enum
{
    NO_WIFI_VACANT, NO_WIFI_LIVING, WIFI_VACANT, WIFI_LIVING, ROUTER
};

int main() 
{
    int temp;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &temp);
        arr[i] = (temp == 1) ? NO_WIFI_LIVING : NO_WIFI_VACANT;
    }
    
    // Please write your code here.

    int cnt = 0;

    if (n <= m)
    {
        m = n - 1;
    }

    for (int i = m; i < n; i++)
    {
        if (arr[i - m] == NO_WIFI_LIVING)
        {
            for (int j = i - m; j <= i + m && j < n; j++)
            {
                if (i == j) arr[j] = ROUTER;
                else arr[j] = (arr[j] == NO_WIFI_LIVING) ? WIFI_LIVING : WIFI_VACANT;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ROUTER) cnt++;
    }

    printf("%d", cnt);
    
    return 0;
}