#include<stdio.h>

int main() {
    float weight[50], profit[50], ratio[50], Totalvalue = 0, temp, capacity;
    int n, i, j;
    
    printf("Enter the number of items (max 50): ");
    scanf("%d", &n);

    if (n > 50) {
        printf("Number of items exceeds maximum limit.\n");
        return 1;
    }


    for (i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item[%d] :\n", i);
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);


    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > capacity)
            break;
        else {
            Totalvalue += profit[i];
            capacity -= weight[i];
        }
    }

    // Add fractional part of the last item
    if (i < n)
        Totalvalue += (ratio[i] * capacity);

    printf("The maximum value is: %.2f\n", Totalvalue);

    return 0;
}
