#include <iostream>

using namespace std;

int n;
char arr[26];

void swap(char* c1, char* c2)
{
    char tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Please write your code here.

    int cnt = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}