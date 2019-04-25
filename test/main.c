#define CTEST_MAIN
#define CTEST_COLOR_OK
#include <ctest.h>
#include <foo.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(square__test, result_test)
{
    // Given
    const double x = 169;

    // When
    const double result = sqrt(x);

    // Then
    const double expected = 13;
    ASSERT_EQUAL(expected, result);
}

CTEST(square__test2, result_test)
{
    // Given
    const double x = 156;

    // When
    const double result = sqrt(x);

    // Then
    const double expected = 12.489996;
    const double tol = 0.0001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}
CTEST(square__test3, result_test)
{
    // Given
    const double x = 568.798;

    // When
    const double result = sqrt(x);

    // Then
    const double expected = 23.849486;
    const double tol = 0.0001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}
CTEST(percent_test, result_test)
{
    // Given
    const double x = 6;
    const double n = 50;

    // When
    const double result = percent(x, n);

    // Then
    const double expected = 3;
    ASSERT_EQUAL(expected, result);
}
CTEST(persent__test2, result_test)
{
    // Given
    const double x = 354.768;
    const double n = 23;

    // When
    const double result = percent(x, n);

    // Then
    const double expected = 81.59664;
    const double tol = 0.00001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}
CTEST(persent__test3, result_test)
{
    // Given
    const double x = 586807.687;
    const double n = 97.67;

    // When
    const double result = percent(x, n);

    // Then
    const double expected = 573135.068;
    const double tol = 0.001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}
CTEST(persent__test4, result_test)
{
    // Given
    const double x = -7849.965;
    const double n = 349;

    // When
    const double result = percent(x, n);

    // Then
    const double expected = -27396.3778;
    const double tol = 0.0001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}
CTEST(calc_plus_test1, result_test)
{
    // Given
    const double num1 = 159;
    const double num2 = 248;
    const char s = '+';

    // When
    const double result = calc(num1, num2, s);

    // Then
    const double expected = 407;
    ASSERT_EQUAL(expected, result);
}
CTEST(calc_plus_test2, result_test)
{
    // Given
    const double num1 = -19.275;
    const double num2 = -62.8863;
    const char s = '+';

    // When
    const double result = calc(num1, num2, s);

    // Then
    const double expected = -82.1613;
    const double tol = 0.0001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}
CTEST(calc_minus_test1, result_test)
{
    // Given
    const double num1 = 76;
    const double num2 = 121;
    const char s = '-';

    // When
    const double result = calc(num1, num2, s);

    // Then
    const double expected = -45;
    ASSERT_EQUAL(expected, result);
}
CTEST(calc_minus_test2, result_test)
{
    // Given
    const double num1 = 53.414;
    const double num2 = -74.1543;
    const char s = '-';

    // When
    const double result = calc(num1, num2, s);

    // Then
    const double expected = 127.568;
    const double tol = 0.001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}
CTEST(calc_multy_test1, result_test)
{
    // Given
    const double num1 = -65;
    const double num2 = -34;
    const char s = '*';

    // When
    const double result = calc(num1, num2, s);

    // Then
    const double expected = 2210;
    ASSERT_EQUAL(expected, result);
}
CTEST(calc_multy_test2, result_test)
{
    // Given
    const double num1 = 0.14241;
    const double num2 = 543;
    const char s = '*';

    // When
    const double result = calc(num1, num2, s);

    // Then
    const double expected = 77.3286;
    const double tol = 0.0001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}
CTEST(calc_divide_test1, result_test)
{
    // Given
    const double num1 = 42;
    const double num2 = 7;
    const char s = '/';

    // When
    const double result = calc(num1, num2, s);

    // Then
    const double expected = 6;
    ASSERT_EQUAL(expected, result);
}
CTEST(calc_divide_test2, result_test)
{
    // Given
    const double num1 = 53.25;
    const double num2 = -84.12;
    const char s = '/';

    // When
    const double result = calc(num1, num2, s);

    // Then
    const double expected = -0.633024;
    const double tol = 0.000001;
    ASSERT_DBL_NEAR_TOL(expected, result, tol);
}
