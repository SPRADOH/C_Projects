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

void merge(int arr[], int left, int mid, int right)
{
    int i,j,k,n1,n2;
    n1=mid-left+1;
    n2=right-mid;

    int left_arr[n1];
    int right_arr[n2];

    for ( i = 0; i < n1; i++)
    {
        left_arr[i]=arr[left+i];
    }
    
    for ( j = 0; j < n2; j++)
    {
        right_arr[j]=arr[mid+1+j];
    }

    i=0;
    j=0;
    k=left;
    
    while (i<n1&&j<n2)
    {
        if (left_arr[i]<=right_arr[j])
        {
            arr[k]=left_arr[i];
            i++;
        }

        else
        {
            arr[k]=right_arr[j];
            j++;
        }
        k++;
        
    }

    while (i<n1)
    {
        arr[k]=left_arr[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        arr[k]=right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left<right)
    {
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);        
    }

}

int main()
{
    int x;
    printf("\nHow many elements does your array have? ");
    scanf("%d",&x);
    
    int arr[x];

    getMembers(x,arr);
    printf("\nunsorted array:\t");
    printArray(x,arr);

    printf("\n\nSorted array:\t");
    mergeSort(arr,0,x-1);
    printArray(x,arr);

    return 0;
}