#include <iostream>
#include <string>
#include <cmath>
#define MAX_VAL 1000

using namespace std;

int N;
string seats;

int main() {
    cin >> N;
    cin >> seats;

    // Please write your code here.

    int max_dist = 0;
    int max_dist_start_idx = 1;
    for (int i = 1; i < N - 1; i++)
    {
        int temp_dist = 1;

        for (int j = i; seats[j] == '0'; j++)
        {
            temp_dist++;
        }

        if (max_dist < temp_dist)
        {
            max_dist = temp_dist;
            max_dist_start_idx = i;
        }

        i += temp_dist - 1;
    }

    seats[max_dist_start_idx + (max_dist / 2) - 1] = '1';

    int min_dist = MAX_VAL;

    for (int i = 1; i < N - 1; i++)
    {
        int temp_dist = 1;

        for (int j = i; seats[j] == '0'; j++)
        {
            temp_dist++;
        }

        if (min_dist > temp_dist)
        {
            min_dist = temp_dist;
        }

        i += temp_dist - 1;
    }

    cout << min_dist;

    return 0;
}
