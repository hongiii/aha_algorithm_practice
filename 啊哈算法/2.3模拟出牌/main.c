#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data[10];
    int head;
    int tail;
};

struct stack
{
    int data[10];
    int top;
};

int main()
{
    struct queue q1, q2;
    struct stack s;
    int n, t;
    int book[10];

    q1.head = q2.head = 0;
    q1.tail = q2.tail = 0;
    s.top = 0;
    for(int i = 0; i < 10; i++) book[i] = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }
    //printf("%d %d\n", q1.tail, q2.tail);

    while(q1.head < q1.tail && q2.head < q2.tail)
    {
        //heng start
        t = q1.data[q1.head];

        if(!book[t]) //如果桌面上没有这张牌，就加进来
        {
            q1.head++;
            s.data[++s.top] = t;
            book[t] = 1;
        }
        else
        {  //如果有了，就找相同的牌和中间的牌
            q1.head++;
            q1.data[q1.tail] = t;
            q1.tail++;
            while(s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0;
                q1.data[q1.tail] = s.data[s.top];
                q1.tail++;
                s.top--;
            }
            book[s.data[s.top]] = 0; //t back to q1
            q1.data[q1.tail] = s.data[s.top];
            q1.tail++;
            s.top--;
        }

        int tmp = s.top;
        printf("heng查看桌面上的牌\n");
        while(tmp > 0)
        {
            printf("%d ", s.data[tmp]);
            tmp--;
        }
        printf("\n");

        if(q1.head == q1.tail)
            break;

        t = q2.data[q2.head];

        if(!book[t])
        {
            q2.head++;
            s.data[++s.top] = t;
            book[t] = 1;
        }
        else
        {
            q2.head++;
            q2.data[q2.tail] = t;
            q2.tail++;
            while(s.data[s.top] != t)
            {
                book[s.data[s.top]] = 0;
                q2.data[q2.tail] = s.data[s.top];
                q2.tail++;
                s.top--;
            }
            book[s.data[s.top]] = 0; //t back to q2
            q2.data[q2.tail] = s.data[s.top];
            q2.tail++;
            s.top--;
        }

        tmp = s.top;
        printf("ha查看桌面上的牌\n");
        while(tmp > 0)
        {
            printf("%d ", s.data[tmp]);
            tmp--;
        }
        printf("\n");
    }

    if(q1.head == q1.tail)
    {
        printf("haha WIN\n");
        while(s.top>0)
        {
            for(int i = 1; i <= s.top; i++)
            printf("%d ", s.data[i]);
        }
        printf("--------");
        while(q2.head < q2.tail)
        {
            printf("%d ", q2.data[q2.head++]);
        }
    }

    return 0;
}
