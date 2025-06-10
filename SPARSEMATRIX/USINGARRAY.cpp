#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum number of non-zero elements

// Function to display sparse matrix in 3-column array representation
void arrayRepresentation(int matrix[][4], int rows, int cols) {
    cout << "Array Representation (Row, Col, Value):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                cout << i << " " << j << " " << matrix[i][j] << endl;
            }
        }
    }
}

int main() {
    // Sample sparse matrix
    int matrix[4][4] = {
        {0, 0, 3, 0},
        {22, 0, 0, 0},
        {0, 0, 0, 5},
        {0, 17, 0, 0}
    };

    arrayRepresentation(matrix, 4, 4);

    return 0;
}