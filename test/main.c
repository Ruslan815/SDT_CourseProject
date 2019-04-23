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
    const double tol= 0.0001;
    ASSERT_DBL_NEAR_TOL(expected, result,tol);
}
CTEST(square__test3, result_test)
{
    // Given
    const double x = 568.798;

    // When
    const double result = sqrt(x);

    // Then
    const double expected =23.849486;
    const double tol =0.01;
    ASSERT_DBL_NEAR_TOL(expected, result,tol);
}
