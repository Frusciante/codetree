#include <iostream>
#include <cstring>

using namespace std;

int n;
char c[100];
int s[100];

enum
{
    A_SCORE, B_SCORE, C_SCORE, SCORE_CNT
};

void get_winner(bool* hall_of_fame, int* score)
{
    int max = score[0];

    memset(hall_of_fame, false, SCORE_CNT * sizeof(bool));

    for (int i = 1; i < SCORE_CNT; i++)
    {
        if (score[i] > max) { max = score[i]; }
    }

    for (int i = 0; i < SCORE_CNT; i++)
    {
        if (score[i] == max) { hall_of_fame[i] = true; }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> s[i];
    }

    // Please write your code here.

    bool hall_of_fame[sizeof(int)] = {true, true, true, true};
    bool cp_hall_of_fame[sizeof(int)] {true, true, true, true};
    int score[SCORE_CNT] = {};
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        memcpy(cp_hall_of_fame, hall_of_fame, sizeof(hall_of_fame));

        switch (c[i])
        {
            case 'A':
            score[A_SCORE] += s[i];
            break;

            case 'B':
            score[B_SCORE] += s[i];
            break;
            
            case 'C':
            score[C_SCORE] += s[i];
            break;
        }

        get_winner(hall_of_fame, score);

        if ((*(int*)hall_of_fame ^ *(int*)cp_hall_of_fame) != 0) { ++cnt; }
    }

    cout << cnt;

    return 0;
}