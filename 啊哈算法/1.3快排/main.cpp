//快排的基本思想：快排主要基于二分的思想，它引入了基准值、两个哨兵，其中左边哨兵从左往右，右边哨兵从右往左。
//如果是从小到大排序，右边的哨兵找到比基准值小的数停下来。左边找到比基准值大的数停下来，如果两个哨兵没有相遇，就交换这两个数。
//重复上述步骤，直至两个哨兵相遇，此时停下来，将基准值归位，使得基准值左边的数都小于基准值，右边都大于基准值。
//此时，基准值左边的数列和右边的数列，可以看成原始问题的子问题。
//分别应用上述思想，就可以排好序了。
//程序如下：

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100+10;

void quicksort(int a[], int left, int right)
{
    if(left > right)
        return;
    int tmp = a[left];
    int i = left, j = right;
    while(i != j)
    {
        while(a[j] >= tmp && i < j)
            j--;
        while(a[i] <= tmp && i < j)
            i++;
        if(i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    //基准值归位
    a[left] = a[i];
    a[i] = tmp;

    quicksort(a, left, i-1);
    quicksort(a, i+1, right);

    return;
}

int main()
{
    int n;
    int a[N];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
