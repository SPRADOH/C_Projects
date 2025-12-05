#include<stdio.h>

void take_members(int x, int y, int arr[][y])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("Matrix[%d][%d]: ",i,j);
            scanf(" %d",&arr[i][j]);
        }
        
    }
    
}

void print_array(int x, int y, int arr[][y])
{
    for (int i = 0; i < x; i++)
    {
        printf("\n");
        for (int j = 0; j < y; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        
    }
    
}

int main()
{
    int x;
    printf("Enter number of rows and columns of your matrix\nNote that determinant is only possible with square matrices i.e matrices with equal number of rows and columns: ");
    scanf(" %d",&x);

    int matrix[x][x];

    take_members(x,x,matrix);
    print_array(x,x,matrix);

    int det=0;
    //calculating the determinant
    if (x==2)
    {
        for (int i = 0)
        {
            for (int j = 0; j < x; j++)
            {
                    
            }
            
        }
        
    }
    


}