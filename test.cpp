/**
 * MIPT, 695 group, home-work1
 *
 * @file
 * @author Moiseeva Anastasia
 */


#include "gtest/gtest.h"
#include "main.h"

/**
 * Sorting of roots
 *
 * @param [out] x1    pointer to the first root
 * @param [out] x2    pointer to the second root
 */
void Sort_roots(double& x1, double& x2){
    if (x1 < x2) {
        double tmp = x1;
        x1 = x2;
        x2 = tmp;
    }
}

TEST(first_coefficient_is_zero, lineal1){
    double x1 = 0, x2 = 0;
    int x = Equation(0, 4, -8, &x1, &x2);
    ASSERT_EQ(1, x);
    ASSERT_EQ(2, x1);
}

TEST(first_coefficient_is_zero, lineal2){
    double x1 = 0, x2 = 0;
    int x = Equation(0, 6, 3, &x1, &x2);
    ASSERT_EQ(1, x);
    ASSERT_EQ(-0.5, x1);
}

TEST(first_coefficient_is_zero, lineal3){
    double x1 = 0, x2 = 0;
    int x = Equation(0, 5, 0, &x1, &x2);
    ASSERT_EQ(1, x);
    ASSERT_EQ(0, x1);
}

TEST(discriminant_is_zero, quadratic1){
    double x1 = 0, x2 = 0;
    int x = Equation(1, 6, 9, &x1, &x2);
    ASSERT_EQ(2, x);
    ASSERT_EQ(-3, x1);
    ASSERT_EQ(-3, x2);
}

TEST(discriminant_is_zero, quadratic2){
    double x1 = 0, x2 = 0;
    int x = Equation(16, -8, 1, &x1, &x2);
    ASSERT_EQ(2, x);
    ASSERT_EQ(0.25, x1);
    ASSERT_EQ(0.25, x2);
}

TEST(discriminant_is_zero, quadratic3){
    double x1 = 0, x2 = 0;
    int x = Equation(1, -4, 4, &x1, &x2);
    ASSERT_EQ(2, x);
    ASSERT_EQ(2, x1);
    ASSERT_EQ(2, x2);
}

TEST(discriminant_is_positive, quadratic1){
    double x1 = 0, x2 = 0;
    int x = Equation(2, 4, -7, &x1, &x2);
    ASSERT_EQ(2, x);
    Sort_roots(x1, x2);
    ASSERT_NEAR(1.12132, x1, 0.0001);
    ASSERT_NEAR(-3.12132, x2, 0.0001);
}

TEST(discriminant_is_positive, quadratic2){
    double x1 = 0, x2 = 0;
    int x = Equation(3, -6, 0, &x1, &x2);
    ASSERT_EQ(2, x);
    Sort_roots(x1, x2);
    ASSERT_EQ(2, x1);
    ASSERT_EQ(0, x2);
}

TEST(discriminant_is_positive, quadratic3){
    double x1 = 0, x2 = 0;
    int x = Equation(1, -1, -12, &x1, &x2);
    ASSERT_EQ(2, x);
    Sort_roots(x1, x2);
    ASSERT_EQ(4, x1);
    ASSERT_EQ(-3, x2);
}

TEST(discriminant_is_negative, quadratic1){
    double x1 = 0, x2 = 0;
    int x = Equation(2, 1, 3, &x1, &x2);
    ASSERT_EQ(0, x);
}

TEST(discriminant_is_negative, quadratic2){
    double x1 = 0, x2 = 0;
    int x = Equation(9, -6, 2, &x1, &x2);
    ASSERT_EQ(0, x);
}

TEST(discriminant_is_negative, quadratic3){
    double x1 = 0, x2 = 0;
    int x = Equation(2, 4, 7, &x1, &x2);
    ASSERT_EQ(0, x);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
