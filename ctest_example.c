#include <stdio.h>
#include <time.h>

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
    ctest_run_test(test_bar);
    ctest_run_test(test_foo);
    return 0;
}

int main(int argc, char** argv) {
    clock_t start_time = clock();
    int result = all_tests();
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    if (result == 0) {
        printf(ANSI_COLOR_GREEN "ALL TESTS PASSED\n" ANSI_COLOR_RESET);
    }
    printf("Ran %d tests in %0.2fs\n", tests_run, time_taken);

    return result != 0;
}
