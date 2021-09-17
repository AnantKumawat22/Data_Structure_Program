#include <stdio.h>
#include <conio.h>

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int n)
{
    int i, j, temp, flag;
    for(i = 0; i < n - 1; i++)
    {
        flag = 0;
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1; 
            }
        }
        if(flag == 0)
        {
            return;
        }
    }
}

void main()
{
    int arr[100], n, i;
    printf("Enter number of array you want to enter in the array.");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        printf("Enter value at arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    printf("Original array:\n");
    printArray(arr, n);

    bubble_sort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    return;
    getch();
}