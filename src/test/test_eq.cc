#include <gtest/gtest.h>

#include "../s21_matrix.h"

TEST(my_tests_eq, test1) {
    S21Matrix m1(3, 4);
    m1.Fill();

    S21Matrix m2(3, 4);
    m2.Fill();


    EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(my_tests, test2) {
    EXPECT_EQ(true, false);
}

TEST(my_tests_false, test1) {
    EXPECT_EQ(true, true);
    EXPECT_TRUE(false);
}

