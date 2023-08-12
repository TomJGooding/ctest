#include <stdio.h>

#include "ctest.h"

int tests_run = 0;

int foo = 7;
int bar = 4;

int test_foo() {
    ctest_assert(foo == 7);
    return 0;
}
int test_bar() {
    ctest_assert(bar == 5);
    return 0;
}

int all_tests() {
    ctest_run_test(test_foo);
    ctest_run_test(test_bar);
    return 0;
}

int main(int argc, char** argv) {
    int result = all_tests();
    if (result == 0) {
        printf(ANSI_COLOR_GREEN "ALL TESTS PASSED\n" ANSI_COLOR_RESET);
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
