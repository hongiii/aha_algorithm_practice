#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 51;
const int INF = 99;
int u[N], v[N], w[N], book[N];
int head, tail, dis[N], n, m;
int Queue[N], next[N], first[N];

void bellman_ford_()
{
    while(head < tail)
    {
        int t = Queue[head];
        int k = first[t];
        while(k != -1)
        {
            if(dis[u[k]] + w[k] < dis[v[k]])
            {
                 dis[v[k]] = dis[t] + w[k];
                 if(book[v[k]] == 0)
                 {
                     Queue[tail] = v[k];
                     tail++;
                     book[v[k]] = 1;
                 }
            }
            k = next[k];
        }
        book[Queue[head]] = 0;
        head++;
    }
}

int main()
{
    memset(book, 0, sizeof(book));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        dis[i] = INF;
        first[i] = -1;
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        next[i] = first[u[i]];
        first[u[i]] = i;
    }
    dis[1] = 0;
    head = tail = 0;
    Queue[tail++] = 1;
    book[1] = 1;
    bellman_ford_();
    for(int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}

/*
5 7
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
*/
