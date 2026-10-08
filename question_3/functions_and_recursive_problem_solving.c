#include <stdio.h>

// Calculates total distance iteratively
int calculate_total_distance(const int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Demonstrates function reuse by calling calculate_total_distance inside
double calculate_average_distance(const int arr[], int size) {
    if (size <= 0) {
        return 0.0;
    }
    int total = calculate_total_distance(arr, size);
    return (double)total / size;
}

// Finds the longest route in the array
int find_longest_route(const int arr[], int size) {
    if (size <= 0) {
        return 0;
    }
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counts routes exceeding a given threshold (reusable with various limits)
int count_routes_above_limit(const int arr[], int size, int limit) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > limit) {
            count++;
        }
    }
    return count;
}

// Recursive function to calculate the sum of array elements
int recursive_sum(const int arr[], int size) {
    // Base Case: when size is 0, the sum of zero elements is 0
    if (size <= 0) {
        return 0;
    }
    // Recursive Step: current last element + sum of remaining (size - 1) elements
    return arr[size - 1] + recursive_sum(arr, size - 1);
}

int main(void) {
    // Array of route distances
    int distances[] = {12, 95, 13, 70, 15, 31};
    int n = sizeof(distances) / sizeof(distances[0]);
    int threshold = 20;

    // Computing metrics using modular functions
    int total = calculate_total_distance(distances, n);
    double average = calculate_average_distance(distances, n);
    int longest = find_longest_route(distances, n);
    int count_above_20 = count_routes_above_limit(distances, n, threshold);
    int rec_sum = recursive_sum(distances, n);

    // Display formatted analysis
    printf("===== DELIVERY DISTANCE ANALYSIS =====\n\n");
    printf("Total distance: %d km\n", total);
    printf("Average distance: %.2f km\n", average);
    printf("Longest route: %d km\n", longest);
    printf("Routes above %d km: %d\n\n", threshold, count_above_20);
    printf("Recursive sum: %d km\n", rec_sum);

    return 0;
}