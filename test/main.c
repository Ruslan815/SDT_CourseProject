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

