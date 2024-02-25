#include <stdio.h>

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int BinarySearch(int array[], int start_index, int end_index, int KEY)
{
    if (end_index >= start_index)
    {
        int middle = start_index + (end_index - start_index) / 2;
        if (array[middle] == KEY)
            return middle;
        if (array[middle] > KEY)
            return BinarySearch(array, start_index, middle - 1, KEY);
        return BinarySearch(array, middle + 1, end_index, KEY);
    }
    return -1;
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Input array: ");
    PrintArray(arr, size);

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = BinarySearch(arr, 0, size - 1, key);
    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found in the array.\n");
    }

    return 0;
}
