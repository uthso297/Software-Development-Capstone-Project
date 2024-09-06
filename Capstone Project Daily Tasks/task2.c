/*
Problem:
Write a program to rotate an array to the right by a given number of positions.
This involves moving the elements to the right and wrapping the end
elements around to the beginning of the array
*/

#include <stdio.h>

void rotateRight(int arr[], int size, int positions) {
    int temp[size];

    for (int i = 0; i < size; i++) {
        temp[(i + positions) % size] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size, positions;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to rotate the array to the right: ");
    scanf("%d", &positions);

    positions = positions % size;

    printf("Original array: ");
    printArray(arr, size);

    rotateRight(arr, size, positions);

    printf("Array after rotating right by %d positions: ", positions);
    printArray(arr, size);

    return 0;
}
