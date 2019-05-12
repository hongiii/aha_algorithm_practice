#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 999;
int h[N], n;

void _swap(int x, int y)
{
    int t = h[x];
    h[x] = h[y];
    h[y] = t;
}

void siftdown(int i)
{
    int flag = 0;
    while(i*2 <= n && flag == 0) //如果有左儿子
    {
        int t;
        if(h[i] > h[i*2])
            t = 2*i;
        else
            t = i;
        if(i*2+1 <= n) //如果有右儿子
        {
            if(h[i*2+1] < h[t])
                t = 2*i + 1;
        }
        if(t != i)
        {
            _swap(t, i);
            i = t;
        }
        else
            flag = 1;
    }
}

void siftup(int i)
{
    if(i == 1) return;
    int flag = 0;
    while(i != 1 && flag == 0)
    {
        if(h[i/2] > h[i])
            _swap(i, i/2);
        else
            flag = 1;
        i /= 2;
    }
    return;
}

void build()
{
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &h[n]);
        siftup(n);
    }
}

void build_faster()
{
    for(int i = n/2; i >= 1; i--)
        siftdown(i);
}
//删除最小的元素
int deletemin()
{
    int t = h[1];
    h[1] = h[n]; //将对的最后一个元素放到堆顶
    n--;
    siftdown(1);
    return t;
}

void heapsort()
{
    while(n > 1)
    {
        _swap(1, n);
        n--;
        siftdown(1);
    }
    return;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    //build();
    build_faster();
    int num = n;
    heapsort();
    for(int i = 1; i <= num; i++)
    {
        printf("%d ", h[i]);
    }
    printf("\n");

//    while(n != 0)
//    {
//        printf("%d ", deletemin());
//    }
    return 0;
}

/*
14
99 5 36 7 22 17 46 12 2 19 25 28 1 92
*/
