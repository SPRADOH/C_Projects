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

void insertion(int x, int arr[])
{
    int key;
    char sort_type;

    printf("Which sorting operation do you want to carry out?\nEnter 'A' or 'a' for Ascending and 'D' or 'd' for Descending: ");
    scanf(" %c",&sort_type);

    for (int i = 1; i < x; i++)
    {
        key=arr[i];
        int j = j-1;

        if (sort_type=='a'||sort_type=='A')
        {
            while (j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j=j-1;
                arr[j+1]=key;
            }    
        }

        else if(sort_type=='d'||sort_type=='D')
        {
            while (j>=0 && arr[j]<key)
            {
                arr[j+1]=arr[j];
                j=i-1;
                arr[j+1]=key;
            }
        }

        
    }
    
}

int main()
{
    int x;
    
    printf("How many elements does your array have? ");
    scanf("%d",&x);

    int arr[x];

    getMembers(x,arr);
    printf("Unsorted array:\t");
    printArray(x,arr);
    printf("\n\n");

    insertion(x,arr);
    printf("Sorted array:\t");
    printArray(x,arr);

    return 0;
}