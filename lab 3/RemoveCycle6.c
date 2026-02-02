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

int main()
{
    struct Node* head=NULL;
    struct Node* temp=NULL;
    struct Node* last=NULL;

    head=CreateList(20);

    temp=head;
    last=head;
    //create cycle____________randomly__
    while(last->next!=NULL)
    {
        last=last->next;
    }
    for(int i=0;i<(rand()%20);i++)
    {
        temp=temp->next;
    }
    last->next=temp;
    //__________________________________
    struct Node* fast=head;
    struct Node* slow=head;
    
    while(1)
    {
        if(fast->next==NULL || fast->next->next==NULL)
        {
            printf("Cyecle Not found\n");
            return  0;
        }
        fast=fast->next->next;
        if(fast==slow)
        { 
            printf("Cycle Found\n");
            break;
        }
        slow=slow->next;
    }
    slow=head;
    int flag=1;
    while(flag)
    {
        if(slow==fast)
        {
            while(flag)
            {
                fast=fast->next;
                if(fast->next==slow)
                {
                    fast->next=NULL;
                    flag=0;
                }
            }
        }
        slow=slow->next;
        fast=fast->next;
    }

    slow=head;
    while(slow!=NULL)
    {
        printf("%d ",slow->data);
        slow=slow->next;
    }
}