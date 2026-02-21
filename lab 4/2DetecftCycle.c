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

void DetectCycle(struct Node* head)
{
    struct Node* fast=head;
    struct Node* slow=head;
    
    while(1)
    {
        if(fast->next==NULL || fast->next->next==NULL)
        {
            printf("Cyecle Not found\n");
            return;
        }
        fast=fast->next->next;
        if(fast==slow)
        { 
            printf("Cycle Found\n");
            return;
        }
        slow=slow->next;
    }
}

int main()
{
    struct Node* head;
    struct Node* temp;
    struct Node* last;

    printf("Enter n\n");
    int n;
    scanf("%d",&n);
    head=CreateList(n);
    temp=head;
    last=head;
    //create cycle____________randomly__
    while(last->next!=NULL)
    {
        last=last->next;
    }
    printf("Enter at which node you want to make Cycle(0 for no0 cycle)\n");
    int x;
    scanf("%d",&x);
    if(x!=0)
    {
        for(int i=0;i<x-1;i++)
        {
            temp=temp->next;
        }
        last->next=temp;
    }
    else
    {
        last->next=NULL;
    }
    DetectCycle(head);
    
}