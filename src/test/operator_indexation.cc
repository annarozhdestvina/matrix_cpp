#include <gtest/gtest.h>
#include "../s21_matrix.h"
#include <stdexcept>

TEST(operator_indexation, test1) {
    S21Matrix m1(3, 3);
    try {
        m1(4, 4) = 0.44;
        FAIL() << "Expected std::Index is outside the matrix";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("Index is outside the matrix"));
    }
    catch(...) {
        FAIL() << "Expected std::Index is outside the matrix";
    }
}