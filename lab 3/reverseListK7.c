#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void reverseK(struct Node* x,int k)//reverse k linked list
{
    int left=1,right=k;
    struct Node* leftNode=x;
    while(left<right)
    {
        struct Node* rightNode=x;
        for(int i=0;i<right-1;i++)
        {
            rightNode=rightNode->next;
        }
        int temp=leftNode->data;
        leftNode->data=rightNode->data;
        rightNode->data=temp;
        left++;
        leftNode=leftNode->next;
        right--;
    }
    return;
}

void reverseListK(struct Node* head,int k)//reverse list in k groups
{
    
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

int main() 
{
    struct Node* head=NULL;
    int n,k;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    head=CreateList(n);
    printf("Enter k: ");
    scanf("%d",&k);
    struct Node* temp=head;
    printf("Original List: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }




    
}