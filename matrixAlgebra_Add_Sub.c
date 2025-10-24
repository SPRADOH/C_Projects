#include<stdio.h>

void print_array(int arr[], int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("%d\t",arr[i]);
    }
}

void result_add(int arr1[], int arr2[], int x)
{
    int result[x];
    for (int i = 0; i < x; i++)
    {
        result[i]=arr1[i]+arr2[i];
    }
    printf("Arr_A %c Arr_B:\t",'+');
    print_array(result,x);
}

void result_sub(int arr1[], int arr2[], int x)
{
    int result[x];
    for (int i = 0; i < x; i++)
    {
        result[i]=arr1[i]-arr2[i];
    }
    printf("Arr_A %c Arr_B:\t",'-');
    print_array(result,x);
}

int main()
{
    int x,y;
    printf("How many elements does your first array have? ");
    scanf("%d",&x);
    printf("How many elements does your second array have? ");
    scanf("%d",&y);
    int arr_A[x];
    int arr_B[y];

    if (x==y)
    {
        //Get members of The first Array
        printf("\nInput member elements\n");
        for (int i = 0; i < x; i++)
        {
            printf("Arr_A[%d]: ",i+1);
            scanf("%d",&arr_A[i]);
        }
        printf("\n");
        //Get members of the second array
        for (int i = 0; i < y; i++)
        {
            printf("Arr_B[%d]: ",i+1);
            scanf("%d",&arr_B[i]);
        }

        printf("\n\nArray_A:\t");
        print_array(arr_A,x);

        printf("\nArray_B:\t");
        print_array(arr_B,y);

        char operation;

        printf("\n\nWhich operation do you want to carry out??\nEnter A for Addition and S for subtraction: ");
        scanf(" %c",&operation);
        printf("\n\n");
        if (operation=='A'||operation=='a')
        {
            result_add(arr_A,arr_B,x);
        }
        
        else if (operation=='S'||operation=='s')
        {
            result_sub(arr_A,arr_B,x);
        }

        else
        {
            printf("Error: Operation not within range of operations");
        }
        
        

    }
    
    else
    {
        printf("Error: operation not possible");
    }
    

    return 0;
}