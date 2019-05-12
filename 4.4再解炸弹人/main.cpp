#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

struct note
{
    int x;
    int y;
};

const int N = 51;
int sum = 0;
char a[N][N];
note nt[N*N];
int n, m, startx, starty, head, tail, book[N][N];
int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int p, q;

int getnum(int x, int y)
{
   int sum = 0;
   int tx = x, ty = y;
   while(a[tx][ty] != '#')
        {
            if(a[tx][ty] == 'G')
            {
                sum++;
            }
            tx++;
        }
        tx = x, ty = y;
        while(a[tx][ty] != '#')
        {
            if(a[tx][ty] == 'G')
            {
                sum++;
            }
            ty++;
        }
        tx = x, ty = y;
        while(a[tx][ty] != '#')
        {
            if(a[tx][ty] == 'G')
            {
                sum++;
            }
            tx--;
        }
        tx = x, ty = y;
        while(a[tx][ty] != '#')
        {
            if(a[tx][ty] == 'G')
            {
                sum++;
            }
            ty--;
        }

   return sum;
}

void bfs(int x, int y)
{
    int tx, ty;
    while(head < tail)
    {
        for(int i = 0; i < 4; i++)
        {
            tx = nt[head].x + next[i][0];
            ty = nt[head].y + next[i][1];
            if(tx < 1 || tx > n || ty < 1 || ty > m)
                continue;
            if(a[tx][ty] == '.' && book[tx][ty] == 0)
            {
        //        printf("%d--%d\n", tx, ty);
                nt[tail].x = tx;
                nt[tail].y = ty;
                tail++;
                book[tx][ty] = 1;
                int num = getnum(tx, ty);
                if(sum < num)
                {
                    sum = num;
               //     printf("--%d--\n", sum);
                    p = tx;
                    q = ty;
                }
            }
        }
        head++;
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &startx, &starty);
    for(int i = 0; i < n; i++)
        scanf("%s", a[i]);
    memset(book, 0, sizeof(0));
//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < m; j++)
//            printf("%c", a[i][j]);
//        printf("\n");
//    }
    head = tail = 0;

    p = nt[tail].x = startx;
    q = nt[tail].y = starty;
    tail++;

    book[startx][starty] = 1;
    sum = getnum(startx, starty);
    bfs(startx, starty);
    printf("%d %d %d\n", sum, p, q);
    return 0;
}

/*
13 13 3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/
