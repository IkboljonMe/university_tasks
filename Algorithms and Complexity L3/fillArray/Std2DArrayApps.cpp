#include <iostream>
#include "Std2DArrays.h"

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows = 3;
    int cols = 4;

    // Dynamically allocate a 2D array
    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    // Fill array using NE DIAG DOWN method
    fillArray(array, rows, cols);

    // Print the filled array
    printArray(array, rows, cols);

    // Deallocate the memory
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
