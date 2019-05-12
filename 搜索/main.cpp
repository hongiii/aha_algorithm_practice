#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 101;
int n;
int a[N], book[N];
int sum = 0;
void dfs(int step)
{
    if(step == 9)
    {
        if(a[0]*100+a[1]*10+a[2] + a[3]*100+a[4]*10+a[5] == a[6]*100+a[7]*10+a[8])
        {
            for(int i = 0; i < 9; i++)
                printf("%d ", a[i]);
            sum++;
                printf("\n");
        }
        return;
    }
    for(int i = 1; i < 10; i++)
    {
        if(book[i] == 0)
        {
            a[step] = i;
            book[i] = 1;
            dfs(step+1);
            book[i] = 0;
         }
    }
    return;
}

int main()
{
   // scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(book, 0, sizeof(book));
    dfs(0);
    printf("\n%d", sum/2);
    return 0;
}
