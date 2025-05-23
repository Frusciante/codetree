#include <iostream>

using namespace std;

int a[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> a[i];

    // Please write your code here.

    int max_interval = (a[1] - a[0] > a[2] - a[1]) ? a[1] - a[0] : a[2] - a[1];

    cout << max_interval - 1;

    return 0;
}