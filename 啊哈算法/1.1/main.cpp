#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int N = 100+10;
int a[N];

int main(){
    int n;
    scanf("%d", &n);
    int num;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        a[num]++;
    }
    for(int i = 10; i >= 1; i--)
    //如果想改成从小到大输出
    //for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; a[i] >= j; j++)
            printf("%d ", i);
    }
    return 0;
}
