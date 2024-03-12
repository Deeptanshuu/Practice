#include<stdio.h>
#include<stdlib.h>

void stopAndWait() {
    int frame[10], i, j, n;
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    printf("Enter the frame sequence:\n");
    for(i=1; i<=n; i++) {
        scanf("%d", &frame[i]);
    }
    i=1;
    while(i<=n) {
        printf("Frame %d has been transmitted.\n", frame[i]);
        printf("Did you receive frame %d? (0=NO, 1=YES): ", frame[i]);
        scanf("%d", &j);
        if(j==0) {
            printf("Frame %d will be retransmitted.\n", frame[i]);
        } else {
            i++;
        }
    }
    printf("\nAll frames have been transmitted successfully.\n");
}

void slidingWindow() {
    int w, i, f, frames[50];
    printf("Enter window size: ");
    scanf("%d", &w);
    printf("Enter number of frames to transmit: ");
    scanf("%d", &f);
    printf("Enter %d frames: ", f);
    for(i=1; i<=f; i++) {
        scanf("%d", &frames[i]);
    }
    printf("\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n\n");
    printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n\n", w);
    for(i=1;i<=f;i++) {
        if(i%w==0) {
            printf("%d\n",frames[i]);
            printf("Acknowledgement of above frames sent is received by sender\n\n");
        } else {
            printf("%d ",frames[i]);
        }
    }
    if(f%w!=0) {
        printf("\nAcknowledgement of above frames sent is received by sender\n");
    }
}

int main() {
    int choice;
    printf("Choose a protocol to implement:\n");
    printf("1. Stop and Wait Protocol\n");
    printf("2. Sliding Window Protocol\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            stopAndWait();
            break;
        case 2:
            slidingWindow();
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}
