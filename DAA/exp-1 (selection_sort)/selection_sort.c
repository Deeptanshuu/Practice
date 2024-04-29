#include <stdio.h>

void PrintArray(int arr[], int size)
{
    for (int i = 0; i != size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int size)
{
    int min_index;

    for (int i = 0; i != size-1; i++)
    {
        min_index = i;
        for (int j = i + 1; j != size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if(min_index != i){
            printf("\nSorting:");
            PrintArray(arr, size);
            Swap(&arr[i],&arr[min_index]);
            printf("arr[i]:%d, arr[min_index]:%d\n",arr[i],arr[min_index]);
        }
    }
}



int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = 5;

    printf("Unsorted Array:");
    PrintArray(arr, size);

    SelectionSort(arr, size);

    printf("Sorted Array:");
    PrintArray(arr, size);
}