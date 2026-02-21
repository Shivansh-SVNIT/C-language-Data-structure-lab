#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* random;
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
    struct Node* head;
    srand(time(NULL));
    printf("Creating 10 Nodes..\n");
    head=CreateList(10);
    
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    
    for(int i=0;i<8;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(rand()%2)
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    struct Node* x=NULL;
    struct Node* Random=NULL;
    
    for(int i=0;i<10;i++)
    {
        struct Node* y=head;
        for(int j=0;j<arr[i];j++)
        {
            y=y->next;
        }
        if(x==NULL)
        {
            x=y;
            Random=x;
        }
        else
        {
            x->random=y;
            x=x->random;
        }
    }
    
    x=Random;
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->random;
    }

}