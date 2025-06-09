#include <stdio.h>

int n, m;
int arr[101];

enum
{
    NO_WIFI_VACANT, NO_WIFI_LIVING, WIFI_VACANT, WIFI_LIVING
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
        cnt = 1;
    }
    else
    {
        for (int i = m; i < n; i++)
        {
            if (arr[i - m] == NO_WIFI_LIVING)
            {
                cnt++;
                for (int j = i - m; j <= i; j++)
                {
                    arr[j] = (arr[j] == NO_WIFI_LIVING) ? WIFI_LIVING : WIFI_VACANT;
                }
            }
        }
    }

    

    printf("%d", cnt);
    
    return 0;
}