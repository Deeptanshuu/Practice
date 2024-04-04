#include <stdio.h>
#include <stdlib.h>

// Function to sort the requested tracks in ascending order
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// FCFS Disk Scheduling Algorithm
void fcfs(int tracks[], int n) {
    int head = 0;
    int total_movement = 0;

    printf("\nFCFS Scheduling:\n");
    for (int i = 0; i < n; i++) {
        printf("Move from %d to %d\n", head, tracks[i]);
        total_movement += abs(head - tracks[i]);
        head = tracks[i];
    }

    printf("Total head movement: %d\n", total_movement);
}

// SCAN Disk Scheduling Algorithm
void scan(int tracks[], int n, int start, int direction) {
    int head = start;
    int total_movement = 0;
    int end_track = 199; // Assuming end track as 199

    printf("\nSCAN Scheduling:\n");
    if (direction == 1) {
        printf("Move from %d to %d\n", head, end_track);
        total_movement += abs(head - end_track);
        head = end_track;
    }

    for (int i = 0; i < n; i++) {
        printf("Move from %d to %d\n", head, tracks[i]);
        total_movement += abs(head - tracks[i]);
        head = tracks[i];
    }

    if (direction == 0) {
        printf("Move from %d to %d\n", head, 0);
        total_movement += abs(head - 0);
    }

    printf("Total head movement: %d\n", total_movement);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int tracks[n];
    printf("Enter the requested tracks:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    sort(tracks, n);

    // Starting position of disk head
    int start;
    printf("Enter the starting position of disk head: ");
    scanf("%d", &start);

    // Direction of movement for SCAN algorithm
    int direction;
    printf("Enter the direction of movement (0 for left, 1 for right): ");
    scanf("%d", &direction);

    fcfs(tracks, n);
    scan(tracks, n, start, direction);

    return 0;
}
