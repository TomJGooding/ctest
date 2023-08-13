#include <stdio.h>
#include <time.h>

static clock_t start_time = -1;

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define ctest_fail()                                   \
    printf(ANSI_COLOR_RED "FAILED " ANSI_COLOR_RESET); \
    printf("%s::%s, line %d\n", __FILE__, __func__, __LINE__)

#define ctest_assert(test) \
    do {                   \
        if (!(test)) {     \
            ctest_fail();  \
            return 1;      \
        }                  \
    } while (0)

#define ctest_run_test(test)      \
    do {                          \
        if (start_time == -1) {   \
            start_time = clock(); \
        }                         \
        int failed = test();      \
        tests_run++;              \
        if (failed)               \
            return failed;        \
    } while (0)

#define ctest_report()                                                        \
    do {                                                                      \
        clock_t end_time = clock();                                           \
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; \
        printf("Ran %d tests in %0.2fs\n", tests_run, time_taken);            \
    } while (0)

extern int tests_run;
