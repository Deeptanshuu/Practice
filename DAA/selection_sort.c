#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArry(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void SelectionSort(int arr[], int size) {
    int min, loc;

    for (int i = 0; i < size - 1; i++) {
        min = arr[i];
        loc = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < min) {
                min = arr[j];
                loc = j;
            }
        }

        if (loc != i) {
            swap(&arr[i], &arr[loc]);
        }
    }
}

int main() {
    int arr[100];
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter element arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Input array: ");
    PrintArry(arr, size);

    SelectionSort(arr, size);

    printf("Sorted array: ");
    PrintArry(arr, size);

    return 0;
}
