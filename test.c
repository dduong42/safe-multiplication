#include <stdio.h>
#include "mul.h"

void assert_equal(uint64_t expected, uint64_t got, int line)
{
    if (expected != got)
    {
        fprintf(stderr, "Error in line: %d\n", line);
        fprintf(stderr, "expected: %ld\n", expected);
        fprintf(stderr, "got: %ld\n", got);
    }
}

void assert_true(int statement, int line)
{
    if (!statement)
    {
        fprintf(stderr, "Error in line: %d\n", line);
        fprintf(stderr, "Expected to be true\n");
    }
}

int main(void)
{
    uint64_t result;

    assert_true(!mul(2, 4, &result), __LINE__);
    assert_equal(8, result, __LINE__);

    assert_true(!mul(0, 0, &result), __LINE__);
    assert_equal(0, result, __LINE__);

    assert_true(!mul(0, 42, &result), __LINE__);
    assert_equal(0, result, __LINE__);

    assert_true(mul(2, UINT64_MAX, &result), __LINE__);

    assert_true(!mul(1, UINT64_MAX, &result), __LINE__);
    assert_equal(UINT64_MAX, result, __LINE__);
    return (0);
}
