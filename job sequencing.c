#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    int id;      // Job ID
    int profit;  // Profit if the job is completed
    int deadline; // Deadline of the job
} Job;

// Function to compare two jobs according to their profits
void bubbleSort(Job jobs[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (jobs[j].profit < jobs[j+1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}

// Function to find the maximum deadline
int findMaxDeadline(Job jobs[], int n) {
    int maxDeadline = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

// Function to perform job sequencing to maximize profit
void jobSequencing(Job jobs[], int n) {
    // Sort jobs in decreasing order of profit using bubble sort
    bubbleSort(jobs, n);

    // Find the maximum deadline
    int maxDeadline = findMaxDeadline(jobs, n);

    // Create an array to keep track of free time slots
    int *slots = (int *)malloc((maxDeadline + 1) * sizeof(int));
    for (int i = 0; i <= maxDeadline; i++) {
        slots[i] = -1;
    }

    int totalProfit = 0;
    int jobCount = 0;

    // Array to track scheduled jobs
    int *scheduled = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scheduled[i] = 0;
    }

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = i;
                totalProfit += jobs[i].profit;
                jobCount++;
                scheduled[i] = 1; // Mark job as scheduled
                break;
            }
        }
    }

    // Print the scheduled jobs
    printf("The selected jobs to maximize profit are:\n");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slots[i] != -1) {
            printf("Job ID: %d, Profit: %d, Deadline: %d\n", jobs[slots[i]].id, jobs[slots[i]].profit, jobs[slots[i]].deadline);
        }
    }
    printf("Total Profit: %d\n", totalProfit);

    // Print the leftover jobs
    printf("The leftover jobs are:\n");
    for (int i = 0; i < n; i++) {
        if (!scheduled[i]) {
            printf("Job ID: %d, Profit: %d, Deadline: %d\n", jobs[i].id, jobs[i].profit, jobs[i].deadline);
        }
    }

    // Free the allocated memory
    free(slots);
    free(scheduled);
}

int main() {
    // Example jobs with (Job ID, Profit, Deadline)
    Job jobs[] = {
        {1, 100, 2},
        {2, 19, 1},
        {3, 27, 2},
        {4, 25, 1},
        {5, 15, 3}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Call the job sequencing function
    jobSequencing(jobs, n);

    return 0;
}
