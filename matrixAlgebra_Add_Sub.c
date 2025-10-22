#include<stdio.h>

void printArray(int arr[], int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("%d\t",arr[i]);
    }
    
}
int main()
{
    int x,y;
    printf("How many elements are in your first array? ");
    scanf("%d",&x);
    printf("How many elements are in your second array? ");
    scanf("%d",&y);
    if (x!=y)
    {
        printf("Error: Array Algebra not possible");
    }
    else
    {
        int Arr_0[y];
        int Arr_1[x];
        int Arr_Result[x];

        printf("\n\nEnter your Elements\n\n");
        for (int i = 0; i < x; i++)
            {
                printf("Arr_0[%d]: ",i);
                scanf("%d",&Arr_0[i]);
            }
        printf("Arr_0:\t");
        printArray(Arr_0,x);
        printf("\n\n");
        for (int i = 0; i < y; i++)
            {
                printf("Arr_1[%d]: ",i);
                scanf("%d",&Arr_1[i]);
            }
        printf("\n\nArr_1:\t");
        printArray(Arr_1,x);
        for (int i = 0; i < x; i++)
            {
                Arr_Result[i]=Arr_0[i]+Arr_1[i];
            }
        printf("\n\nArr_result:\t");
        printArray(Arr_Result,x);
    
    }
}
