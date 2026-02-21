#include<stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int n) 
{
    if(n==0) 
    {
        return NULL;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for the node: ");
    scanf("%d", &newNode->data);
    newNode->next = createNode(n - 1);
    if(n!=1) 
    {
        newNode->next->prev = newNode;
    }
    struct Node* head=newNode;
    return head;
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
    struct Node* y;
    while(current!=NULL && current->next!=NULL)
    {
        temp=current->next;
        x=current;
        y=current;
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
    head=CreateNode(n);
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