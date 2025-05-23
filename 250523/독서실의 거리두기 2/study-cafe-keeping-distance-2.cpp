#include <iostream>
#include <string>

using namespace std;

int N;
string seats;

int main() {
    cin >> N;
    cin >> seats;

    // Please write your code here.

    int max_dist = 0;
    int dist_start = 0;
    int max_dist_idx = 0;

    for (int i = 0; i < seats.length(); i++)
    {
        if (seats[i] == '1')
        {
            if (dist_start == 0 && seats[0] == '0')
            {
                max_dist = i + 1;
                max_dist_idx = 0;
            }
            else if (max_dist < (i - dist_start) / 2) 
            {
                max_dist = (i - dist_start) / 2;
                max_dist_idx = (i + dist_start) / 2;
            }
            dist_start = i;
        }
        else if (i == seats.length() - 1)
        {
            if (max_dist < i - dist_start)
            {
                max_dist = i - dist_start;
                max_dist_idx = i;
            } 
        }
    }
    seats[max_dist_idx] = '1';

    int min_dist = N;
    dist_start = -1;

    for (int i = 0; i < seats.length(); i++)
    {
        if (seats[i] == '1')
        {
            if (i == 0)
            {
                dist_start = i;
                continue;
            }

            if (dist_start != -1 && min_dist > i - dist_start) 
            {
                min_dist = i - dist_start;
            }

            dist_start = i;
        }
    }  

    cout << min_dist;

    return 0;
}