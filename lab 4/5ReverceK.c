#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void reverseK(struct Node* x, int k)
{
    int left = 1, right = k;
    struct Node* leftNode = x;

    while (left < right)
    {
        struct Node* rightNode = x;
        for (int i = 0; i < right - 1; i++)
        {
            rightNode = rightNode->next;
        }

        int temp = leftNode->data;
        leftNode->data = rightNode->data;
        rightNode->data = temp;

        left++;
        leftNode = leftNode->next;
        right--;
    }
}

void reverseListK(struct Node* head, int k)
{
    struct Node* curr = head;
    while (curr != NULL)
    {
        
        struct Node* check = curr;
        int count = 0;
        while (check != NULL && count < k)
        {
            check = check->next;
            count++;
        }
        if (count < k)
        {
            return; 
        }
        reverseK(curr, k);
        for (int i = 0; i < k; i++)
        {
            curr = curr->next;
        }
    }
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
    struct Node* head = NULL;
    int n, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = CreateList(n);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("\nOriginal List: ");
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

  
    reverseListK(head, k);

    printf("\nReversed in K groups: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}