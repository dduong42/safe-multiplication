# safe-multiplication
Multiplication function that knows when it overflows.

## Example

```c
#include "mul.h"

int main(void)
{
    uint64_t result;
    uint64_t a;
    uint64_t b;

    ...

    if (mul(a, b, &result)) {
        /* Overflow */
    }
    else
    {
        /* result == a * b */
    }
}

```

## Test

To launch the tests:
```
$ make
$ ./test
```
