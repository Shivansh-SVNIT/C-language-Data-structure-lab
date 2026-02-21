#include <stdio.h>
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

void checkPalindrome(int num)
{
    int original = num;
    int reverse = 0, digit;

    while (num > 0)
    {
        digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }

    if (original == reverse)
        printf("Palindrome number\n");
    else
        printf("Not a palindrome number\n");
}

void ListToNumber(struct Node* head)
{
    int n=0;
    while(head!=NULL)
    {
        n=n*10+(head->data);
        head=head->next;
    }
    checkPalindrome(n);
}

int main()
{
    struct Node* head;
    printf("Enter number of Node\n");
    int n;
    scanf("%d",&n);
    head=CreateList(n);
    ListToNumber(head);
    
}