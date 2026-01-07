#include<stdio.h>

int main()
{
    int n,m;
    
    printf("Enter order of matrix \n");
    scanf("%d%d",&n,&m);
	
	int mat[n][m],i,j;

    printf("Enter matrix index i(included zero) ,j\n");
    scanf("%d%d",&i,&j);
    
    printf("Actual address is %d\n",&mat[i][j]);
    
    printf("Address from formula is %d\n",(&mat[0][0]+(i*m+j)));
}
