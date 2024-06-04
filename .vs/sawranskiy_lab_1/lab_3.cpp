#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<:vector<int>> data;
    size_t rows, cols;

public:
    // The default constructor
    Matrix(size_t rows = 2, size_t cols = 2) : rows(rows), cols(cols) 
    {
        data.resize(rows, vector<int>(cols, 0));
    }

    // Constructor with parameters
    Matrix(const vector<vector<int>>& data) : data(data), rows(data.size()), cols(data[0].size()) {}

    // Copy constructor
    Matrix(const Matrix& other) : data(other.data), rows(other.rows), cols(other.cols) {}

    // Assignment operator as a class method
    Matrix& operator=(const Matrix& other) 
    {
        if (this != &other) 
        {
            data = other.data;
            rows = other.rows;
            cols = other.cols;
        }
        return *this;
    }

    // The addition operator as a class method
    Matrix operator+(const Matrix& other) const 
    {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) 
        {
            for (size_t j = 0; j < cols; ++j) 
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Multiplication operator as a class method
    Matrix operator*(int scalar) const 
    {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) 
        {
            for (size_t j = 0; j < cols; ++j) 
            {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // The increment operator as a class method
    Matrix& operator++() 
    {
        for (size_t i = 0; i < rows; ++i) 
        {
            for (size_t j = 0; j < cols; ++j) 
            {
                ++data[i][j];
            }
        }
        return *this;
    }

    // Matrix printing
    void print() const 
    {
        for (const auto& row : data) 
        {
            for (const auto& elem : row) 
            {
                cout << elem << " ";
            }
            cout << std::endl;
        }
    }

    // Friendly addition operator
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);

    // Friendly operator of multiplication by a number
    friend Matrix operator*(const Matrix& lhs, int scalar);

    // Friendly increment operator
    friend Matrix& operator++(Matrix& mat);

    // Normal assignment function
    friend void assign(Matrix& lhs, const Matrix& rhs);
};

// Friendly addition operator
Matrix operator+(const Matrix& lhs, const Matrix& rhs) 
{
    Matrix result(lhs.rows, lhs.cols);
    for (size_t i = 0; i < lhs.rows; ++i) 
    {
        for (size_t j = 0; j < lhs.cols; ++j) 
        {
            result.data[i][j] = lhs.data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

// Friendly operator of multiplication by a number
Matrix operator*(const Matrix& lhs, int scalar) 
{
    Matrix result(lhs.rows, lhs.cols);
    for (size_t i = 0; i < lhs.rows; ++i) 
    {
        for (size_t j = 0; j < lhs.cols; ++j) 
        {
            result.data[i][j] = lhs.data[i][j] * scalar;
        }
    }
    return result;
}

// Friendly increment operator
Matrix& operator++(Matrix& mat) 
{
    for (size_t i = 0; i < mat.rows; ++i) 
    {
        for (size_t j = 0; j < mat.cols; ++j) 
        {
            ++mat.data[i][j];
        }
    }
    return mat;
}

// Normal assignment function
void assign(Matrix& lhs, const Matrix& rhs) 
{
    lhs.data = rhs.data;
    lhs.rows = rhs.rows;
    lhs.cols = rhs.cols;
}

int main() {
    // Creation of matrices
    Matrix mat1{ {1, 2}, {3, 4} };
    Matrix mat2{ {5, 6}, {7, 8} };

    // Using the assignment operator as a class method
    Matrix mat3;
    mat3 = mat1;
    cout << "Matrix mat3 after assignment to mat1:\n";
    mat3.print();

    // Using the addition operator as a class method
    Matrix mat4 = mat1 + mat2;
    cout << "The result of adding mat1 and mat2:\n";
    mat4.print();

    // Using the multiplication operator as a class method
    Matrix mat5 = mat1 * 2;
    cout << "The result of multiplying mat1 by 2:\n";
    mat5.print();

    // Using the increment operator as a class method
    ++mat1;
    cout << "The result of mat1 increment:\n";
    mat1.print();

    // Using the friendly addition operator
    Matrix mat6 = operator+(mat1, mat2);
    cout << "The result of adding mat1 and mat2 (friendly operator):\n";
    mat6.print();

    // Using the friendly operator of multiplication by a number
    Matrix mat7 = operator*(mat1, 3);
    cout << "The result of multiplying mat1 by 3 (friendly operator):\n";
    mat7.print();

    // Using the friendly increment operator
    operator++(mat2);
   cout << "Result of mat2 increment (friendly operator):\n";
    mat2.print();

    // Using a normal function for assignment
    assign(mat3, mat2);
    cout << "Matrix mat3 after assignment to mat2 (usual function):\n";
    mat3.print();

    return 0;
}
