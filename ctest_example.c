#include <stdio.h>

#include "ctest.h"

int foo = 1;
int bar = 2;
int baz = 3;

int test_foo() {
    ctest_assert(foo == 99);
    return 0;
}

int test_bar() {
    ctest_assert(bar == 2);
    return 0;
}

int test_baz() {
    ctest_assert(baz == 99);
    return 0;
}

int all_tests() {
    ctest_run_test(test_foo);
    ctest_run_test(test_bar);
    ctest_run_test(test_baz);
    return 0;
}

int main(int argc, char** argv) {
    all_tests();
    ctest_report();

    return CTEST_EXIT_CODE;
}
