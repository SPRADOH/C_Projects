#include<stdio.h>
#include<stdlib.h>


int max(int arr[], int x)
{
    int max=arr[0];
    for (int i = 1; i < x; i++)
    {
        if (max<arr[i])
        {
            max=arr[i];
        }
        
    }
    return max;  //returns the biggest member of the array
}

int removeDupl_freq_count(int arr[], int x)
{
    if (x==0) return 0;

    int m=max(arr,x)+1;
    int* f= (int*)malloc(sizeof(int) * m);  // int* means that the point points only to integers. malloc() creates an space for m integers.

    int j=0;
    for (int  i = 0; i < x; i++)
    {
        if (f[arr[i]]==0)
        {
            arr[j++]=arr[i];
            f[arr[i]]=1;
        }
        
    }
    free(f)

    return j;
}

int main()
{
    
}