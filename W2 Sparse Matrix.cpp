#include <iostream>
using namespace std;

// Structure to represent a non-zero element
struct Element {
    int row;
    int col;
    int value;
};

// Structure to represent the sparse matrix
struct SparseMatrix {
    int rows;
    int cols;
    int numNonZero;
    Element* elements;

    // Constructor
    SparseMatrix(int r, int c, int num) {
        rows = r;
        cols = c;
        numNonZero = num;
        elements = new Element[numNonZero];
    }

    // Destructor
    ~SparseMatrix() {
        delete[] elements;
    }

    // Display the sparse matrix in triplet form
    void display() {
        cout << "Row\tCol\tValue\n";
        for (int i = 0; i < numNonZero; i++) {
            cout << elements[i].row << "\t"
                 << elements[i].col << "\t"
                 << elements[i].value << "\n";
        }
    }
};

int main() {
    // Example: 4x5 matrix with 5 non-zero elements
    SparseMatrix sm(4, 5, 5);

    // Manually assigning non-zero elements
    sm.elements[0] = {0, 2, 3};
    sm.elements[1] = {0, 4, 4};
    sm.elements[2] = {1, 2, 5};
    sm.elements[3] = {1, 3, 7};
    sm.elements[4] = {3, 1, 2};

    sm.display();

    return 0;
}