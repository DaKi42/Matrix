#include <iostream>
#include "Matrix.h"
using namespace std;

ostream& operator<<(ostream& os, const A& m) {
    os << m.get_value(0, 0);
    return os;
}

istream& operator>>(istream& is, A& m) {
    int number;
    is >> number;
    m.set_value(number);
    return is; 
}

int main() {
    A a1(10);
    A a2(5);

    cout << "a1 + a2 = " << (a1 + a2).get_value(0, 0) << endl;
    cout << "a1 - a2 = " << (a1 - a2).get_value(0, 0) << endl;
    cout << "a1 * a2 = " << (a1 * a2).get_value(0, 0) << endl;

    if (a1 > a2) {
        cout << "a1 is greater than a2" << endl;
    }
    else if (a1 < a2) {
        cout << "a1 is less than a2" << endl;
    }
    else {
        cout << "a1 is equal to a2" << endl;
    }
    Matrix<A> matrix1(3, 3);
    matrix1.input();

    cout << "Matrix 1:" << endl;
    matrix1.print();

    Matrix<A> matrix2(3, 3);
    matrix2.fill();

    cout << "Matrix 2 (randomly filled):" << endl;
    matrix2.print();

    Matrix<A> matrix_sum = matrix1.add_matrix(matrix2);
    cout << "Matrix 1 + Matrix 2:" << endl;
    matrix_sum.print();

    Matrix<A> matrix_diff = matrix1.diff_matrix(matrix2);
    cout << "Matrix 1 - Matrix 2:" << endl;
    matrix_diff.print();

    Matrix<A> matrix_product = matrix1.multiply_matrix(matrix2);
    cout << "Matrix 1 * Matrix 2:" << endl;
    matrix_product.print();

    cout << "Max value in Matrix 1: " << matrix1.max() << endl;
    cout << "Min value in Matrix 2: " << matrix2.min() << endl;

    return 0;
}
