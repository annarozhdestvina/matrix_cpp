#include <gtest/gtest.h>
#include "../s21_matrix.h"

TEST(move_operator_eq, test1) {
    S21Matrix m1(3, 4);
    m1.Fill();

    S21Matrix copied(m1);

    S21Matrix moved(3, 5);
    moved = std::move(m1);

    EXPECT_TRUE(copied.EqMatrix(moved));

    EXPECT_EQ(0, m1.GetRow());
    EXPECT_EQ(0, m1.GetCol());
}