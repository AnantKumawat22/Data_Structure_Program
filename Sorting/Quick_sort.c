#include <stdio.h>
#include <conio.h>

int partition(int [], int, int);
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        quick_sort(arr, low, partitionindex - 1);
        quick_sort(arr, partitionindex + 1, high);
    }
}

// Last element is pivot.

// void quickSort(int arr[], int low, int high)
// {
//     // code here
//     int partind;
//     if(low < high)
//     {
//         partind = partition(arr, low, high);
//         quickSort(arr, low, partind - 1);
//         quickSort(arr, partind + 1, high);
//     }
// }
    
// int partition (int arr[], int low, int high)
// {
//    // Your code here
//    int i, j, temp, pivot;
   
//    i = low;
//    pivot = arr[high];
//    j = high - 1;
   
//    do
//    {
//        while(arr[i] < pivot)
//        {
//            i++;
//        }
//        while(pivot < arr[j])
//        {
//            j--;
//        }
//        if(i < j)
//        {
//            temp = arr[j];
//            arr[j] = arr[i];
//            arr[i] = temp;
//        }
       
//    }while(i < j);
   
//    temp = arr[high];
//    arr[high] = arr[j + 1];
//    arr[j + 1] = temp;
   
//    return (j+1);
// }


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