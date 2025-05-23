#include <iostream>
#include <cstring>

using namespace std;

int N;
int a[100], b[100];

enum
{
    ROCK, SCISSOR, PAPER
};

enum
{
    WIN = 1, DRAW = 0, LOSE = -1
};

/*
 \brief  p1이 이기면 1, 비기면 0, 지면 -1을 반환하는 함수
*/
int game(int p1, int p2)
{
    switch (p1)
    {
    case ROCK:
        switch (p2)
        {
        case ROCK:
            return DRAW;
        case SCISSOR:
            return WIN;
        case PAPER:
            return LOSE;
        }
    case SCISSOR:
        switch (p2)
        {
        case ROCK:
            return LOSE;
        case SCISSOR:
            return DRAW;
        case PAPER:
            return WIN;
        }
    case PAPER:
        switch (p2)
        {
        case ROCK:
            return WIN;
        case SCISSOR:
            return LOSE;
        case PAPER:
            return DRAW;
        }
    }
}

const char all_cases[][3] =
{   
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

constexpr int NUM_CASES = sizeof(all_cases) / 3;

int main()
{
    cin >> N;

    char cases[3];

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    // Please write your code here.

    int max_cnt = 0;
 
    for (int i = 0; i < NUM_CASES; i++)
    {
        int tmp_cnt = 0;

        cases[all_cases[i][0]] = ROCK;
        cases[all_cases[i][1]] = SCISSOR;
        cases[all_cases[i][2]] = PAPER;

        for (int j = 0; j < N; j++)
        {
            if (1 == game(cases[a[j] - 1], cases[b[j] - 1])) { tmp_cnt++; }
        }

        if (tmp_cnt >= max_cnt) max_cnt = tmp_cnt;
    }

    cout << max_cnt;

    return 0;
}