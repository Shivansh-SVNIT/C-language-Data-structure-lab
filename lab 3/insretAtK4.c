#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insert(struct node * x,int d,int p)
{
    struct node* a=x;
    struct node* y=(struct node*)malloc(sizeof(struct node));
    y->data=d;
    if(p==1)
    {
        y->next=x;
        return y;
    }
    else
    {
        for (int i = 0; i < p-2; i++)
        {
            a=a->next;
        }
        y->next=a->next;
        a->next=y;
        return x;
    }
}

struct node* delete(struct node * x,int p)
{
    struct node* a=x;
    if(p==1)
    {
        x=x->next;
        return x;
    }
    else
    {
        for (int i = 0; i < p-2; i++)
        {
            a=a->next;
        }
        a->next=a->next->next;
        return x;
    }
}

void main() 
{
    struct node* a;
    struct node* b;
    struct node* c;
    a=(struct node*)malloc(sizeof(struct node));
    b=(struct node*)malloc(sizeof(struct node));
    c=(struct node*)malloc(sizeof(struct node));
    a->data=10;
    a->next=b;
    b->data=20;
    b->next=c;
    c->data=30;
    c->next=NULL;
    struct node* s;
    struct node* temp;
    s=a;
    temp=s;
    while(temp->next!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);

    int k;
    printf("Enter the position to insert:");
    scanf("%d",&k);
    printf("Enter data to insert:");
    int d;
    scanf("%d",&d);
    s=insert(s,d,k);
    temp=s;

    while(temp->next!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);

    printf("Enter the position to delete:");
    scanf("%d",&k);
    s=delete(s,k);
    temp=s;
    while(temp->next!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}
