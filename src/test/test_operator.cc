#include <gtest/gtest.h>
#include "../s21_matrix.h"
#include <stdexcept>

TEST(test_sum, test1){
    S21Matrix m1(2, 2);
    m1.Fill();

    S21Matrix m2(2, 2);
    m2.Fill();

    S21Matrix m3 = m1 + m2;

    S21Matrix m4(2, 2);
    m4(0, 0) = 2.0;
    m4(0, 1) = 4.0;
    m4(1, 0) = 6.0;
    m4(1, 1) = 8.0;

    EXPECT_TRUE(m3.EqMatrix(m4));
}

TEST(test_sum, test2) {
    S21Matrix m1(4, 4);
    m1.Fill();

    S21Matrix m2(4, 4);
    m2.Fill();
    m2.MulNumber(0);

    S21Matrix m3 = m1 + m2;

    S21Matrix m4(4, 4);
    m4(0, 0) = 1.0;
    m4(0, 1) = 2.0;
    m4(0, 2) = 3.0;
    m4(0, 3) = 4.0;
    m4(1, 0) = 5.0;
    m4(1, 1) = 6.0;
    m4(1, 2) = 7.0;
    m4(1, 3) = 8.0;
    m4(2, 0) = 9.0;
    m4(2, 1) = 10.0;    
    m4(2, 2) = 11.0;
    m4(2, 3) = 12.0;
    m4(3, 0) = 13.0;
    m4(3, 1) = 14.0;
    m4(3, 2) = 15.0;
    m4(3, 3) = 16.0;
    EXPECT_TRUE(m3.EqMatrix(m4));
}

TEST(test_sum, test3) {
    S21Matrix m1(4, 4);
    m1.Fill();

    S21Matrix m2(4, 4);
    m2.Fill();
    m2.MulNumber(-1);

    S21Matrix m3 = m1 + m2;

    S21Matrix m4(4, 4);
    m4(0, 0) = 0.0;
    m4(0, 1) = 0.0;
    m4(0, 2) = 0.0;
    m4(0, 3) = 0.0;
    m4(1, 0) = 0.0;
    m4(1, 1) = 0.0;
    m4(1, 2) = 0.0;
    m4(1, 3) = 0.0;
    m4(2, 0) = 0.0;
    m4(2, 1) = 0.0;    
    m4(2, 2) = 0.0;
    m4(2, 3) = 0.0;
    m4(3, 0) = 0.0;
    m4(3, 1) = 0.0;
    m4(3, 2) = 0.0;
    m4(3, 3) = 0.0;
    EXPECT_TRUE(m3.EqMatrix(m4));
}

TEST(test_sum, different_matrix_dimensions)
{
    S21Matrix m1(2, 3);
    S21Matrix m2(3, 3);
    try {
        S21Matrix m3 = m1 + m2;
        FAIL() << "Expected std::different matrix dimensions";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("Different matrix dimensions"));
    }
    catch(...) {
        FAIL() << "Expected std::different matrix dimensions";
    }
}

TEST(test_sub, test1){
    S21Matrix m1(2, 2);
    m1.Fill();

    S21Matrix m2(2, 2);
    m2.Fill();

    S21Matrix m3 = m1 - m2;

    S21Matrix m4(2, 2);
    m4(0, 0) = 0.0;
    m4(0, 1) = 0.0;
    m4(1, 0) = 0.0;
    m4(1, 1) = 0.0;

    EXPECT_TRUE(m3.EqMatrix(m4));
}

TEST(test_sub, test2) {
    S21Matrix m1(4, 4);
    m1.Fill();

    S21Matrix m2(4, 4);
    m2.Fill();
    m2.MulNumber(0);

    S21Matrix m3 = m1 - m2;

    S21Matrix m4(4, 4);
    m4(0, 0) = 1.0;
    m4(0, 1) = 2.0;
    m4(0, 2) = 3.0;
    m4(0, 3) = 4.0;
    m4(1, 0) = 5.0;
    m4(1, 1) = 6.0;
    m4(1, 2) = 7.0;
    m4(1, 3) = 8.0;
    m4(2, 0) = 9.0;
    m4(2, 1) = 10.0;    
    m4(2, 2) = 11.0;
    m4(2, 3) = 12.0;
    m4(3, 0) = 13.0;
    m4(3, 1) = 14.0;
    m4(3, 2) = 15.0;
    m4(3, 3) = 16.0;
    EXPECT_TRUE(m3.EqMatrix(m4));
}

