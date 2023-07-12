#include <gtest/gtest.h>
#include "../s21_matrix.h"
#include <stdexcept>

TEST(void_sum_matrix, test1) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(2, 3);
    m2(0, 0) = 2.0;
    m2(0, 1) = 4.0;
    m2(0, 2) = 6.0;
    m2(1, 0) = 8.0;
    m2(1, 1) = 10.0;
    m2(1, 2) = 12.0;
    
    m2.SumMatrix(m1);

    S21Matrix m3(2, 3);
    m3(0, 0) = 3.0;
    m3(0, 1) = 6.0;
    m3(0, 2) = 9.0;
    m3(1, 0) = 12.0;
    m3(1, 1) = 15.0;
    m3(1, 2) = 18.0;

    EXPECT_TRUE(m2.EqMatrix(m3));
}

TEST(void_sum_matrix, test2) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(3, 3);
    m2(0, 0) = 2.0;
    m2(0, 1) = 4.0;
    m2(0, 2) = 6.0;
    m2(1, 0) = 8.0;
    m2(1, 1) = 10.0;
    m2(1, 2) = 12.0;
    m2(2, 0) = 8.0;
    m2(2, 1) = 10.0;
    m2(2, 2) = 12.0;

    try {
        m2.SumMatrix(m1);
        FAIL() << "Expected std::different matrix dimensions";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("Different matrix dimensions"));
    }
    catch(...) {
        FAIL() << "Expected std::different matrix dimensions";
    }
}