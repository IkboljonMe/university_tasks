#include "Std2DArrays.h"

void fillArray(int** arr, int rows, int cols) {
    int num = 1;
    // Loop through all possible diagonals starting from NE corner
    for (int startCol = cols - 1; startCol >= 0; --startCol) {
        int col = startCol;
        int row = 0;
        while (col < cols && row < rows) {
            arr[row][col] = num++;
            ++row;
            ++col;
        }
    }
    // Loop through diagonals starting from below NE corner on the right edge
    for (int startRow = 1; startRow < rows; ++startRow) {
        int row = startRow;
        int col = 0;
        while (row < rows && col < cols) {
            arr[row][col] = num++;
            ++row;
            ++col;
        }
    }
}