TEST(test_sub, test3) {
    S21Matrix m1(4, 4);
    m1.Fill();

    S21Matrix m2(4, 4);
    m2.Fill();
    m2.MulNumber(2);

    S21Matrix m3 = m1 - m2;

    S21Matrix m4(4, 4);
    m4(0, 0) = -1.0;
    m4(0, 1) = -2.0;
    m4(0, 2) = -3.0;
    m4(0, 3) = -4.0;
    m4(1, 0) = -5.0;
    m4(1, 1) = -6.0;
    m4(1, 2) = -7.0;
    m4(1, 3) = -8.0;
    m4(2, 0) = -9.0;
    m4(2, 1) = -10.0;    
    m4(2, 2) = -11.0;
    m4(2, 3) = -12.0;
    m4(3, 0) = -13.0;
    m4(3, 1) = -14.0;
    m4(3, 2) = -15.0;
    m4(3, 3) = -16.0;
    EXPECT_TRUE(m3.EqMatrix(m4));
}

TEST(test_sub, different_matrix_dimensions)
{
    S21Matrix m1(2, 3);
    S21Matrix m2(3, 3);
    try {
        S21Matrix m3 = m1 - m2;
        FAIL() << "Expected std::different matrix dimensions";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("Different matrix dimensions"));
    }
    catch(...) {
        FAIL() << "Expected std::different matrix dimensions";
    }
}

TEST(test_mul_operator, test1) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(3, 2);
    m2.Fill();

    S21Matrix m3 = m1 * m2;

    S21Matrix m4(2, 2);
    m4(0, 0) = 22;
    m4(0, 1) = 28;
    m4(1, 0) = 49;
    m4(1, 1) = 64;

    EXPECT_TRUE(m3.EqMatrix(m4));

}

TEST(test_mul_operator, test2) {
    S21Matrix m1(5, 3);
    m1.Fill();

    S21Matrix m2(5, 3);
    m2(0, 0) = 0.0;
    m2(0, 1) = 0.0;
    m2(0, 2) = 0.0;
    m2(1, 0) = 0.0;
    m2(1, 1) = 0.0;
    m2(1, 2) = 0.0;
    m2(2, 0) = 0.0;
    m2(2, 1) = 0.0;
    m2(2, 2) = 0.0;
    m2(3, 0) = 0.0;
    m2(3, 1) = 0.0;
    m2(3, 2) = 0.0;
    m2(4, 0) = 0.0;
    m2(4, 1) = 0.0;
    m2(4, 2) = 0.0;

    try {
        S21Matrix m3 = m1 * m2;
        FAIL() << "Expected std::the number of columns of the first matrix does not equal the number of rows of the second matrix";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("The number of columns of the first matrix does not equal the number of rows of the second matrix"));
    }
    catch(...) {
        FAIL() << "Expected std::the number of columns of the first matrix does not equal the number of rows of the second matrix";
    }
}

TEST(test_mul_operator, test3) {
    S21Matrix m1(3, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = -1;
    m1(2, 1) = 5;
    m1(2, 2) = -1;

    S21Matrix m2(3, 3);
    m2(0, 0) = 1;
    m2(0, 1) = 2;
    m2(0, 2) = -1;
    m2(1, 0) = 3;
    m2(1, 1) = -1;
    m2(1, 2) = 4;
    m2(2, 0) = 5;
    m2(2, 1) = 6;
    m2(2, 2) = 2;

    S21Matrix m4 = m1 * m2;

    S21Matrix m3(3, 3);
    m3(0, 0) = 22;
    m3(0, 1) = 18;
    m3(0, 2) = 13;
    m3(1, 0) = 49;
    m3(1, 1) = 39;
    m3(1, 2) = 28;
    m3(2, 0) = 9;
    m3(2, 1) = -13;
    m3(2, 2) = 19;
    

    
    EXPECT_TRUE(m4.EqMatrix(m3));
}

