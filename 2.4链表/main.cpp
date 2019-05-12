#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct node
{
    int data;
    node *next;
};

int main()
{
    node *head, *p, *q;
    //p = (node*)malloc(sizeof(node));
    int num;
    int n;
    head = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        p = (node*)malloc(sizeof(node));
        p->data = num;
        p->next = NULL;
        if(head == NULL)
            head = p;
        else
            q->next = p;
        q = p;
       // free(p);
    }
    node *t = head;

    scanf("%d", &num);
    t = head;
    while(t != NULL)
    {
        if(t->next == NULL || t->next->data > num)
        {
            p = (node*)malloc(sizeof(node));
            p->data = num;
            p->next = t->next;
            t->next = p;
            break;
        }
        t = t->next;
    }
    free(p);
    t = head;
    while(t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }

    return 0;
}
