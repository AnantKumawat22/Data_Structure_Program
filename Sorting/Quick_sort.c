#include <stdio.h>
#include <conio.h>

int partition(int[], int, int);
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *Ai, int *Aj)
{
    int temp;
    temp = *Ai;
    *Ai = *Aj;
    *Aj = temp;
}

// First element is pivot.

int partition(int arr[], int low, int high)
{
    int i = low + 1, temp;
    int j = high;
    int pivot = arr[low];
    do
    {
        while (pivot > arr[i])
        {
            i++;
        }

        while (pivot < arr[j])
        {
            j--;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);

    swap(&arr[j], &arr[low]);
    return j;
}

//Short time complexity.

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[low];
//     int i = low;
//     for (int j = low + 1; j <= high; j++)
//     {
//         if (pivot >= arr[j])
//         {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i], &arr[low]);
//     return i;
// }

// Last element is pivot.(Error -> Correct the Code !!)

// int partition(int arr[], int low, int high)
// {
//     // Your code here
//     int i, j, temp, pivot;

//     i = low;
//     pivot = arr[high];
//     j = high - 1;

//     do
//     {
//         while (arr[i] < pivot)
//         {
//             i++;
//         }
//         while (pivot < arr[j])
//         {
//             j--;
//         }
//         if (i < j)
//         {
//             swap(&arr[i], &arr[j]);
//         }

//     } while (i < j);

//     swap(&arr[j - 1], &arr[high]);

//     return (j);
// }



void quickSort(int arr[], int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        quickSort(arr, low, partitionindex - 1);
        quickSort(arr, partitionindex + 1, high);
    }
}

void main()
{
    int arr[100], n, i;
    printf("Enter number of elements you want to enter in the array.");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter value at arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Original array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    printArray(arr, n);

    return;
    getch();
}