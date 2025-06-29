#include <stdio.h>
#define MAX(n1, n2) (((n1) > (n2)) ? (n1) : (n2))
#define MIN(n1, n2) (((n1) < (n2)) ? (n1) : (n2))

int main() {
    int x1, y1, x2, y2;
    int a1, b1, a2, b2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
    
    // Please write your code here.

    int x_len = MAX(x2, a2) - MIN(x1, a1);
    int y_len = MAX(y2, b2) - MIN(y1, b1);

    printf("%d", (x_len > y_len) ? x_len * x_len : y_len * y_len);
    
    return 0;
}