#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare two activities based on their finish time
int compare(const void* a, const void* b) {
    struct Activity* activity1 = (struct Activity*) a;
    struct Activity* activity2 = (struct Activity*) b;
    
    // Sort by finish time in ascending order
    return activity1->finish - activity2->finish;
}

// Function to select the maximum number of activities
void activitySelection(struct Activity activities[], int n) {
    // Sort the activities based on finish time
    qsort(activities, n, sizeof(activities[0]), compare);
    
    // Select the first activity
    printf("Selected Activities:\n");
    printf("Start: %d, Finish: %d\n", activities[0].start, activities[0].finish);
    
    int lastFinishTime = activities[0].finish; // Finish time of the last selected activity
    
    // Consider the rest of the activities
    for (int i = 1; i < n; i++) {
        // If the start time of the current activity is greater than or equal to the last selected activity's finish time
        if (activities[i].start >= lastFinishTime) {
            // Select the current activity
            printf("Start: %d, Finish: %d\n", activities[i].start, activities[i].finish);
            lastFinishTime = activities[i].finish; // Update the finish time
        }
    }
}

// Main function to test the Activity Selection Problem
int main() {
    int n;

    // Input the number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    // Input the start and finish times for each activity
    printf("Enter the start and finish times of each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d (start, finish): ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Select and print the maximum number of activities
    activitySelection(activities, n);

    return 0;
}
