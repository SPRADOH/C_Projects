#include<stdio.h>

void getMembers(int x, int arr[])
{
    for (int i = 0; i < x; i++)
    {
        printf("Array[%d]: ",i);
        scanf("%d",&arr[i]);
    }
}

void printArray(int x, int arr[])
{
    for (int i = 0; i < x; i++)
    {
        printf("%d\t",arr[i]);
    }
}

void Selection(int x, int arr[])
{
    char sortType;
    int run;

    printf("Which sorting operation do you want to carry out?\nEnter 'A' or 'a' for Ascending and 'D' or 'd' for Descending: ");
    scanf(" %c",&sortType);

    for (int i = 0; i < x-1; i++)
    {
        int minIndex=i;
        for (int j = i+1; j < x; j++)
        {
            if (sortType=='a'||sortType=='A')
            {
                if (arr[minIndex]>arr[j])
                {
                    minIndex=j;
                }
            }

            else if (sortType=='d'||sortType=='D')
            {
                if (arr[minIndex]<arr[j])
                {
                    minIndex=j;
                }
            }
            
            else
            {
                run=1;
            } 
            
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }

    if (run==1)
    {
        Selection(x,arr);
    }
    
    
}

int main()
{
    int x;
    printf("How many elements does your array have?? ");
    scanf("%d",&x);

    int arr[x];

    getMembers(x,arr);
    printf("\n\nunsorted array\t");
    printArray(x,arr);

    printf("\n\nsorted array:\t");
    Selection(x,arr);
    printArray(x,arr);

}