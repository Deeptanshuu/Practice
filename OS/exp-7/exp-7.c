#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

bool is_safe_state(int available[], int allocation[][MAX_RESOURCES], int need[][MAX_RESOURCES], int n, int m, int safe_sequence[]) {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = { false };

    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool can_allocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    safe_sequence[count] = i;
                    count++;
                    found = true;
                }
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

void banker_algorithm(int num_processes, int num_resources, int allocation[][MAX_RESOURCES], int max_claim[][MAX_RESOURCES], int available[]) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int safe_sequence[MAX_PROCESSES];

    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            need[i][j] = max_claim[i][j] - allocation[i][j];
        }
    }

    printf("Enter the sequence of processes to be executed: ");
    int sequence[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        scanf("%d", &sequence[i]);
    }

    int available_copy[MAX_RESOURCES];
    for (int i = 0; i < num_resources; i++) {
        available_copy[i] = available[i];
    }

    bool safe = is_safe_state(available_copy, allocation, need, num_processes, num_resources, safe_sequence);

    if (safe) {
        printf("The given sequence is safe.\n");
        printf("Safe sequence: ");
        for (int i = 0; i < num_processes; i++) {
            printf("P%d", safe_sequence[i]);
            if (i != num_processes - 1) {
                printf("->");
            }
        }
        printf("\n");
    } else {
        printf("The given sequence is unsafe.\n");
    }
}

int main() {
    int num_processes, num_resources;
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int max_claim[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the number of resource types: ");
    scanf("%d", &num_resources);

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the max claim matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &max_claim[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (int i = 0; i < num_resources; i++) {
        scanf("%d", &available[i]);
    }

    banker_algorithm(num_processes, num_resources, allocation, max_claim, available);

    return 0;
}
