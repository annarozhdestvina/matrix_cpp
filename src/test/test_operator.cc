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

