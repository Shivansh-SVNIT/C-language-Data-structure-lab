#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

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

int commonElement(struct Node* head1, struct Node* head2)
{
    struct Node* x=head1;
    while(x!=NULL)
    {
        struct Node* y=head2;
        while(y!=NULL)
        {
            if(x->data==y->data)
            {
                return x->data;
            }
            y=y->next;
        }
        x=x->next;
    }
    printf("No common element found\n");
    return -1;
}

int main()
{
    struct Node* head1;
    printf("Enter number of Node (List 1)\n");
    int n;
    scanf("%d",&n);
    head1=CreateList(n);
    struct Node* x=head1;
    printf("Original List 1: ");
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->next;
    }

    struct Node* head2;
    printf("Enter number of Node (List 2)\n");
    scanf("%d",&n);
    head2=CreateList(n);
    x=head2;
    printf("Original List 2: ");
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->next;
    }
    int common=commonElement(head1, head2);
    if(common!=-1)
    {
        printf("\nCommon element is %d\n", common);
    }
}