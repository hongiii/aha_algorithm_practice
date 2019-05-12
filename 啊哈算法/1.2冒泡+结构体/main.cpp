//输入姓名和分数，按照分数从高到低排序，输出相应的姓名
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct student
{
    char name[10];
    int grade;
};

int main()
{
    int n;
    student s[10];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s%d", s[i].name, &s[i].grade);
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            student tmp;
            if(s[j].grade < s[j+1].grade)
            {
                tmp = s[j];
                s[j] = s[j+1];
                s[j+1] = tmp;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", s[i].name);
    }
    return 0;
}
