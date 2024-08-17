#include <stdio.h>

typedef struct {
    int value;
    int weight;
    float ratio; // Ratio of value/weight
} Item;

// Function to perform bubble sort on the items array based on the ratio
void bubbleSort(Item items[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (items[j].ratio < items[j+1].ratio) {
                Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

// Function to calculate maximum profit for fractional knapsack
int fractionalKnapsack(int capacity, Item items[], int n) {
    bubbleSort(items, n); // Sort items by ratio

    int totalValue = 0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (remainingCapacity == 0) {
            break;
        }

        if (items[i].weight <= remainingCapacity) {
            // If the item can be taken whole
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // If the item can only be taken fractionally
            totalValue += (items[i].value * remainingCapacity) / items[i].weight;
            remainingCapacity = 0;
        }
    }

    return totalValue;
}

int main() {
    Item items[] = {
        {60, 10}, // value, weight
        {100, 20},
        {120, 30}
    };

    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    // Calculate ratios
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    int maxProfit = fractionalKnapsack(capacity, items, n);
    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}