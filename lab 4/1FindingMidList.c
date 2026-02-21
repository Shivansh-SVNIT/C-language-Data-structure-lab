#include<stdio.h>

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
void Middle(struct Node* head)
{
    int l=0;
    struct Node* x=head;
    while(x!=NULL)
    {
        x=x->next;
        l++;
    }
    if(l%2==0)
    {
        printf("Middle Element does not exits\n");
    }
    else
    {
        x=head;
        for(int i=0;i<l/2;i++)
        {
            x=x->next;
        }
        printf("middle element is %d",x->data);

    }

}

int main() 
{
    
    struct Node* head;
    printf("Enter n\n");
    int n;
    scanf("%d",&n);

    head=CreateList(n);
    Middle(head);

}