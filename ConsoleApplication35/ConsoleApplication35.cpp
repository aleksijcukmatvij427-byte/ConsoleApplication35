#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
using namespace std;

// Task 1. Function to sort an array ascending or descending
// order = 1 (default) for descending, order = 0 for ascending
void sortArray(int arr[], int size, int order = 1) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((order == 1 && arr[j] < arr[j + 1]) ||
                (order == 0 && arr[j] > arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Helper function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed for random numbers

    // Task 1. Sorting array with default parameter
    cout << "Task 1. Sort array (descending by default, ascending if 0)" << endl;
    {
        int arr1[10] = { 5, 2, 9, 1, 7, 3, 8, 4, 6, 0 };
        cout << "Original array: ";
        printArray(arr1, 10);

        sortArray(arr1, 10); // Default is 1 (descending)
        cout << "Sorted descending (default): ";
        printArray(arr1, 10);

        sortArray(arr1, 10, 0); // 0 for ascending
        cout << "Sorted ascending (0): ";
        printArray(arr1, 10);
        cout << endl;
    }

    // Task 2. Sort elements between extreme negative elements
    cout << "Task 2. Sort elements between leftmost and rightmost negative elements" << endl;
    {
        int arr2[15];
        cout << "Generated array: ";
        for (int i = 0; i < 15; i++) {
            arr2[i] = rand() % 41 - 20; // Random -20 to 20
            cout << arr2[i] << " ";
        }
        cout << endl;

        int leftIdx = -1, rightIdx = -1;
        for (int i = 0; i < 15; i++) {
            if (arr2[i] < 0) {
                if (leftIdx == -1) leftIdx = i;
                rightIdx = i;
            }
        }

        if (leftIdx != -1 && rightIdx != -1 && rightIdx > leftIdx + 1) {
            cout << "Leftmost negative at index " << leftIdx << ", rightmost at index " << rightIdx << endl;
            // Sort elements strictly between them in ascending order
            sort(arr2 + leftIdx + 1, arr2 + rightIdx);
            cout << "Array after sorting between them: ";
            printArray(arr2, 15);
        }
        else {
            cout << "Not enough negative elements to sort between." << endl;
        }
        cout << endl;
    }

    // Task 3. Bonus +12 points
    cout << "Task 3. Bonus task" << endl;
    {
        int arr3[20];
        for (int i = 0; i < 20; i++) {
            arr3[i] = i + 1; // Values from 1 to 20
        }

        // Shuffle the array randomly
        random_shuffle(arr3, arr3 + 20);
        cout << "Shuffled array: ";
        printArray(arr3, 20);

        // Generate a random number from 1 to 20 and find its position
        int target = rand() % 20 + 1;
        int pos = -1;
        for (int i = 0; i < 20; i++) {
            if (arr3[i] == target) {
                pos = i;
                break;
            }
        }

        cout << "Random target number: " << target << endl;
        if (pos != -1) {
            cout << "Found at position: " << pos << endl;

            // Sort left part descending
            sort(arr3, arr3 + pos, greater<int>());
            // Sort right part ascending
            sort(arr3 + pos + 1, arr3 + 20);

            cout << "Array after sorting left (desc) and right (asc): ";
            printArray(arr3, 20);
        }
        else {
            cout << "Target number not found in array." << endl;
        }
    }

    return 0;
}