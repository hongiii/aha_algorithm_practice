//³öÕ» top--
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char p[101], q[101];
    int len, next;
    gets(p);

    len = strlen(p);
    int mid = len/2;
    int top = 0;
    for(int i = 0; i < mid; i++)
        q[top++] = p[i];

    //printf("%d\n", top);

    if(len%2)
        next = mid+1;
    else
        next = mid;
    for(int i = next; i < len; i++)
    {
        if(p[i] != q[--top])
            break;
      //  top--;
    }
    printf("%d\n", top);
    if(top == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
