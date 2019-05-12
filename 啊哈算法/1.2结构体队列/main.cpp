#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Queue
{
    int data[101];
    int head;
    int tail;
};

int main()
{
    struct Queue que;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &que.data[i]);
    que.head = 0, que.tail = n;
    while(que.head < que.tail)
    {
        printf("%d ", que.data[que.head]);
        que.head++;

        que.data[que.tail] = que.data[que.head];
        que.tail++;

        que.head++;
    }
    return 0;
}
