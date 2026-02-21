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

struct Node* MergeTwoSortedLists(struct Node* head1, struct Node* head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node* mergedHead = NULL;

    if (head1->data <= head2->data)
    {
        mergedHead = head1;
        mergedHead->next = MergeTwoSortedLists(head1->next, head2);
    }
    else
    {
        mergedHead = head2;
        mergedHead->next = MergeTwoSortedLists(head1, head2->next);
    }

    return mergedHead;
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

    struct Node* mergedHead = MergeTwoSortedLists(head1, head2);
    x = mergedHead;
    printf("\nMerged List: ");
    while (x != NULL)
    {
        printf("%d ", x->data);
        x = x->next;
    }
}