#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 50+10;
int a[N][N], book[N][N];
int p,q,m,n,bg,ed;
int arr[4][2] = {{0,1}, {1,0},{0,-1},{-1,0}};
int mindis = 2500;
int head, tail, cnt = 0;
struct node //队列
{
    int x; //横坐标
    int y; //纵坐标
    int s; //步数
};
node nd[51];
void bfs()
{
    while(head < tail)
    {
        if(nd[head].x == p-1 && nd[head].y == q-1)
        {
            if(nd[head].s < mindis)
                mindis = nd[head].s;
            return;
        }
        int tx, ty;
        for(int i = 0; i < 4; i++)
        {
            tx = nd[head].x + arr[i][0];
            ty = nd[head].y + arr[i][1];
            if(tx < 0 || ty < 0 || tx > n-1 || ty > m-1)
                continue;
            if(a[tx][ty] == 0 && book[tx][ty] == 0)
            {
                nd[tail].x = tx;
                nd[tail].y = ty;
                nd[tail].s = nd[head].s + 1;
                book[tx][ty] = 1;
                tail++;
            }
        }
        head++;
    }
}
int main()
{
    scanf("%d%d", &n, &m);

    memset(book, 0, sizeof(book));
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    scanf("%d%d%d%d", &bg, &ed, &p, &q);
    book[bg-1][ed-1] = 1;
    head = tail = 0;
    nd[0].x = bg-1;
    nd[0].y = ed-1;
    nd[0].s = 0;
    tail++;
    bfs();
    printf("%d\n", mindis);
    return 0;
}

/*
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3
*/
