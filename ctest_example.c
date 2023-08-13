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

ctest_test_suite(ctest_example) {
    ctest_run_test(test_foo);
    ctest_run_test(test_bar);
    ctest_run_test(test_baz);
}

int main(int argc, char** argv) {
    ctest_run_suite(ctest_example);
    ctest_report();

    return CTEST_EXIT_CODE;
}
