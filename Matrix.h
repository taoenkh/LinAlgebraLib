

#ifndef LINALGEBRA_MATRIX_H
#define LINALGEBRA_MATRIX_H


#include <sstream>
template <typename T>

class Matrix{
private:

    int rowSize;
    int colSize;
public:
    std::vector <std::vector<T>> matrix_val;
    Matrix(int row,int col,const T & element);
    explicit Matrix(std::vector<std::vector<T>> mat);
    Matrix(const Matrix<T> &mat);
    Matrix<T> multiply(const  Matrix & mat);
    Matrix<T> multiply(const int &n);
    Matrix<T> operator* (const Matrix<T> &rhs);
    Matrix<T> operator* (const int &n);
    inline void validate_multiply(const Matrix<T>&m);
    Matrix<T> transpose();
    virtual ~Matrix();
};


#endif //LINALGEBRA_MATRIX_H
template <typename T>
std::ostream &operator<<(std::ostream &outs, const Matrix<T> &mat){
    outs << "Matrix[";
    for (int i = 0; i < mat.matrix_val.size();i++){
        for (int j = 0; j < mat.matrix_val[0].size(); j++){
            if (j == 0 & i != 0){
                outs<<"       ";
            }
            outs <<mat.matrix_val[i][j];
            if (j != mat.matrix_val[0].size() - 1){
                outs<<",";
            }
        }
        if (i != mat.matrix_val.size() - 1)
            outs << "\n";
    }
    outs << "]\n";
    return outs;

}
/**
 * Constructor: Creating a row * col matrix filled with `elements` (mostly for 0s)
 * @param rows int row size of the matrix
 * @param col int column size of the matrix
 * @param element T& initialized value of the matrix
 */
template <typename T>
Matrix<T>::Matrix(int rows, int col, const T &elements):rowSize(rows),colSize(col){
    for (int i = 0;i < rows; i++){
        std::vector<T> matrow(col, elements);
        matrix_val.push_back(matrow);
    }
}
/**
 * Copy constructor: Creating a matrix filled with the elements in a 2D vector
 * @param mat std::vector<std::vector<T>> a 2D vector to be assign as Matrix object
 */
template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> mat):rowSize(mat.size()),colSize(mat[0].size()),matrix_val (mat){}
/**
 * Copy constructor: Assigning one matrix to another matrix
 *
 * @param mat Matrix to be copied
 */
template <typename T>
Matrix<T>::Matrix(const Matrix<T> &mat) : rowSize(mat.rowSize),colSize(mat.colSize),matrix_val(mat.matrix_val){}
/**
 * Helper function to check the validity of a muliplication, throw and exception if it is an invalid multiplication
 *
 * @param m Matrix<T> the matrix at right hand side
 */
template <typename T>
void Matrix<T>::validate_multiply(const Matrix<T> &m) {

    if (colSize != m.rowSize){
        std::ostringstream invalid_dimensions;
        invalid_dimensions<<"Cannot multiply a ("<<rowSize<<" x "<<colSize<<") matrix with a ("<<m.rowSize<<" x "<<m.colSize<<") matrix";
        throw std::invalid_argument(invalid_dimensions.str());
    }
}
/**
 * The function to multiplying two matrices
 *
 * @param mat Matrix The multiplicand matrix
 * @return Matrix The product of two matrices
 */
template <typename T>

Matrix<T> Matrix<T>::multiply(const Matrix &mat) {

    validate_multiply(mat);
    Matrix result(rowSize,mat.colSize,0.0);
    for (int i = 0;i < rowSize;i++){
        for (int j = 0; j < mat.colSize; j++){
            for (int k =0;k < colSize;k++) {
                result.matrix_val[i][j] += matrix_val[i][k] * mat.matrix_val[k][j];
            }
        }
    }
    return result;


}
/**
 *
 * The overloaded multiply function with a scalar
 * @param n int scalar multiplicand
 * @return Matrix scalar multiplication of matrix
 */
template <typename T>
Matrix<T> Matrix<T>::multiply(const int &n) {

    Matrix<T> result(matrix_val);
    for (int i = 0; i < rowSize; i++){
        for (int j = 0 ; j < colSize; j++){
            result.matrix_val[i][j] *= n;
        }
    }
    return result;
}
/**
 *
 * To return a new transposed Matrix of the original matrix
 * @return Matrix Transposed Matrix
 */
template <typename T>
Matrix<T> Matrix<T>::transpose() {
    Matrix result (colSize,rowSize,0.0);
    for (int i = 0; i < colSize; i++){
        for (int j = 0; j < rowSize; j++){
            result.matrix_val[i][j] = matrix_val[j][i];
        }
    }
    return result;

}
/**
 *
 * Supporting operator * to perform multiplication
 * @param rhs Matrix The multiplicand matrix
 * @return Matrix The product of two matrices
 */
template <typename T>
inline Matrix<T> Matrix<T>::operator* (const Matrix<T> &rhs){
    return Matrix<T>::multiply(rhs);

}
/**
 *
 * Overloaded operator * to perform multiplication with a scalar
 * @param n int The scalar multiplicand
 * @return Matrix The product of the matrix and the scalar
 */
template <typename T>
inline Matrix<T> Matrix<T>::operator* (const int &n){
    return Matrix<T>::multiply(n);

}
template<typename T>
Matrix<T>::~Matrix() {

}

