/**
 * MIPT, 695 group, home-work1
 *
 * @file
 * @author Moiseeva Anastasia
 */


#include <iostream>
#include <cmath>
#include <assert.h>
#include <limits>

/**
 * Solving of linear equation
 *
 * @param [in]  b     the second coefficient
 * @param [in]  c     the third coefficient
 * @param [out] x1    pointer to the root
 */
void Solve_linear_equation(double b, double c, double* x1){
    *x1 = -c/b;
}

/**
 * Solving of quadratic equation
 *
 * @param [in]   a              the first coefficient
 * @param [in]   b              the second coefficient
 * @param [in]  discriminant    the discriminant of equation
 * @param [out] x1              pointer to the first root
 * @param [out] x2              pointer to the second root
 *
 * @note a shouldn't be zero
 */
void Solve_quadratic_equation(const double a, const double b, const double discriminant, double* x1, double* x2){
    *x1 = (-b + sqrt(discriminant))/(2*a);
    *x2 = (-b - sqrt(discriminant))/(2*a);
}

/**
 * Calculation of the discriminant
 *
 * @param [in] a    the first coefficient
 * @param [in] b    the second coefficient
 * @param [in] c    the third coefficient
 *
 * @return the value of the discriminat
 *
 * @note a shouldn't be zero
 */
double Find_discriminant(const double a, const double b, const double c){
    return b*b - 4*a*c;
}

/**
 * Solving the equation
 *
 * @param [in]  a    the first coefficient
 * @param [in]  b    the second coefficient
 * @param [in]  c    the third coefficient
 * @param [out] x1   pointer to the first root
 * @param [out] x2   pointer to the second root
 *
 * @return the number of roots
 *
 * @note In case of infinite number of roots, returns maximum integer value.
 */
int Equation(const double a, const double b, const double c, double* x1, double* x2){
    assert (std::isfinite(a));
    assert (std::isfinite(b));
    assert (std::isfinite(c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1!=x2);
    const double discriminant = Find_discriminant(a, b, c);
    if (!(std::fabs(a - 0) < std::numeric_limits<double>::epsilon())  && !(discriminant < 0)) {
     /* well well well, double number is compared without epsilon, it is violation of the every fundamental rules together, 
        plz check unless anybody sees it */
        Solve_quadratic_equation(a, b, discriminant, x1, x2);
        return 2;
    }
    if (a == 0) {
        if (b == 0 && c == 0){
            return std::numeric_limits<int>::max();
        }
        Solve_linear_equation(b, c, x1);
        return 1;
    }
    return 0;
}
