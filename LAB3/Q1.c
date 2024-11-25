#include <stdio.h>

// Function to perform activity selection
void activitySelection(int start[], int finish[], int n) {
    int i, j;

    // The first activity is always selected
    printf("Selected activities: ");
    i = 0;
    printf("%d ", i + 1);

    // Consider the rest of the activities
    for (j = 1; j < n; j++) {
        // If the start time of the current activity is greater than or equal
        // to the finish time of the previously selected activity
        if (start[j] >= finish[i]) {
            printf("%d ", j + 1);
            i = j;
        }
    }
    printf("\n");
}

int main() {
    // Example input: start and finish times of activities
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    // Sort activities by their finish times if they are not sorted
    // For simplicity, this example assumes the activities are already sorted by finish times.

    // Call the activity selection function
    activitySelection(start, finish, n);

    return 0;
}
