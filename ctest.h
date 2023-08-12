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

#define ctest_run_test(test) \
    do {                     \
        int failed = test(); \
        tests_run++;         \
        if (failed)          \
            return failed;   \
    } while (0)

extern int tests_run;
