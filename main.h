/**
 * MIPT, 695 group, home-work1
 *
 * @file
 * @author Moiseeva Anastasia
 */


#ifndef main_h
#define main_h

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
 */
int Equation(const double a, const double b, const double c, double* x1, double* x2);

#endif