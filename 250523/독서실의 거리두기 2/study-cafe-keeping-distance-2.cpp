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

    for (int i = 1; i < seats.length(); i++)
    {
        if (seats[i] == '1')
        {
            if (max_dist < i - dist_start) 
            {
                max_dist = (i - dist_start) / 2;
                dist_start = i;
            }
        }
        else if (i == seats.length() - 1)
        {
            if (max_dist < i - dist_start)
            {
                max_dist = i - dist_start;
            } 
        }
    }

    cout << max_dist;

    return 0;
}