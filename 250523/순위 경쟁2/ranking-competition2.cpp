#include <iostream>

using namespace std;

int n;
char c[100];
int s[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> s[i];
    }

    // Please write your code here.

    int a_score = 0;
    int b_score = 0;
    int cnt = 0;

    bool hall_of_fame[2] = { true, true };

    for (int i = 0; i < n; i++)
    {
        bool cp_hall_of_fame[2] = { hall_of_fame[0], hall_of_fame[1] };
        
        switch(c[i])
        {
            case 'A':
            a_score += s[i];
            break;

            case 'B':
            b_score += s[i];
            break;
        }

        if (a_score > b_score) { hall_of_fame[0] = true; hall_of_fame[1] = false; }
        else if (a_score < b_score) { hall_of_fame[0] = false; hall_of_fame[1] = true; }
        else { hall_of_fame[0] = true; hall_of_fame[1] = true; };

        if (cp_hall_of_fame[0] != hall_of_fame[0] || cp_hall_of_fame[1] != hall_of_fame[1])
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}