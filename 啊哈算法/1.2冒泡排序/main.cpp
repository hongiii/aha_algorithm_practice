//ð������Ļ���˼�룺ÿ�αȽ����ڵ�����Ԫ�أ����˳�����Ͱ����ǽ���������
//����һ����������12 35 99 18 76������Ǵ�С��������
//��һ�ˣ�12 35 18 76 | 99
//�ڶ��ˣ�12 18 35 | 76 99
//�����ˣ�12 18 | 35 76 99
//�����ˣ�12 | 18 35 76 99
//���Ӷ�O(N*N)

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
            if(a[j] > a[j+1]) //��С����
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}
