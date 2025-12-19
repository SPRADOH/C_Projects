#include<stdio.h>

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
        right_arr[j]=arr[mid+j+1];
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

void merge_sort(int arr[], int left, int right)
{
    if (left<right)
    {
        
    }
    
}