#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Function to check if the array is sorted
bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to shuffle the elements of the array randomly
void shuffle(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

// Bogo sort implementation
void bogoSort(int arr[], int size) {
    // Keep shuffling until the array is sorted
    while (!isSorted(arr, size)) {
        shuffle(arr, size);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Seed the random number generator
    std::srand(std::time(nullptr));

    int arr[] = {5, 2, 8, 6, 1, 3, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Unsorted array: ";
    printArray(arr, size);

    bogoSort(arr, size);

    std::cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}