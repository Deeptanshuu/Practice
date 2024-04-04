#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FRAMES 10

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Check if page is present in frame
bool isPagePresent(int frames[], int frameSize, int page) {
    for (int i = 0; i < frameSize; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// Insert page into circular linked list
void insertPage(struct Node** start, int page, int frameSize) {
    struct Node* temp = *start;

    // If list is empty, create the first node
    if (temp == NULL) {
        *start = createNode(page);
        (*start)->next = *start;
        return;
    }

    // Traverse the list to check if page already exists
    struct Node* prev = NULL;
    do {
        if (temp->data == page) {
            // Page already exists, return
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != *start);

    // If list has empty node, insert page
    if (prev->data == -99) {
        prev->data = page;
        return;
    }

    // Replace the oldest page
    prev->data = page;
    *start = prev->next;
}

// Display page frames
void displayFrames(struct Node* start, int frameSize) {
    struct Node* temp = start;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
}

// FIFO page replacement algorithm
void FIFO(int pages[], int pageCount, int frameSize) {
    printf("FIFO Algorithm:\n");
    struct Node* start = NULL;

    for (int i = 0; i < pageCount; i++) {
        insertPage(&start, pages[i], frameSize);
        displayFrames(start, frameSize);
    }

    free(start);
}

// LRU page replacement algorithm
void LRU(int pages[], int pageCount, int frameSize) {
    printf("LRU Algorithm:\n");
    int stack[MAX_FRAMES];
    int top = -1;

    for (int i = 0; i < pageCount; i++) {
        int j, k;
        for (j = 0; j <= top; j++) {
            if (stack[j] == pages[i]) {
                for (k = j; k < top; k++) {
                    stack[k] = stack[k + 1];
                }
                stack[top] = pages[i];
                break;
            }
        }
        if (j > top) {
            if (top == frameSize - 1) {
                for (k = 0; k < top; k++) {
                    stack[k] = stack[k + 1];
                }
                stack[top] = pages[i];
            } else {
                stack[++top] = pages[i];
            }
        }
        for (j = 0; j <= top; j++) {
            printf("%d ", stack[j]);
        }
        printf("\n");
    }
}

// Optimal page replacement algorithm
void Optimal(int pages[], int pageCount, int frameSize) {
    printf("Optimal Algorithm:\n");
    int frames[MAX_FRAMES];
    bool isPresent[MAX_FRAMES] = {false};
    int pageFaults = 0;

    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1; // Initialize frames with -1
    }

    for (int i = 0; i < pageCount; i++) {
        if (!isPagePresent(frames, frameSize, pages[i])) {
            int farthest = -1;
            int replaceIndex = -1;
            for (int j = 0; j < frameSize; j++) {
                int k;
                for (k = i + 1; k < pageCount; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            replaceIndex = j;
                        }
                        break;
                    }
                }
                if (k == pageCount) {
                    replaceIndex = j;
                    break;
                }
            }
            frames[replaceIndex] = pages[i];
            pageFaults++;
        }

        // Display frames after each page reference
        for (int j = 0; j < frameSize; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", pageFaults);
}


int main() {
    int frameSize, pageCount;
    int pages[MAX_FRAMES];

    printf("Enter frame size: ");
    scanf("%d", &frameSize);

    printf("Enter number of pages: ");
    scanf("%d", &pageCount);

    printf("Enter sequence of pages: ");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }

    FIFO(pages, pageCount, frameSize);
    LRU(pages, pageCount, frameSize);
    Optimal(pages, pageCount, frameSize);

    return 0;
}
