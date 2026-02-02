#include<stdio.h>
#include<stdlib.h>
#include <time.h>

struct Node 
{
    int data;
    struct Node* next;
};

void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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

struct Node* insertAtHead(struct Node* head)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("Enter data to insert at head: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

struct Node* insertAtTail(struct Node* head)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("Enter data to insert at Tail: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void Search(struct Node* head)
{
    if(head == NULL)//zero node
    {
        printf("List is empty\n");
    }
    
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Value %d found in the list\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list\n", value);
}

void reverse(struct Node* x)
{
    
    int left=1,right=0;
    struct Node* temp=x;
    while(temp!=NULL)
    {
        right++;
        temp=temp->next;
    }
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


struct Node* DeleteByValue(struct Node* head)
{
    if(head == NULL)//zero node
    {
        printf("List is empty\n");
        return head;
    }
    
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);
    if(head->next == NULL)//single node
    {
        if(head->data==value)
        {
            return NULL;
        }
        else
        {
            printf("Value not found\n");
            return head;
        }
    }

    struct Node* x = head;
    struct Node* y = head->next;
    while(y != NULL)
    {
        if(y->data == value)
        {
            x->next = y->next;
            return head;
        }
        x = y;
        y = y->next;
    }
    printf("Value not found\n");
    return head;

}

struct Node* DeleteAtPosition(struct Node* head)
{
    if(head == NULL)//zero node
    {
        printf("List is empty\n");
        return head;
    }
    
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);
    
    if(head->next == NULL)//single node
    {
        return NULL;
    }
    
    struct Node* x = head;
    for(int i=0;i<position-1;i++)
    {
        x = x->next;
    }
    x->next = x->next->next;
    return head;
}

struct Node* DeectCycle(struct Node* head)
{
    struct Node* fast=head;
    struct Node* slow=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    
    while(1)
    {
        if(fast->next==NULL || fast->next->next==NULL)
        {
            printf("Cyecle Not found\n");
            return head;
        }
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        { 
            printf("Cycle Found\n");
            break;
        }
    }

}



int main()
{
    struct Node* head=NULL;
    srand(time(NULL));   // seed the random generator
    int p=rand()%20;
    printf("Creating list with %d nodes\n",p);
    head=CreateList(p);
    struct Node* temp=head;
    printf("Original List: ");
    printList(temp);

    while(1)
    {
        printf("Choose an operation:\n1. Insert at Head\n2. Insert at Tail\n3. Search\n4. Reverse\n5. Delete by Value\n6. Delete at Position\n7. Detect Cycle\n8. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                head = insertAtHead(head);
                break;
            case 2:
                head = insertAtTail(head);
                break;
            case 3:
                Search(head);
                break;
            case 4:
                reverse(head);
                break;
            case 5:
                head = DeleteByValue(head);
                break;
            case 6:
                head = DeleteAtPosition(head);
                break;
            case 7:
                head = DeectCycle(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("Updated List: ");
        printList(head);
    }
}