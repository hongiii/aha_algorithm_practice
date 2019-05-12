#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 110;
int n, m, a[N];
//ÕÒµùº¯Êı
int getpapa(int t)
{
    if(a[t] == t)
        return t;
    else
    {
        a[t] = getpapa(a[t]);
        return a[t];
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        a[i] = i;
    int u, v;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        int upa = getpapa(u);
        int vpa = getpapa(v);
        if(upa != vpa)
        {
            a[vpa] = a[upa];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        printf("%d-%d\n", i, a[i]);
        if(i == a[i])
            cnt++;
    }
    printf("%d\n", cnt);
}

/*
10 9
1 2
3 4
5 2
4 6
2 6
8 7
9 7
1 6
2 4
*/
