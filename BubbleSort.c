#include<stdio.h>

void getMembers(int x, int arr[])
{
    for (int i = 0; i < x; i++)
    {
        printf("Array [%d]: ", i+1);
        scanf("%d",&arr[i]);
    }
    
}

void printArray(int x, int arr[])
{
    for ( int i=0; i<x; i++)
    {
        printf("%d\t",arr[i]);
    }
}

void ascSwap(int x, int arr[])
{
    int swap;
    for (int i = 0; i < x ; i++)
    {
        for (int j = 0; j < x-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
            
        }
        
        
    }
}

void DesSwap(int x, int arr[])
{
    int swap;
    for (int i = 0; i < x ; i++)
    {
        for (int j = 0; j < x-1; j++)
        {
            if (arr[j]<arr[j+1])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
            
        }
        
        
    }
}


int main()
{
    int x;
    int arr[x];

    printf("Enter number of elements your array has: ");
    scanf("%d",&x);

    printf("Enter your Elements in any order:\n\n");
    getMembers(x,arr);
    
    printf("Array:\t");
    printArray(x,arr);

    printf("\n\nSorted Array:\n");
    
    ascSwap(x,arr);
    printf("Ascending order:\t");
    printArray(x,arr);

    DesSwap(x,arr);
    printf("\n\nDescending order:\t");
    printArray(x,arr);


    return 0;
}