#include <stdio.h>
#include <time.h>

static int tests_passed = 0;
static int tests_failed = 0;

static clock_t start_time = -1;

#define CTEST_EXIT_CODE tests_failed != 0

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
        if (failed) {             \
            tests_failed++;       \
        } else {                  \
            tests_passed++;       \
        }                         \
    } while (0)

#define ctest_report()                                                         \
    do {                                                                       \
        clock_t end_time = clock();                                            \
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;  \
        if (tests_failed > 0) {                                                \
            printf(                                                            \
                (ANSI_COLOR_RED "%d failed " ANSI_COLOR_RESET), tests_failed   \
            );                                                                 \
        }                                                                      \
        if (tests_passed > 0) {                                                \
            printf(                                                            \
                (ANSI_COLOR_GREEN "%d passed " ANSI_COLOR_RESET), tests_passed \
            );                                                                 \
        }                                                                      \
        printf("in %0.2fs\n", time_taken);                                     \
    } while (0)
