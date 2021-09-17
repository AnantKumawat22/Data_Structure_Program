#include <stdio.h>
#include <conio.h>

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int n)
{
    int j, i, temp;
    
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; j--)
        {
                arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

void main()
{
    int arr[100], n, i;
    printf("Enter number of array you want to enter in the array.");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter value at arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Original array:\n");
    printArray(arr, n);

    insertion_sort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    return;
    getch();
}