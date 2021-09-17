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

int min_value(int arr[], int n, int i)
{
    int j, LOC, index;
    LOC = arr[i];
    index = i;
    for (j = i; j < n; j++)
    {
        if (LOC > arr[j])
        {
            LOC = arr[j];
            index = j;
        }
    }
    return index;
}

void main()
{
    int arr[100], n, i, LOC, temp;
    printf("Enter number of array you want to enter in the array.");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter value at arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Original array:\n");
    printArray(arr, n);

    for (i = 0; i < n - 1; i++)
    {
        LOC = min_value(arr, n, i);
        temp = arr[LOC];
        arr[LOC] = arr[i];
        arr[i] = temp;
    }
    printf("Sorted array:\n");
    printArray(arr, n);
    return;
    getch();
}