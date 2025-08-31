#include <iostream>
using namespace std;

// Draws a Sierpinski triangle recursively
void sierpinski(int row, int col, int size, char **canvas) {
    if (size == 1) {
        canvas[row][col] = '*';  // base case: just one star
        return;
    }

    int newSize = size / 2;
    // Top triangle
    sierpinski(row, col, newSize, canvas);
    // Bottom-left triangle
    sierpinski(row + newSize, col - newSize, newSize, canvas);
    // Bottom-right triangle
    sierpinski(row + newSize, col + newSize, newSize, canvas);
}

int main() {
    int n = 4; // must be a power of 2 (size of the triangle height)

    // Create canvas filled with spaces
    char **canvas = new char*[n];
    for (int i = 0; i < n; i++) {
        canvas[i] = new char[2*n];
        for (int j = 0; j < 2*n; j++) canvas[i][j] = ' ';
    }

    // Draw fractal
    sierpinski(0, n - 1, n, canvas);

    // Print canvas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n; j++) cout << canvas[i][j];
        cout << "\n";
    }

    // Cleanup
    for (int i = 0; i < n; i++) delete[] canvas[i];
    delete[] canvas;
    return 0;
}
