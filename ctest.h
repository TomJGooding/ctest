#define ctest_fail() printf("FAILED %s, line %d\n", __func__, __LINE__)

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
