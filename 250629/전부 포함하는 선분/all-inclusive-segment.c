#include <stdio.h>
#include <stdlib.h>
#define MIN(n1, n2) (((n1) < (n2)) ? (n1) : (n2))

typedef struct
{
    int start;
    int end;
} LINE;

int asc_LINE(const void* first, const void* second)
{
    if (((LINE*)first)->start > ((LINE*)second)->start) { return 1; }
    if (((LINE*)first)->start < ((LINE*)second)->start) { return -1; }
    
    if (((LINE*)first)->end > ((LINE*)second)->end) { return 1; }
    if (((LINE*)first)->end < ((LINE*)second)->end) { return -1; }

    return 0;
}

int desc_LINE(const void* first, const void* second)
{
    if (((LINE*)first)->end > ((LINE*)second)->end) { return -1; }
    if (((LINE*)first)->end < ((LINE*)second)->end) { return 1; }

    if (((LINE*)first)->start > ((LINE*)second)->start) { return -1; }
    if (((LINE*)first)->start < ((LINE*)second)->start) { return 1; }

    return 0;
}

int main() 
{
    LINE lines[100];
    LINE lines_backward[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d", &lines[i].start, &lines[i].end);
        lines_backward[i].start = lines[i].start;
        lines_backward[i].end = lines[i].end;
    }
    
    // Please write your code here.
    qsort(lines, n, sizeof(LINE), asc_LINE);
    qsort(lines_backward, n, sizeof(LINE), desc_LINE);

    if (lines[0].start == lines_backward[0].start && lines[0].end == lines_backward[0].end)
    {
        printf("%d", lines_backward[1].end - lines[1].start);
    }
    else
    {
        printf("%d", MIN(lines_backward[0].end - lines[1].start, lines_backward[1].end - lines[0].start));
    }

    return 0;
}