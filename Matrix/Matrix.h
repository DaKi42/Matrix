#pragma once
#include <iostream>

class A {
private:
    int value;

public:
    A() = default;

    A(int val) : value(val) {} 

    int get_value(int r, int c) const 
    {
        return value;
    }

    void set_value(int b) {
        value = b;
    }

    A& operator= (int b) 
    {
        value = b; 
        return *this;
    }

    A operator- (int num) 
    {
        return A(value - num);
    }

    A operator- (const A& other) 
    {
        return A(value - other.value);
    }

    A operator+ (int num) 
    {
        return A(value + num);
    }

    A operator+ (const A& other) 
    {
        return A(value + other.value);
    }

    A operator/ (int num) 
    {
        return A(value / num);
    }

    A operator/ (const A& obj) 
    {
        if (obj.value != 0) {
            return A(value / obj.value);
        }
        return A();
    }

    A operator* (int b) 
    {
        return A(value * b);
    }

    A operator* (const A& other) 
    {
        return A(value * other.value);
    }

    bool operator> (const A& other) const 
    {
        return value > other.value;
    }

    bool operator< (const A& other) const 
    {
        return value < other.value;
    }

    A operator++ (int) 
    {
        A result(*this);
        value++;
        return result;
    }
};

template <typename T>
class Matrix {
private:
    T** arr;
    int rows;
    int cols;

public:
    Matrix() : arr(nullptr), rows(0), cols(0) {}

    Matrix(int nr, int nc) : rows(nr), cols(nc) {
        arr = new T * [rows];

        for (int i = 0; i < rows; ++i) {
            arr[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    T get_arr(int r, int c) {
        if (r < rows && r >= 0 && c < cols && c >= 0) {
            return arr[r][c];
        }
    }

    T set_arr(int r, int c) {
        if (r > 1 && c > 1) {
            rows = r;
            cols = c;
        }
    }

    void input() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter the element at row " << i + 1 << " and column " << j + 1 << ": ";
                std::cin >> arr[i][j];
            }
        }
    }


    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << arr[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    void fill() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr[i][j] = rand() % 60;
            }
        }
    }

    T max() {
        T max_val = arr[0][0];

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (arr[i][j] > max_val) {
                    max_val = arr[i][j];
                }
            }
        }
        return max_val;
    }

    T min() {
        T min_val = arr[0][0];

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (arr[i][j] < min_val) {
                    min_val = arr[i][j];
                }
            }
        }
        return min_val;
    }

    Matrix<T> add_matrix(const Matrix<T>& other_matrix) {
        Matrix<T> result_matrix(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result_matrix.arr[i][j] = arr[i][j] + other_matrix.arr[i][j];
            }
        }
        return result_matrix;
    }

    Matrix<T> diff_matrix(const Matrix<T>& other_matrix) {
        Matrix<T> result_matrix(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result_matrix.arr[i][j] = arr[i][j] - other_matrix.arr[i][j];
            }
        }
        return result_matrix;
    }

    Matrix<T> divide_matrix(const Matrix<T>& other_matrix) {
        Matrix<T> result_matrix(rows, other_matrix.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other_matrix.cols; ++j) {
                result_matrix.arr[i][j] = arr[i][j] / other_matrix.arr[i][j];
            }
        }
        return result_matrix;
    }

    Matrix<T> add_number(int num) {
        Matrix<T> result_matrix(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result_matrix.arr[i][j] = arr[i][j] + num;
            }
        }
        return result_matrix;
    }

    Matrix<T> diff_number(int num) {
        Matrix<T> result_matrix(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result_matrix.arr[i][j] = arr[i][j] - num;
            }
        }
        return result_matrix;
    }

    Matrix<T> divide_number(int num) {
        Matrix<T> result_matrix(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result_matrix.arr[i][j] = arr[i][j] / num;
            }
        }
        return result_matrix;
    }

    Matrix<T> multiply_matrix(const Matrix<T>& other_matrix) {
        Matrix<T> result_matrix(rows, other_matrix.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other_matrix.cols; ++j) {
                result_matrix.arr[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result_matrix.arr[i][j] = (arr[i][k] * other_matrix.arr[k][j]);
                }
            }
        }
        return result_matrix;
    }

    Matrix<T> multiply_number(int num) {
        Matrix<T> result_matrix(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result_matrix.arr[i][j] = arr[i][j] * num;
            }
        }
        return result_matrix;
    }
};
