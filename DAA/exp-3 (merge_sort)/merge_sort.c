#include <stdio.h>

void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Combine(int A[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[high - low + 1];

    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            temp[k] = A[i];
            i++;
        } else {
            temp[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = A[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = A[j];
        j++;
        k++;
    }

    for (int x = low; x <= high; x++) {
        A[x] = temp[x];
    }
}

void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Combine(A, low, mid, high);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element array[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    PrintArray(arr, size);

    MergeSort(arr, 0, size - 1);

    printf("Sorted array: ");
    PrintArray(arr, size);

    return 0;
}
