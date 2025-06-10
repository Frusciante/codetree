#include <stdio.h>

int n, m;
int arr[101];

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 0; i < n; i++) {
       scanf("%d", &arr[i]);
   }

   // Please write your code here.

   int i = 0;
   int cnt = 0;

   for (;;)
   {
       while (i < n && i >= 0 && arr[i] == 0) { i++; }
       
       int next = i + (m * 2 + 1);

       if (next >= n)
       {
           for (int j = i; j < n; j++)
           {
               if (arr[j])
               {
                   cnt++;
                   break;
               }
           }
           break;
       }

       i = next;
       cnt++;
   }

   printf("%d", cnt);

   return 0;
}