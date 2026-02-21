#include<stdio.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
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

struct Node* RemoveDuplicates(struct Node* head)
{
    struct Node* current = head;
    if(current == NULL)
    {
        return head;
    }
    if(current->next == NULL)
    {
        return head;
    }
    struct Node* temp;
    struct Node* x;
    while(current!=NULL && current->next!=NULL)
    {
        temp=current->next;
        x=current;
        while (temp!=NULL)
        {
            if(current->data==temp->data)
            {
                x->next=temp->next;
                temp=x->next;
            }
            else
            {
                temp=temp->next;
                x=x->next;
            }   
        }
        current=current->next;
    }
    return head;
}

int main() 
{
    struct Node* head;
    printf("Enter number of Node\n");
    int n;
    scanf("%d",&n);
    head=CreateList(n);
    struct Node* x=head;
    printf("Original List: ");
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->next;
    }
    head=RemoveDuplicates(head);
    x=head;
    printf("\nList after removing duplicates: ");
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->next;
    }

}