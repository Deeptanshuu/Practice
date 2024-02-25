#include <stdio.h>

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
                printf("this is j %d\n",j);
            }
        }
        if(min_index != i)
            Swap(&arr[i],&arr[min_index]);
    }
}

void PrintArray(int arr[], int size)
{

    for (int i = 0; i != size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 5, 8, 9, 7};
    int size = 5;

    PrintArray(arr, size);
    SelectionSort(arr, size);
    PrintArray(arr, size);
}