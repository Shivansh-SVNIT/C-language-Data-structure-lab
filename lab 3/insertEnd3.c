#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* insertend(struct Node *x,int data)
{
    struct Node *y=(struct Node*)malloc(sizeof(struct Node));
    struct Node *temp=x;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=y;
    y->data=data;
    y->next=NULL;
    return x;
}

int main()
{
    struct Node *x;
    x=(struct Node*)malloc(sizeof(struct Node));
    struct Node *y;
    y=(struct Node*)malloc(sizeof(struct Node));
    struct Node *z;
    z=(struct Node*)malloc(sizeof(struct Node));

    x->data=10;
    y->data=20;
    z->data=30;

    x->next=y;
    y->next=z;
    z->next=NULL;
    struct Node *s;
    s=x;

    s=insertend(s,21);


    while(s!=NULL)
    {
        printf("%d ",s->data);  
        s=s->next;
    }
    

}

