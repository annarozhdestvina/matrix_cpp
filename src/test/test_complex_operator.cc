#include <gtest/gtest.h>
#include "../s21_matrix.h"
#include <stdexcept>

TEST(complex_sum_operator, test1) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(2, 3);
    m2 += m1;

    m2.Print();

    S21Matrix m3(2, 3);
    m3(0, 0) = 0.0;
    m3(0, 1) = 0.0;
    m3(0, 2) = 0.0;
    m3(1, 0) = 0.0;
    m3(1, 1) = 0.0;
    m3(1, 2) = 0.0;

    EXPECT_TRUE(m2.EqMatrix(m3));

}

TEST(complex_sum_operator, test2) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(3, 3);

    try {
        m2 += m1;
        FAIL() << "Expected std::different matrix dimensions";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("Different matrix dimensions"));
    }
    catch(...) {
        FAIL() << "Expected std::different matrix dimensions";
    }
}

TEST(complex_sum_operator, test3) {
    S21Matrix m1(2, 3);
    m1.Fill();

    S21Matrix m2(2, 3);
    m2.Fill();
    m2 += m1;
    m2.Print();

    S21Matrix m3(2, 3);
    m3(0, 0) = 2.0;
    m3(0, 1) = 4.0;
    m3(0, 2) = 6.0;
    m3(1, 0) = 8.0;
    m3(1, 1) = 10.0;
    m3(1, 2) = 12.0;

    m3.Print();

    EXPECT_TRUE(m2.EqMatrix(m3));
}