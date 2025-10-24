#include<stdio.h>
void print_Array(int x,int y, int arr[][y])
{
    for (int i=0;i<x;i++)
    {
        printf("\n");
        for (int j = 0; j < y; j++)
        {
            printf("%d\t",arr[i][j]);
            
        }
        
    }
}

void get_Elements(int x,int y,int arr[][y], char alpha)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("Mat_%c[%d][%d]: ", alpha,i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
        
    }
    
}

int main()
{
    int a,b,c,d;
    printf("How many rows and column does your first matrix have? ");
    scanf(" %d%d",&a,&b);
    printf("\nHow many rows and column does your second matrix have? ");
    scanf(" %d%d",&c,&d);
    
    if (b==c)
    {
        int mat_A[a][b];
        int mat_B[c][d];
        int res[a][d];
        char alpha='A',beta='B';

        printf("Input member elements\nMat_A:\n");
        get_Elements(a,b,mat_A,alpha);
        printf("Input member elements\nMat_B:\n");
        get_Elements(c,d,mat_B,beta);

        printf("Mat_A:\t");
        print_Array(a,b,mat_A);
        printf("\n\nMat_B:\t");
        print_Array(c,d,mat_B);

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < d; j++)
            {
               res[i][j]=0;
            }
            
        }

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < d; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    res[i][j]+=mat_A[i][k]*mat_B[k][j];
                }
                
            }
            
        }
        printf("\n\nMat_A x Mat_B:\t");
        print_Array(a,d,res);
    }

    else
    {
        printf("Error: The number of columms of first array must match with the number of rows of the second matrix");
    }
    
    

    return 0;
}