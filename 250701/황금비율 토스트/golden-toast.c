#include <stdio.h>

char s[100005];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    char* iter = s + n;
    char* end = iter; // end (마지막 원소 + 1)
    char* begin = s;
    char char_to_insert;
    getchar();

    for (int i = 0; i < m; i++) {
        char command;
        scanf("%c", &command, 1);
        getchar();
        switch (command)
        {
        case 'L':
            if (iter != begin)
            {
                iter--;
            }
            break;
        case 'R':
            if (iter != end)
            {
                iter++;
            }
            break;
        case 'P':
            scanf("%c", &char_to_insert, 1);
            getchar();
            ++end;
            for (char* temp_iter = end; temp_iter != iter; --temp_iter)
            {
                *temp_iter = *(temp_iter - 1);
            }
            *end = 0;
            *iter = char_to_insert;
            ++iter;
            break;
        case 'D':
            if (iter == end)
            {
                continue;
            }

            for (char* temp_iter = iter; temp_iter != end; ++temp_iter)
            {
                *temp_iter = *(temp_iter + 1);
            }
            end--;
            *end = 0;

            break;
        }
    }

    printf("%s", s);

    // Please write your code here.
    return 0;
}