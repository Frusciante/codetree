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

    int cnt = 0;
    char order[3] = {};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            switch (board[i][j])
            {
                case 'B':
                b_loc.row = i;
                b_loc.col = j;
                order[cnt] = 'B';
                cnt++;
                break;

                case 'R':
                r_loc.row = i;
                r_loc.col = j;
                order[cnt] = 'R';
                cnt++;
                break;

                case 'L':
                l_loc.row = i;
                l_loc.col = j;
                order[cnt] = 'L';
                cnt++;
                break;
            }
        }
    }

    bool r_is_between_b_and_l = (order[1] == 'R');

    // Please write your code here.

    int min_dist = 100;

    if ((b_loc.row == r_loc.row && r_loc.row == l_loc.row ||
        b_loc.col == r_loc.col && r_loc.col == l_loc.col)
        && r_is_between_b_and_l
        )
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