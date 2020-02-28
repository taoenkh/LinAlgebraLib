# Matrix Library

A C++ Linear Algebra Library support matrix multiplication and transpose


## Getting Started

### Prerequisites

Before using the library, please make sure `g++` and `cmake` are installed.

### Running the unit test

The unit testing of this project utlizes `Google test` 

#### Option 1 Using `Clion`

Running this project on `Clion` only requires `file` ->`open` and `Run LinAlgebra` to run the unit tests on `Clion`

#### Option 2 Using `Terminal` under `MacOS` or `Linux`

1. `cmake .` to generate the make file and `Google test` dependencies (if this step failed, rerun `cmake .` to get the dependencies)
2. run `make` to run the `Makefile`
3. run `./LinAlgebra` to run the executable program of the unit tests.

## Documentation
### Constructing a Matrix object
The Matrix Library has three ways to create a matrix, and the elements in the matrix can be `int`, `float`, or `double` type.
```Matrix<int>, Matrix<float>, Matrix<double>```
1. Filling the `m x n` matrix with a certain number

    * `Matrix<int> matrix(3, 3, 0);` will create a 3 * 3 matrix with all zeros.
    * `Matrix<int> matrix(3, 3, 1);` will create a 3 * 3 matrix with all ones.

2. Assigning a 2D vector to `Matrix`
    * Assume `std::vector<std::vector> vector = {{1, 2, 3}, {4, 5, 6}};` (vector is a 2 * 3 2D vector) 

         `Matrix<int> matrix(vector);` to assign the 2D vector to `Matrix` object in order to do multiplication and transpose operations.
3. Assigning a `Matrix` to another `Matrix`

    * `Matrix<int> result (mat1 * mat2);` assigning the product of two matrices to `result`
    
 

### Transpose

```$xslt
 Matrix<int> mat1 = matrix.transpose();
```
Since `matrix` was assigned to ```{{1, 2, 3}, {4, 5, 6}}```, `mat1` will be `{{1, 4}, {2, 5}, {3, 6}}`.
### Multiplication

This library supports both matrix multiple by a scalar and matrix multiple by matrix.

For both Scalar and Matrix multiplication, multiplication can be done directly using `operator *`, or `Matrix.multiply()` function.

#### Matrix * Scalar
```$xslt
std::vector<std::vector<int>> vector1 = {{1, 2, 3}, {4, 5, 6}}; 
Matrix<int> mat1 (vector);
Matrix<int> result(mat1.multiply(3));
>>> Matrix [ 3,  6,  9,
            12, 15, 18 ]
```

#### Matrix * Matrix
Matrix1 * Matrix2 must obey the rule of row number 1 must be same as column number 2

A (r1 * c1) matrix x (r2 * c2) matrix will produce a matrix with dimension of (r1 * c2), where c1 must be equal to r2.
```$xslt
std::vector<std::vector<int>> vectA = {{1, 2}, {3, 4}, {5, 4}, {6, 7}};
Matrix<int> a(vectA);
std::vector<std::vector<int>> vectB = {{1, 3},{4, 5}};
Matrix<int> b(vectB);

Matrix<int> result (a * b);
>>> Matrix[ 9, 13
           19, 29
           21, 35
           34, 53]

```
However `b * a` will throw an `Exception`, since it violates the rule of matrix multiplication `(2, 2) * (4, 2)` where `4 != 2`.
### Operator <<

For better debugging purpose, Matrices can be outputed using `cout<<` to check the elements inside a `Matrix`.


```$xslt
std::cout<<result;

>>> Matrix[ 9, 13
           19, 29
           21, 35
           34, 53]

```
