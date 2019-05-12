#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int f[10] = {6,2,5,5,4,5,6,3,7,6};
int fun(int n)
{
    int num = 0;
    while(n/10)
    {
        num += f[n%10];
        n /= 10;
    }
    num += f[n];
    return num;
}

int main()
{
    for(int i = 0; i <= 1000; i++)
    {
        for(int j = 0; j <= 1000; j++)
        {
            int k = i + j;
            if(fun(k)+fun(i)+fun(j) == 18-4)
                printf("%d %d %d\n", i, j, k);
        }
    }
    return 0;
}

