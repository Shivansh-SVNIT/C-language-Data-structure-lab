#include<stdio.h>

void main()
{
    int n,sum=0,key;
    printf("Enter value of N : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements  \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int max=arr[0],min=arr[0];

    for (int i = 1; i < n; i++) { max=max>arr[i]?max:arr[i]; }//max
    for (int i = 1; i < n; i++) { min=min<arr[i]?min:arr[i]; }//min

    printf("max and min is %d %d\n",max,min);//printing maax and min

    for(int i = 0; i < n; i++) { sum+=arr[i]; }
    printf("avg is %f\n",(float)sum/n);//avg
    
    printf("Enter key \n");
    scanf("%d",&key);

    for (int i = 0; i < n; i++)
    {
        if(key==arr[i])
        {
            printf("Element is found and index is %d",i);
            return;
        }
    }

    printf("Element is not found");

    
}