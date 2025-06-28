#include <stdio.h>
#include <math.h>
#define MAX(n1, n2) ((n1 > n2) ? (n1) : (n2))
#define MIN(n1, n2) ((n1 < n2) ? (n1) : (n2))

typedef struct
{
    int x;
    int y;
} POINT;

typedef struct
{
    POINT p1;
    POINT p2;
} SQUARE;

int main() 
{
    SQUARE s1, s2;

    scanf("%d %d %d %d", &s1.p1.x, &s1.p1.y, &s1.p2.x, &s1.p2.y);
    scanf("%d %d %d %d", &s2.p1.x, &s2.p1.y, &s2.p2.x, &s2.p2.y);
    // Please write your code here.

    printf("%d", (MAX(s1.p1.x, MAX(s1.p2.x, MAX(s2.p1.x, s2.p2.x)))
     - MIN(s1.p1.x, MIN(s1.p2.x, MIN(s2.p1.x, s2.p2.x)))) *
     (MAX(s1.p1.y, MAX(s1.p2.y, MAX(s2.p1.y, s2.p2.y)))
     - MIN(s1.p1.y, MIN(s1.p2.y, MIN(s2.p1.y, s2.p2.y))))
     );

    return 0;
}