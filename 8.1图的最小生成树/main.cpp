#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct edge
{
    int u;
    int v;
    int w;
};

const int N = 110;
int n, m, a[N];
edge node[N];

void init()
{
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++)
        a[i] = i;
}

int getfather(int i)
{
    if(a[i] == i)
        return i;
    else
    {
        a[i] = getfather(a[i]);
        return a[i];
    }
}

int mergeuv(int u, int v)
{
    int ufa = getfather(u);
    int vfa = getfather(v);
    if(ufa != vfa)
    {
        a[vfa] = a[ufa];
        return 0;
    }
    return 1;
}

//void quicksort(int left, int right)
//{
//    if(left >= right)
//        return;
//    edge temp = node[left];
//    int i = left;
//    int j = right;
//    while(i != j)
//    {
//        while(node[j].w >= node[left].w && i < j)
//            j--;
//        while(node[i].w <= node[left].w && i < j)
//            i++;
//
//        if(i < j)
//        {
//            edge tmp = node[i];
//            node[i] = node[j];
//            node[j] = tmp;
//        }
//    }
//    node[left] = node[i];
//    node[i] = temp;
//    quicksort(left, i-1);
//    quicksort(i+1, right);
//    return;
//}
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
int main()
{
    scanf("%d%d", &n, &m);
    init();
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &node[i].u, &node[i].v, &node[i].w);
    }
    sort(node+1, node+m+1, cmp);
  //  quicksort(1, m);
//    for(int i = 1; i <= m; i++)
//    {
//        printf("%d %d %d\n", node[i].u, node[i].v, node[i].w);
//    }
    int cnt = 0;
    int sum = 0;
    for(int i = 1; i <= m; i++)
    {
         int t = mergeuv(node[i].u, node[i].v);
         if(t == 0 && cnt != n-1)
         {
             cnt++;
             sum += node[i].w;
             printf("%d %d\n", node[i].u, node[i].v);
         }
         else
            continue;
    }
    printf("%d", sum);
}

/*
6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2
*/
