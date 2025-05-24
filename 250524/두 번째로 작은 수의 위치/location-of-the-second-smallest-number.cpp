#include <iostream>

using namespace std;

int n;
int a[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Please write your code here.

    int min = a[0];
    int min_idx = 0;
    int sec_min = 100;
    int sec_min_idx = -1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            sec_min = min;
            sec_min_idx = min_idx;
            min = a[i];
            min_idx = i;
        }
        else if (min < a[i] && a[i] < sec_min)
        {
            sec_min = a[i];
            sec_min_idx = i;
        }
        else if (a[i] == sec_min)
        {
            sec_min_idx = -1;
        }
    }

    cout << ((sec_min_idx == -1) ? -1 : sec_min_idx + 1);

    return 0;
}