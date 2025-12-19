#include<stdio.h>

void merge(int arr_A[], int arr_B[], int arr[])
{
    int a, b, x, i, j;

    while (i<a&&j<b)
    {
        if (arr_A[i]<arr_B[j])
        {
            arr[x]=arr_A[i];
            i++;
        }

        else
        {
            arr[x]=arr_B[j];
            j++;
        }
        x++;
    }

    while (i<a)
    {
        arr[x]=arr_A[i];
        i++;
        x++;
    }
    
    while (j<b)
    {
        arr[x]=arr_B[j];
        j++;
        x++;
    }    
    
}

void array_print(int arr[], int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("%d\t",arr[i]);
    }
    
}

void get_mem(int arr[], int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("Array[%d]: ", i);
        scanf("%d",&arr[i]);
    }
    
}

int main()
{
    int a,b,x;

    printf("How many elements does your first array have? ");
    scanf("%d",&a);

    int arr_A[a];
    get_mem(arr_A,a);

    printf("\nHow many elements does your second array have? ");
    scanf("%d",&b);
    
    int arr_B[b];
    get_mem(arr_B,b);

    printf("\nArr_A:\t");
    array_print(arr_A,a);

    printf("\n\nArr_B:\t");
    array_print(arr_B,b);

    x=a+b;
    int arr[x];

    merge(arr_A,arr_B,arr);
    printf("\n\nCombined array\nArr:\t");
    array_print(arr,x);
}