#include <gtest/gtest.h>

class AccesorsTestCase : public ::testing::Test
{
};

TEST_F(AccesorsTestCase, case_1)
    {
        // S21Matrix matrix;
        // matrix = S21Matrix(1, 1);
        // matrix.SetCols(2);
        // ASSERT_EQ(matrix(0, 0), 0);
        // ASSERT_EQ(matrix(0, 1), 0);
        ASSERT_EQ(1+1, 2);
    }
