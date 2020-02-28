#include <iostream>
#include <vector>
#include "Matrix.h"
#include <gtest/gtest.h>
using namespace std;

static vector<vector<int>> identiyVector{ { 1, 0, 0 },
                                          { 0, 1, 0 },
                                          { 0, 0, 1 }};
static vector<vector<int>> squareVector { { 1, 2, 0 },
                                          { 4, 1, 5 },
                                          { 6, 5, 4 }};
static vector<vector<int>> rectVector {{1, 2, 3, 4},
                                       {5, 4, 6, 7}};
static vector<vector<int>> fourxtwoVector {{1, 2},{3, 4},
                                           {5, 4},{6, 7}};
static vector<vector<int>> twoxtwoVector{{1, 3},{4, 5}};
TEST(MatrixTest, Zeroconstrcutor){
    Matrix<int> mat1(3,3,0);
    vector<vector<int> > vect1{ { 0, 0, 0 },
                                { 0, 0, 0 },
                                { 0, 0, 0 }};
    EXPECT_EQ(mat1.matrix_val,vect1);
}
TEST(MatrixTest, VectorConstructor){

    Matrix<int> mat1 (identiyVector);
    EXPECT_EQ(mat1.matrix_val, identiyVector);
}
TEST(MatrixTest, MatrixConstructor){
    Matrix<int> mat1(identiyVector);
    Matrix<int> mat2(mat1);
    EXPECT_EQ(mat1.matrix_val,mat2.matrix_val);
}
TEST(MatrixTest, TransposeIdentityMatrixTest){
    Matrix<int> mat1(identiyVector);
    Matrix<int> mat2(mat1.transpose());
    EXPECT_EQ(mat1.matrix_val,mat2.matrix_val);
}
TEST(MatrixTest, TransposeSquareMatrixTest){
    Matrix<int> mat1 (squareVector);
    Matrix<int> mat2 (mat1.transpose());
    vector<vector<int>> TransposedSquare{{1,4,6},{2,1,5},{0,5,4}};
    EXPECT_EQ(mat2.matrix_val,TransposedSquare);
}
TEST(MatrixTest, TransposeRectMatrixTest) {
    Matrix<int> mat1 (rectVector);
    Matrix<int> mat2 (mat1.transpose());
    vector<vector<int>> TransposedSquare{{1,5},{2,4},{3,6},{4,7}};
    EXPECT_EQ(mat2.matrix_val,TransposedSquare);
}
TEST(MatrixTest, SameMatrixMultiplicationTest) {
    Matrix<int> mat1(squareVector);
    Matrix<int> mat2(mat1.multiply(mat1));
    vector<vector<int>> SameMatrixMult{{9,4, 10},{38,34, 25},{50,37,41}};
    EXPECT_EQ(mat2.matrix_val,SameMatrixMult);
}
TEST(MatrixTest, DifferentdimentionMultiplicationTest){
    Matrix<int> mat1 (fourxtwoVector);
    Matrix<int> mat2 (twoxtwoVector);
    Matrix<int> result(mat1.multiply(mat2));
    vector<vector<int>> resultVector{{9,13},{19,29},{21, 35}, {34, 53}};
    EXPECT_EQ(result.matrix_val,resultVector);
}
TEST(MatrixTest, ScalarMultiplicationTest) {
    Matrix<int> mat1 (rectVector);
    Matrix<int> result (mat1.multiply(3));
    vector<vector<int>> resultVector {{3,6,9,12},
                                      {15,12,18,21}};
    EXPECT_EQ(result.matrix_val, resultVector);
}
TEST(MatrixTest, operatorMultScalarTest) {
    Matrix<int> mat1 (rectVector);
    Matrix<int> result (mat1 * 3);
    vector<vector<int>> resultVector {{3, 6, 9, 12},
                                      {15, 12, 18, 21}};
    EXPECT_EQ(result.matrix_val, resultVector);
}

TEST(MatrixTest, operatorMultTest){
    Matrix<int> mat1 (fourxtwoVector);
    Matrix<int> mat2 (twoxtwoVector);
    Matrix<int> result(mat1 * mat2);
    vector<vector<int>> resultVector{{9, 13},{19, 29},{21, 35}, {34, 53}};
    EXPECT_EQ(result.matrix_val,resultVector);
}
TEST(MatrixTest, invalidMultiplicationReverseTest){
    Matrix<int> mat1(twoxtwoVector);
    Matrix<int> mat2(fourxtwoVector);
    EXPECT_THROW({
                     try {

                         Matrix<int> result(mat1 * mat2);
                     }
                     catch (const invalid_argument &e) {
                         stringstream error;
                         error <<"Cannot multiply a (";
                         error<<mat1.matrix_val.size()<<" x "<<mat1.matrix_val[0].size()<<") matrix with a ("<<mat2.matrix_val.size()<<" x "<<mat2.matrix_val[0].size();
                         error<< ") matrix";

                         EXPECT_EQ(error.str(),e.what());
                         throw;
                     }
                 }
    , invalid_argument);

}
TEST (MatrixTest, invalidMultiplicationTest){
    Matrix<int> mat1(rectVector);
    Matrix<int> mat2(twoxtwoVector);
    EXPECT_THROW({
                     try {

                         Matrix<int> result(mat1 * mat2);
                     }
                     catch (const invalid_argument &e) {
                         stringstream error;
                         error <<"Cannot multiply a (";
                         error<<mat1.matrix_val.size()<<" x "<<mat1.matrix_val[0].size()<<") matrix with a ("<<mat2.matrix_val.size()<<" x "<<mat2.matrix_val[0].size();
                         error<< ") matrix";

                         EXPECT_EQ(error.str(),e.what());
                         throw;
                     }
                 }
    , invalid_argument);
}





int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();



}