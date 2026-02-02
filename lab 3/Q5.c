#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createList(int n)
{
    struct node* head = NULL;
    struct node* temp = NULL;

    int data;

    for (int i = 0; i < n; i++)
    {
        struct node* x = (struct node*)malloc(sizeof(struct node));
        x->next = NULL;

        printf("Enter data: ");
        scanf("%d", &data);
        x->data = data;

        if (head == NULL)
        {
            head = x;
            temp = head;
        }
        else
        {
            temp->next = x;
            temp = x;
        }
    }
    return head;
}

struct node* deleteKfromEnd(struct node* head, int k)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    struct node* fast = head;
    struct node* slow = head;

    // move fast k steps ahead
    for (int i = 0; i < k; i++)
    {
        if (fast == NULL)
            return head;

        fast = fast->next;
    }

    // if deleting first node
    if (fast == NULL)
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    struct node* del = slow->next;
    slow->next = del->next;
    free(del);

    return head;
}

int main()
{
    struct node* x = createList(5);

    struct node* y = x;
    while (y != NULL)
    {
        printf("%d ", y->data);
        y = y->next;
    }

    printf("\nEnter k (node from last): ");
    int k;
    scanf("%d", &k);

    x = deleteKfromEnd(x, k);

    printf("After deletion:\n");
    y = x;
    while (y != NULL)
    {
        printf("%d ", y->data);
        y = y->next;
    }

    return 0;
}
