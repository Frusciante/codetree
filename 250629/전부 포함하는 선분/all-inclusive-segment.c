#include <stdio.h>
#define MAX(n1, n2) (((n1) > (n2)) ? (n1) : (n2))
#define MIN(n1, n2) (((n1) < (n2)) ? (n1) : (n2))

typedef struct
{
    int start;
    int end;
} LINE;

int main() 
{
    int n;
    LINE lines[100];
    scanf("%d", &n);
    int left_end = 100;
    int right_end = 0;

    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d", &lines[i].start, &lines[i].end);
        left_end = MIN(left_end, lines[i].start);
        right_end = MAX(right_end, lines[i].end);
    }

    LINE answer_without_first = {100, 0};
    LINE answer_without_last = {100, 0};

    for (int i = 0; i < n; i++)
    {
        if (lines[i].start == left_end)
        {
            answer_without_last.start = MIN(answer_without_last.start, lines[i].start);
            answer_without_last.end = MAX(answer_without_last.end, lines[i].end);\
            continue;
        }

        if (lines[i].end == right_end)
        {
            answer_without_first.start = MIN(answer_without_first.start, lines[i].start);
            answer_without_first.end = MAX(answer_without_first.end, lines[i].end);
            continue;
        }

        answer_without_last.start = MIN(answer_without_last.start, lines[i].start);
        answer_without_last.end = MAX(answer_without_last.end, lines[i].end);
        answer_without_first.start = MIN(answer_without_first.start, lines[i].start);
        answer_without_first.end = MAX(answer_without_first.end, lines[i].end);
    }

    printf("%d", MIN(answer_without_first.end - answer_without_first.start, answer_without_last.end - answer_without_last.start));

    return 0;
}