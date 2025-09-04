#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

class SparseMatrix {
private:
    int rows, cols, numNonZero;
    Element* elements;

public:
    // Constructor
    SparseMatrix(int r, int c, int n) {
        rows = r;
        cols = c;
        numNonZero = n;
        elements = new Element[numNonZero];
    }

    // Destructor
    ~SparseMatrix() {
        delete[] elements;
    }


    void readElements() {
        cout << "Enter non-zero elements (row col value):" << endl;
        for (int i = 0; i < numNonZero; i++) {
            cin >> elements[i].row >> elements[i].col >> elements[i].value;
        }
    }

    // Function to display sparse matrix
    void display() {
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (k < numNonZero &&
                    elements[k].row == i &&
                    elements[k].col == j) {
                    cout << elements[k].value << " ";
                    k++;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols, n;

    cout << "Enter your number of rows, columns, and non-zero elements: ";
    cin >> rows >> cols >> n;

    SparseMatrix sm(rows, cols, n);

    sm.readElements();

    cout << "\nSparse Matrix Representation:\n";
    sm.display();

    return 0;
}
