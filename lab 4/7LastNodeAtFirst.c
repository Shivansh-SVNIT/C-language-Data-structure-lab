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

struct Node* MoveLastToFront(struct Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node* x = NULL;
    struct Node* y = head;
    while (y->next != NULL)
    {
        x = y;
        y = y->next;
    }
    x->next = NULL;
    y->next = head;
    head = y;
    return head;
}

int main()
{
    struct Node* head;
    printf("Enter number of Node\n");
    int n;
    scanf("%d",&n);
    head=CreateList(n);
    struct Node* x;
    x=head;
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->next;
    }
    head=MoveLastToFront(head);
    x=head;
    printf("\n");
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->next;
    }
    
}