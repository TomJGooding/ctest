# ctest.h

A simple header-only testing framework for C.

## Usage

Example of a simple test using `ctest.h`:

```c
#include "ctest.h"

int inc(int x) {
    return x + 1;
}

int test_answer() {
    ctest_assert(inc(3) == 5);
    return 0;
}

ctest_test_suite(ctest_example) {
    ctest_run_test(test_answer);
}

int main(void) {
    ctest_run_suite(ctest_example);
    ctest_report();

    return CTEST_EXIT_CODE;
}
```

## Acknowledgements

- Based on [MinUnit](https://jera.com/techinfo/jtns/jtn002) and
  [this blog post by Eric Radman](https://eradman.com/posts/tdd-in-c.html)
- Test report style based on [pytest](https://pytest.org/)

## Licence

Licensed under the [GNU General Public License v3.0](LICENSE).
