#include <stdio.h>

#define MAX_PARTITIONS 10
#define MAX_PROCESSES 10

void first_fit(int partitions[], int processes[], int n, int p) {
    int flag[MAX_PROCESSES] = {0};

    printf("\nFirst Fit Algorithm:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            if (partitions[i] >= processes[j] && flag[j] == 0) {
                flag[j] = 1;
                printf("P%d\t\t%d\n", j, partitions[i]);
                break;
            }
        }
    }
}

void best_fit(int partitions[], int processes[], int n, int p) {
    int sorted_partitions[MAX_PARTITIONS];
    int flag[MAX_PROCESSES] = {0};

    // Sort partitions in ascending order
    for (int i = 0; i < n; i++) {
        sorted_partitions[i] = partitions[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sorted_partitions[i] > sorted_partitions[j]) {
                int temp = sorted_partitions[i];
                sorted_partitions[i] = sorted_partitions[j];
                sorted_partitions[j] = temp;
            }
        }
    }

    printf("\nBest Fit Algorithm:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            if (sorted_partitions[j] >= processes[i] && flag[i] == 0) {
                flag[i] = 1;
                printf("P%d\t\t%d\n", i, sorted_partitions[j]);
                break;
            }
        }
    }
}

void worst_fit(int partitions[], int processes[], int n, int p) {
    int sorted_partitions[MAX_PARTITIONS];
    int flag[MAX_PROCESSES] = {0};

    // Sort partitions in descending order
    for (int i = 0; i < n; i++) {
        sorted_partitions[i] = partitions[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sorted_partitions[i] < sorted_partitions[j]) {
                int temp = sorted_partitions[i];
                sorted_partitions[i] = sorted_partitions[j];
                sorted_partitions[j] = temp;
            }
        }
    }

    printf("\nWorst Fit Algorithm:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            if (sorted_partitions[j] >= processes[i] && flag[i] == 0) {
                flag[i] = 1;
                printf("P%d\t\t%d\n", i, sorted_partitions[j]);
                break;
            }
        }
    }
}

int main() {
    int partitions[MAX_PARTITIONS], processes[MAX_PROCESSES];
    int n, p;

    printf("Enter the number of partitions: ");
    scanf("%d", &n);

    printf("Enter the size of each partition:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &partitions[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &p);

    printf("Enter the size of each process:\n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &processes[i]);
    }

    first_fit(partitions, processes, n, p);
    best_fit(partitions, processes, n, p);
    worst_fit(partitions, processes, n, p);

    return 0;
}
