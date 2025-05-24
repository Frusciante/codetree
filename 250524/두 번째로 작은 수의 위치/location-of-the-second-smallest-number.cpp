#include <iostream>

using namespace std;

int n;
int a[101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Please write your code here.

    int min = a[1];
    int sec_min = -1;
    int sec_min_idx = -1;

    for (int i = 2; i <= n; i++)
    {
        if (a[i] < min)
        {
            if (sec_min == -1)
            {
                sec_min = min;
                sec_min_idx = i;
                min = a[i];
            }
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
        else if (a[i] > min && sec_min == -1)
        {
            sec_min = a[i];
            sec_min_idx = i;
        }
    }

    cout << sec_min_idx;

    return 0;
}