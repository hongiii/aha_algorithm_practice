//出队操作head++
//入队操作q[tail] = x, tail++
//模拟qq号问题

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int a[20] = {6,3,1,7,5,8,9,2,4};
    int head, tail;
    head = 0, tail = 9;
    while(head < tail)
    {
        printf("%d ", a[head]);
        head++;

        a[tail] = a[head];
        tail++;
    //    printf("%d ", a[head]);
        head++;
    }
    return 0;
}
