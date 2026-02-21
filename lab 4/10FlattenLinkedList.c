#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* down;
};

void print(struct Node* head)
{
    if(head==NULL)
    {
        return;
    }
    struct Node* y=head;
    printf("%d : ",y->data);
    y=y->down;
    while(y!=NULL)
    {
        printf("%d -> ",y->data);
        y=y->down;
    }
    printf("NULL\n");
    print(head->next);
}

struct Node* CreateList(int n)//create list fun recursion
{
    struct Node* head=NULL;
    struct Node* current=NULL;
    current=(struct Node*)malloc(sizeof(struct Node));
    if(n==0)
    {
        return NULL;
    }
    printf("Data %d : ",n);
    scanf("%d",&current->data);
    head=CreateList(n-1);
    struct Node* x=head;
    current->next=head;
    return current;
}

struct Node* CreateFlatList(int n)//create list fun recursion
{
    struct Node* head=NULL;
    struct Node* current=NULL;
    current=(struct Node*)malloc(sizeof(struct Node));
    if(n==0)
    {
        return NULL;
    }
    printf("Data %d : ",n);
    scanf("%d",&current->data);
    head=CreateFlatList(n-1);
    struct Node* x=head;
    current->down=head;
    return current;
}

int main() 
{
    struct Node* head;
    printf("Enter number of node\n");
    int n;
    scanf("%d",&n);

    head=CreateList(n);
    struct Node* x=head;
    printf("Straight List ");

    while(x!=NULL)
    {
        
        printf("%d ",x->data);
        x=x->next;
    }
    struct Node* y=head;
    printf("\n");
    while(y!=NULL)
    {
        printf("\nEnter nuber of flat node ");
        scanf("%d",&n);
        y->down=CreateFlatList(n);
        x=y->down;
        printf("Flat list -> ");
        while(x!=NULL)
        {
            printf("%d ",x->data);
            x=x->down;
        }
        y=y->next;
    }
    printf("\n");
    print(head);
}