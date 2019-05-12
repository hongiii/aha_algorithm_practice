//冒泡排序的基本思想：每次比较相邻的两个元素，如果顺序错误就把它们交换过来。
//给定一个数据序列12 35 99 18 76，如果是从小到大排序
//第一趟，12 35 18 76 | 99
//第二趟，12 18 35 | 76 99
//第三趟，12 18 | 35 76 99
//第四趟，12 | 18 35 76 99
//复杂度O(N*N)

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100+10;
void bubblesort(int a[], int n);
int main()
{
    int a[N], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bubblesort(a, n);

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

void bubblesort(int a[], int n)
{
    int tmp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1]) //从小到大
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}
