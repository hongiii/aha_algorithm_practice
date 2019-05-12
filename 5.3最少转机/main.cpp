#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100;
const int INF = 9999999;
int n, m, p, q, srt, ed;
int head, tail;
int a[N][N], book[N];
struct nodee
{
    int x;
    int dis;
};

nodee node[N];

void bfs()
{
    while(head < tail)
    {
        if(node[head].x == ed)
        {
            printf("%d\n", node[head].dis);
            return;
        }
  //      printf("1--%d--\n", node[head].x);
        for(int i = 1; i <= n; i++)
        {
            if(a[node[head].x][i] == 1 && book[i] == 0)
            {
   //             printf("2--%d---%d--\n", node[head].x, i);
                node[tail].x = i;
                node[tail].dis = node[head].dis + 1;
                tail++;
                book[i] = 1;
            }
        }
        head++;
    }
}

int main()
{
    memset(a, 0, sizeof(a));
    memset(book, 0, sizeof(book));

    scanf("%d%d%d%d", &n, &m, &srt, &ed);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &p, &q);
        a[p][q] = 1;
        a[q][p] = 1;
        a[i][i] = 0;
    }
    head = tail = 0;
    node[tail].x = srt;
    node[tail].dis = 0;
    tail++;
    book[p] = 1;

    bfs();

    return 0;
}

/*
5 7 1 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5


*/

