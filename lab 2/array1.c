#include<stdio.h>
#include<stdlib.h>

void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void sum(int arr[],int size)
{
    int s=0;
    for(int i=0;i<size;i++)
    {
        s+=arr[i];
    }
    printf("Sum of elements (withot recursion): %d\n",s);
}

int sumRec(int arr[],int size)
{
    if(size==0)
    {
        return 0;
    }
    return (arr[size-1]+sumRec(arr,size-1));
}

int main()
{
    int *arr1,*arr2,*main;
    int a=10,b=10,c=20;
    arr1 = (int *)malloc(10 * sizeof(int));
    arr2 = (int *)malloc(10 * sizeof(int));
    main = (int *)malloc(20 * sizeof(int));

    for(int i=0;i<a;i++)
    {
        arr1[i]=rand()%100;
    }
    for(int j=0;j<b;j++)
    {
        arr2[j]=rand()%100;
    }
    for(int k=0;k<c;k++)
    {
        main[k]=rand()%100;
    }

    for(int i=0;i<a;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    for(int j=0;j<b;j++)
    {
        printf("%d ",arr2[j]);
    }
    printf("\n");
    for(int k=0;k<c;k++)
    {
        printf("%d ",main[k]);
    }
    while(1)
    {
    printf("\n1 Insert End\n2 Insert Begin\n3 Insert Position");
    printf("\n4 Delete End\n5 Delete Begin\n6 Delete Position");
    printf("\n7 Reverse using temp\n8 Reverse in-place");
    printf("\n9 Copy from array 1 to main array\n10 merge two sorted array\n11 Display sum elements");
    printf("\n12 Search the array for a user-given value\n13 Separate the MainArray into sub-arrays");
    printf("\n14 all array print\n0 EXIT\nEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    printf("Enter array number (1,2 or 3)(anyone for case 14,13,10): ");
    int no;
    scanf("%d",&no);
    switch(choice)
    {
        case 1:
            if(no==1)
            {
                int value;
                printf("Enter value to insert at end: ");
                scanf("%d",&value);
                arr1 =(int *)realloc(arr1,(a+1)*sizeof(int));
                *(arr1 + a)=value;
                a++;
                print(arr1,a);
            }
            else if(no==2)
            {
                int value;
                printf("Enter value to insert at end: ");
                scanf("%d",&value);
                arr2 =(int *)realloc(arr2,(b+1)*sizeof(int));
                *(arr2 + b)=value;
                b++;
                print(arr2,b);
            }
            else if(no==3)
            {
                int value;
                printf("Enter value to insert at end: ");
                scanf("%d",&value);
                main =(int *)realloc(main,(c+1)*sizeof(int));
                *(main + c)=value;
                c++;
                print(main,c);
            }break;
        case 2:
            if(no==1)
            {
                int value,temp[a];
                printf("Enter value to insert at begin: ");
                scanf("%d",&value);
                for(int i=0;i<a;i++)
                {
                    temp[i]=arr1[i];
                }
                arr1 =(int *)realloc(arr1,(a+1)*sizeof(int));
                arr1[0]=value;
                for(int i=1;i<=a;i++)
                {
                    arr1[i]=temp[i-1];
                }
                a++;
                print(arr1,a);
            }
            else if(no==2)
            {
                int value,temp[b];
                printf("Enter value to insert at begin: ");
                scanf("%d",&value);
                for(int i=0;i<b;i++)
                {
                    temp[i]=arr2[i];
                }
                arr2 =(int *)realloc(arr2,(b+1)*sizeof(int));
                arr2[0]=value;
                for(int i=1;i<=b;i++)
                {
                    arr2[i]=temp[i-1];
                }
                b++;
                print(arr2,b);
            }
            else if(no==3)
            {
                int value,temp[c];
                printf("Enter value to insert at begin: ");
                scanf("%d",&value);
                for(int i=0;i<c;i++)
                {
                    temp[i]=main[i];
                }
                main =(int *)realloc(main,(c+1)*sizeof(int));
                main[0]=value;
                for(int i=1;i<=c;i++)
                {
                    main[i]=temp[i-1];
                }
                c++;
                print(main,c);
            }break;    
        case 3:
            if(no==1)
            {
                int value,position;
                printf("Enter position to insert(1,2,3..): ");
                scanf("%d",&position);
                printf("Enter value: ",position);
                scanf("%d",&value);
                arr1 =(int *)realloc(arr1,(a+1)*sizeof(int));
                for(int i=a;i>=position;i--)
                {
                    arr1[i]=arr1[i-1];
                }
                print(arr1,a);
            }
            else if(no==2)
            {
                int value,position;
                printf("Enter position to insert: ");
                scanf("%d",&position);
                printf("Enter value to insert at position %d: ",position);
                scanf("%d",&value);
                arr2 =(int *)realloc(arr2,(b+1)*sizeof(int));
                for(int i=b;i>=position;i--)
                {
                    arr2[i]=arr2[i-1];
                }
                arr2[position-1]=value;
                b++;
                print(arr2,b);
            }
            else
            {
                int value,position;
                printf("Enter position to insert: ");
                scanf("%d",&position);
                printf("Enter value to insert at position %d: ",position);
                scanf("%d",&value);
                main =(int *)realloc(main,(c+1)*sizeof(int));
                for(int i=c;i>=position;i--)
                {
                    main[i]=main[i-1];
                }
                main[position-1]=value;
                c++;
                print(main,c);
            }
            break;
        case 4:
            if(no==1)
            {
                a--;
                arr1 =(int *)realloc(arr1,a*sizeof(int));
                print(arr1,a);
            }
            else if(no==2)
            {
                b--;
                arr2 =(int *)realloc(arr2,b*sizeof(int));
                print(arr2,b);
            }
            else if(no==3)
            {
                c--;
                main =(int *)realloc(main,c*sizeof(int));
                print(main,c);
            }break; 
        case 5:
            if(no==1)
            {
                for(int i=0;i<a-1;i++)
                {
                    arr1[i]=arr1[i+1];
                }
                a--;
                arr1 =(int *)realloc(arr1,a*sizeof(int));
                print(arr1,a);
            }
            else if(no==2)
            {
                for(int i=0;i<b-1;i++)
                {
                    arr2[i]=arr2[i+1];
                }
                b--;
                arr2 =(int *)realloc(arr2,b*sizeof(int));
                print(arr2,b);
            }
            else if(no==3)
            {
                for(int i=0;i<c-1;i++)
                {
                    main[i]=main[i+1];
                }
                c--;
                main =(int *)realloc(main,c*sizeof(int));
                print(main,c);
            }break;            
        case 6:
            if(no==1)
            {
                int position;
                printf("Enter position to delete(1,2,3..): ");
                scanf("%d",&position);
                for(int i=position-1;i<a-1;i++)
                {
                    arr1[i]=arr1[i+1];
                }
                arr1=(int*)realloc(arr1,(a-1)*sizeof(int));
                a--;
                print(arr1,a);
            }
            else if(no==2)
            {
                int position;
                printf("Enter position to delete(1,2,3..): ");
                scanf("%d",&position);
                for(int i=position-1;i<b-1;i++)
                {
                    arr2[i]=arr2[i+1];
                }
                arr2=(int*)realloc(arr2,(b-1)*sizeof(int));
                b--;
                print(arr2,b);
            }
            else if(no==3)
            {
                int position;
                printf("Enter position to delete(1,2,3..): ");
                scanf("%d",&position);
                for(int i=position-1;i<c-1;i++)
                {
                    main[i]=main[i+1];
                }
                main=(int*)realloc(main,(c-1)*sizeof(int));
                c--;
                print(main,c);
            }break;
        case 7:
            if(no==1)
            {
                int temp[a];
                for(int i=0;i<a;i++)
                {
                    temp[i]=arr1[a-i-1];
                }
                for (int i = 0; i < a; i++)
                {
                    arr1[i]=temp[i];
                }
                print(arr1,a); 
            }
            else if(no==2)
            {
                int temp[b];
                for(int i=0;i<b;i++)
                {
                    temp[i]=arr2[b-i-1];
                }
                for (int i = 0; i < b; i++)
                {
                    arr2[i]=temp[i];
                }
                print(arr2,b); 
            }
            else if(no==3)
            {
                int temp[c];
                for(int i=0;i<c;i++)
                {
                    temp[i]=main[c-i-1];
                }
                for (int i = 0; i < c; i++)
                {
                    main[i]=temp[i];
                }
                print(main,c);
            }break;
        case 8:
            if(no==1)
            {
                int low=0,high=a-1,temp;
                while(low<high)
                {
                    temp=arr1[low];
                    arr1[low]=arr1[high];
                    arr1[high]=temp;
                    low++;
                    high--;
                }
                print(arr1,a);
            }
            else if(no==2)
            {
                int low=0,high=b-1,temp;
                while(low<high)
                {
                    temp=arr2[low];
                    arr2[low]=arr2[high];
                    arr2[high]=temp;
                    low++;
                    high--;
                }
                print(arr2,b);
            }
            else if(no==3)
            {
                int low=0,high=c-1,temp;
                while(low<high)
                {
                    temp=main[low];
                    main[low]=main[high];
                    main[high]=temp;
                    low++;
                    high--;
                }
                print(main,c);
            }break;
        case 9:
            if(no==1)
            {
                for(int i=0;i<a && i<c;i++)
                {
                    main[i]=arr1[i];
                }
                print(main,c);
            }
            else if(no==2)
            {
                for(int i=0;i<b && i<c;i++)
                {
                    main[i]=arr2[i];
                }
                print(main,c);
            }    
            else
            {
                printf("Cannot copy from main array to main array.\n");
            }break;
        case 10:
            if(no==1 || no==2 || no==3)
            {
                printf("Array 1 & 2 are now sorted in decreasing order");
                for (int i = a; i > 0; i--)
                {
                    for (int j = a-1; j >=0; j--)
                    {
                        if (arr1[i] > arr1[j])
                        {
                            int temp = arr1[j];
                            arr1[j] = arr1[j - 1];
                            arr1[j - 1] = temp;
                        }
                    }
                }
                for (int i = b; i > 0; i--)
                {
                    for (int j = b-1; j >=0; j--)
                    {
                        if (arr2[i] > arr2[j])
                        {
                            int temp = arr2[j];
                            arr2[j] = arr2[j - 1];
                            arr2[j - 1] = temp;
                        }
                    }
                }
                int i=0,j=0,k=0;
                while(k<c)
                {
                    if(arr1[i]<arr2[j])
                    {
                        main[k]=arr2[j];
                        j++;
                        k++;
                    }
                    else
                    {
                        main[k]=arr1[i];
                        i++;
                        k++;
                    }

                }
                print(main,c);
            }break;
        case 11:
            if(no==1)
            {
                sum(arr1,a);
            }
            else if(no==2)
            {
                sum(arr2,b);
            }
            else if(no==3)
            {
                printf("Sum of elements (with recursion): %d\n",sumRec(main,c));
            }break;
        case 12:
            if(no==1)
            {
                int value,found=0;
                printf("Enter value to search: ");
                scanf("%d",&value);
                for(int i=0;i<a;i++)
                {
                    if(arr1[i]==value)
                    {
                        printf("Element %d found at position %d in array 1\n",value,i+1);
                        found=1;
                        break;
                    }
                }
                if(!found)
                {
                    printf("Element %d not found in array 1\n",value);
                }
            }
            else if(no==2)
            {
                int value,found=0;
                printf("Enter value to search: ");
                scanf("%d",&value);
                for(int i=0;i<b;i++)
                {
                    if(arr2[i]==value)
                    {
                        printf("Element %d found at position %d in array 2\n",value,i+1);
                        found=1;
                        break;
                    }
                }
                if(!found)
                {
                    printf("Element %d not found in array 2\n",value);
                }
            }
            else if(no==3)
            {
                int value,found=0;
                printf("Enter value to search: ");
                scanf("%d",&value);
                for(int i=0;i<c;i++)
                {
                    if(main[i]==value)
                    {
                        printf("Element %d found at position %d in main array\n",value,i+1);
                        found=1;
                        break;
                    }
                }
                if(!found)
                {
                    printf("Element %d not found in main array\n",value);
                }
            }break;
        case 13:

        printf("\n1 odd even\n2 ");
        printf("positive negative\n");
        int x;
        scanf("%d",&x);
        if(x==1){
            int odd=0,even=0;
            for (int i = 0; i < c; i++)
            {
                if(main[i]%2==0)
                {
                    even++;
                }
                else
                {
                    odd++;
                }
            }
            a=odd;
            b=even;
            arr1=(int *)malloc(even*sizeof(int));
            arr2=(int *)malloc(odd*sizeof(int));
            int e=0,o=0;
            for (int i = 0; i < c; i++)
            {
                if(main[i]%2==0)
                {
                    arr1[e]=main[i];
                    e++;
                }
                else
                {
                    arr2[o]=main[i];
                    o++;
                }
            }
            printf("Even elements array 1: ");
            print(arr1,even);
            printf("\nOdd elements array 2: ");
            print(arr2,odd);
            break;
        }
        else if(x==2){
            int positive=0,negative=0;
            for (int i = 0; i < c; i++)
            {
                if(main[i]>=0)
                {
                    positive++;
                }
                else
                {
                    negative++;
                }
            }
            a=positive;
            b=negative;
            arr1=(int *)malloc(positive*sizeof(int));
            arr2=(int *)malloc(negative*sizeof(int));
            int p=0,n=0;
            for (int i = 0; i < c; i++)
            {
                if(main[i]>=0)
                {
                    arr1[p]=main[i];
                    p++;
                }
                else
                {
                    arr2[n]=main[i];
                    n++;
                }
            }
            printf("Positive elements array 1: ");
            print(arr1,positive);
            printf("\nNegative elements array 2: ");
            print(arr2,negative);
            break;
        }
        break;

        case 14:
            printf("Array 1: ");
            print(arr1,a);
            printf("Array 2: ");
            print(arr2,b);
            printf("Main Array: ");
            print(main,c);
            break;

        case 0:
            exit(0);
            break;
    }
    }
}
