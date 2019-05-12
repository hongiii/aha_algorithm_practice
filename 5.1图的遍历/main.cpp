#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 51;
const int INF = 9999999;
int n, m, a[N][N], book[N];
int head, tail, p, q;
int note[N];

//int p, q, sum = 0;

//void dfs(int cur)
//{
//    printf("%d ", cur+1);
//    sum++;
//    if(sum == n)
//        return;
//
//    for(int i = 0; i < n; i++)
//    {
//        if(a[cur][i] == 1 && book[i] == 0)
//        {
//            book[i] = 1;
//            dfs(i);
//        }
//    }
//}

void bfs()
{
    while(head < tail)
    {
        printf("%d ", note[head]+1);
        if(head == 4)
            return;
        for(int i = 0; i < n; i++)
        {
            if(a[head][i] == 1 && book[i] == 0)
            {
                note[tail] = i;
                tail++;
            //    printf("-%d-\n", i+1);
                book[i] = 1;
            }
        }
        head++;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(a, INF, sizeof(a));
    memset(book, 0, sizeof(book));

    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &p, &q);
        a[p-1][q-1] = 1;
        a[i][i] = 0;
    }

//    book[0] = 1;
//    dfs(0);
    head = tail = 0;
    note[tail] = 0;
    tail++;
    book[0] = 1;
    bfs();

    return 0;
}

/*
5 5
1 2
1 3
1 5
2 4
3 5
*/
