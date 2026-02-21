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
    int k;
    printf("Enter number of List");
    scanf("%d",&k);
    struct Node* heads[k];
    struct Node* mergedHead = NULL;
    for(int i=0;i<k;i++)
    {
        printf("Enter number of Node (List %d)\n",i+1);
        int n;
        scanf("%d",&n);
        heads[i]=CreateList(n);
        struct Node* x=heads[i];
        printf("Original List %d: ",i+1);
        while(x!=NULL)
        {
            printf("%d ",x->data);
            x=x->next;
        }
        mergedHead = MergeTwoSortedLists(mergedHead, heads[i]);
        printf("\n");
    }
    printf("Merged Sorted List: ");
    struct Node* x=mergedHead;
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->next;
    }

    
}