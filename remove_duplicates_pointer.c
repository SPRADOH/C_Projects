//Pointer method to remove duplicates in arrays only works on sorted arrays, so if it is not sorted you have to sort first using either bubble, selection, insertion or merge sort
#include<stdio.h>

void merge(int arr[], int  left, int mid, int right)
{
    int i, j, k, n1, n2;
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

    i=0,j=0,k=left;

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
        int mid;
        mid=left+(right-left)/2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);

    }
    
}

int remove_duplicate(int arr[], int x)
{
    if (x==0)
    {
        return 0;
    }

    else
    {
        int j=0;

        for (int i = 1; i < x; i++)
        {
            if (arr[i]!=arr[j])
            {
                j++;
                arr[j]=arr[i];
            }
               
        }
        return j+1;
    }
    
       
}

void getMembers(int arr[], int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("X[%d]: ", i);
        scanf("%d",&arr[i]);
    }
}

void prt_arr(int arr[], int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("%d\t", arr[i]);
    }
    
}

int main(void)
{
    int x;
    
    printf("How many members does your array has: ");
    scanf("%d",&x);

    int arr[x];

    getMembers(arr,x);

    printf("Your array:\t");
    prt_arr(arr,x);

    merge_sort(arr, 0, x-1);
    printf("\n\nYour sorted array:\t");
    prt_arr(arr,x);

    char dupl;
    printf("\n\nDo you wish to remove any duplicates from the sorted array?\nEnter Y or y for 'yes'  and N or n for 'no': ");
    scanf(" %c",&dupl);
    
    if (dupl=='y'||dupl=='Y')
    {
        x=remove_duplicate(arr,x);
        prt_arr(arr,x);
    }
    
    else if (dupl=='n'||dupl=='N')
    {
        printf("Exiting.............................");
    }
    
    
}