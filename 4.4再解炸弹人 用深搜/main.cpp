#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 51;
int sum = 0;
char a[N][N];
int n, m, startx, starty, book[N][N];
int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int p, q;
int cnt = 0;

int getnum(int x, int y)
{
   int num = 0;
   int tx = x, ty = y;
   if(a[tx][ty] != '.')
     return num;
   while(a[tx][ty] != '#')
   {
        if(a[tx][ty] == 'G')
        {
            num++;
        }
        tx++;
    }
    tx = x, ty = y;
    while(a[tx][ty] != '#')
    {
        if(a[tx][ty] == 'G')
        {
            num++;
        }
        ty++;
    }
    tx = x, ty = y;
    while(a[tx][ty] != '#')
    {
        if(a[tx][ty] == 'G')
        {
            num++;
        }
        tx--;
    }
    tx = x, ty = y;
    while(a[tx][ty] != '#')
    {
        if(a[tx][ty] == 'G')
        {
            num++;
        }
        ty--;
    }

   return num;
}

void dfs(int x, int y)
{
    cnt++;
    int num = getnum(x, y);
    if(num > sum)
    {
        sum = num;
        p = x;
        q = y;
    }
    int tx, ty;
    for(int i = 0; i < 4; i++)
    {
        tx = x + next[i][0];
        ty = y + next[i][1];
        if(tx < 1 || tx > n || ty < 1 || ty > m)
            continue;
        if(a[tx][ty] == '.' && book[tx][ty] == 0)
        {
            book[tx][ty] = 1;
            dfs(tx, ty);
            printf("%d-%d\n", tx, ty);
           // book[tx][ty] = 0;  //https://blog.ihypo.net/15013048758625.html
        }
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
    dfs(starty, starty);
    printf("%d %d\n", sum, cnt);
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
