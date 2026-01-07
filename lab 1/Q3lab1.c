#include<stdio.h>

int main()
{
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};//row
    printf("Enter elements of matrix");
    
    printf("elements of matrix 1\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }

    printf("address matrix 1\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ",&arr[i][j]);
        }
        printf("\n");
    }
    
    int arr2[3][3]={{1,4,7},{2,5,8},{3,8,9}};

    printf("elements of matrix 2\n");//colum
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ",arr2[i][j]);
        }
        printf("\n");
    }

    printf("address matrix 2\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ",&arr2[i][j]);
        }
        printf("\n");
    }
    
}