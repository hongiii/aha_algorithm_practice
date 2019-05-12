//求第K大，建立大小为K的最小堆
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110;

int h[N];
int n, k;
void swap(int i, int j)
{
    int t = h[i];
    h[i] = h[j];
    h[j] = t;
}
void siftdown(int i)
{
    int flag = 0, t;
    while(i*2 <= k && flag == 0)
    {
        if(h[i] > h[i*2])
            t = i*2;
        else
            t = i;
        if(i*2 + 1 <= n)
        {
            if(h[t] < h[i*2+1])
                t = i*2+1;
        }
        if(t != i)
        {
            swap(i, t);
            i = t;
        }
        else
            flag = 1;
    }
    return;
}

void setup()
{
    for(int i = k/2; k >= 1; k--)
        siftdown(i);
}
int main()
{
    scanf("%d%d", &n, &k);
    int tmp;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        if(i <= k)
            siftdown(i);
        else
        {
            if(tmp > h[1])
            {
                h[1] = tmp;
                siftdown(1);
            }
            else
                continue;
        }
    }
    printf("%d", h[1]);
    return 0;
}

/*
14 3
99 5 36 7 22 17 46 12 2 19 25 28 1 92
*/
