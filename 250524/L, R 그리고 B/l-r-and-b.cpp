#include <iostream>
#include <cmath>

using namespace std;

char board[10][10];

struct loc
{
    int row;
    int col;
};

int main() {

    loc l_loc = {};
    loc r_loc = {};
    loc b_loc = {};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            switch (board[i][j])
            {
                case 'B':
                b_loc.row = i;
                b_loc.col = j;
                break;

                case 'R':
                r_loc.row = i;
                r_loc.col = j;
                break;

                case 'L':
                l_loc.row = i;
                l_loc.col = j;
                break;
            }
        }
    }

    // Please write your code here.

    int min_dist = 100;

    if (b_loc.row == r_loc.row && r_loc.row == l_loc.row ||
        b_loc.col == r_loc.col && r_loc.col == l_loc.col)
    {
        min_dist = abs(b_loc.row - l_loc.row) + abs(b_loc.col - l_loc.col) + 1;
    }
    else
    {
        min_dist = abs(b_loc.row - l_loc.row) + abs(b_loc.col - l_loc.col) - 1;
    }

    cout << min_dist;

    return 0;
}