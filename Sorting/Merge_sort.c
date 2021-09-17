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

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int brr[100];
    i = low;
    j = mid + 1;
    k = low;
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            brr[k] = arr[i];
            i++;k++;
        }
        else
        {
            brr[k] = arr[j];
            j++;k++;
        }
    }
    while(i <= mid)
    {
        brr[k] = arr[i];
        i++;k++;
    }
    while(j <= high)
    {
        brr[k] = arr[j];
        j++;k++;
    }
    for(i = 0; i < high; i++)
    {
        arr[i] = brr[i];
    }
}

void merge_sort(int arr[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void main()
{
    int arr[] = {12, 1, 3, 4, 6, 4}, n, i;
    printf("Enter number of elements you want to enter in the array.");
    scanf("%d", &n);
    // for (i = 0; i < n; i++)
    // {
    //     printf("Enter value at arr[%d]: ", i);
    //     scanf("%d", &arr[i]);
    // }
    printf("Original array:\n");
    printArray(arr, n);

    merge_sort(arr, 0, n - 1);
    printf("Sorted array:\n");
    printArray(arr, n);

    return;
    getch();
}