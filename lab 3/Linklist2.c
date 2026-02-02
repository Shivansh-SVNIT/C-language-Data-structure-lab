#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* insertfront(struct Node *x,int data)
{
    struct Node *y=(struct Node*)malloc(sizeof(struct Node));

    y->data=data;
    y->next=x;
    
    return y;
}

struct Node* undo (struct Node* x)
{
    struct Node *y=x;
    x=x->next;
    y->next=NULL;
    free(y);
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

    s=insertfront(s,10);
    s=insertfront(s,21);
    s=insertfront(s,456789);    
    s=undo(s);

    while(s!=NULL)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    

}

