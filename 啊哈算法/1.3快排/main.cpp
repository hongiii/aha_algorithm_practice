//���ŵĻ���˼�룺������Ҫ���ڶ��ֵ�˼�룬�������˻�׼ֵ�������ڱ�����������ڱ��������ң��ұ��ڱ���������
//����Ǵ�С���������ұߵ��ڱ��ҵ��Ȼ�׼ֵС����ͣ����������ҵ��Ȼ�׼ֵ�����ͣ��������������ڱ�û���������ͽ�������������
//�ظ��������裬ֱ�������ڱ���������ʱͣ����������׼ֵ��λ��ʹ�û�׼ֵ��ߵ�����С�ڻ�׼ֵ���ұ߶����ڻ�׼ֵ��
//��ʱ����׼ֵ��ߵ����к��ұߵ����У����Կ���ԭʼ����������⡣
//�ֱ�Ӧ������˼�룬�Ϳ����ź����ˡ�
//�������£�

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
    //��׼ֵ��λ
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
