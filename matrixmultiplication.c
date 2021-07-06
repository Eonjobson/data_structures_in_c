//prod = sum of a[i][k].b[j][k] for k:1 to n
#include<stdio.h>
#include<stdlib.h>
int main()
{ 
    int i,j,k,r1,c1,r2,c2,rr,rc;
    printf("enter number of rows and columns for matrix 1\n");
    scanf("%d%d",&r1,&c1);
    printf("enter number of rows and columns for matrix 2\n");
    scanf("%d%d",&r2,&c2);
    if(r1!=c2)
    {
        printf("\n number of columns of matrix 1 should be equal to rows of matrix 2");
        exit(0);
    }
    rr = r1;
    rc = c2;
    int res[r1][c2];
    int mat1[r1][c1];
    int mat2[r2][c2];
    printf("enter elements of matrix 1:\n");
    for(i=1;i<=r1;i++)
    {
        for(j=1;j<=c1;j++)
        {
            printf("element[%d][%d]: ",i,j);
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("\n");
    printf("enter elements of matrix 2:\n");
    for(i=1;i<=r2;i++)
    {
        for(j=1;j<=c2;j++)
        {
            printf("element[%d][%d]: ",i,j);
            scanf("%d",&mat2[i][j]);
        }
    }
    //multiplied matrix
    for(i=1;i<=rr;i++)
    {
        for(j=1;j<=rc;j++)
        {
            res[i][j]=0;
            for(k=1;k<=rc;k++)
            {
                res[i][j]  += mat1[i][k]*mat2[k][j];
            }
        }
    }
    printf("product matrix is \n");
    for(int i=1;i<=rr;i++)
    {
        for(j=1;j<=rc;j++)
        {
            printf("%d  ",res[i][j]);

        }
        printf("\n");

    }
        



    return 0;
}