#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/fizzbuzz.h"
#include "check.h"

START_TEST(test_check)
{
    ck_assert_str_eq("", "");
}

START_TEST(test_fizzbuzz_normal)
{
    char buf[BUFSIZE];

    int min = (int)(floor(SHRT_MIN / 15.) * 15);
    int max = (int)(ceil(SHRT_MAX / 15.) * 15);

    for (int i = min; i <= max; i += 15) {
        fizzbuzz(i, buf);
        ck_assert_str_eq(buf, "FIZZBUZZ");
    }
}

START_TEST(test_fizz_normal)
{
    char buf[BUFSIZE];

    int min = (int)(floor(SHRT_MIN / 3.) * 3);
    int max = (int)(ceil(SHRT_MAX / 3.) * 3);

    for (int i = min; i <= max; i += 3) {
        if (i % 5 == 0) {
            continue;
        }
        fizzbuzz(i, buf);
        ck_assert_str_eq(buf, "FIZZ");
    }
}

START_TEST(test_buzz_normal)
{
    char buf[BUFSIZE];

    int min = (int)(floor(SHRT_MIN / 5.) * 5);
    int max = (int)(ceil(SHRT_MAX / 5.) * 5);

    for (int i = min; i <= max; i += 5) {
        if (i % 5 == 0) {
            continue;
        }
        fizzbuzz(i, buf);
        ck_assert_str_eq(buf, "FIZZ");
    }
}

Suite *fizzbuzz_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("fizzbuzz");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_check);
    tcase_add_test(tc_core, test_fizzbuzz_normal);
    tcase_add_test(tc_core, test_fizz_normal);
    tcase_add_test(tc_core, test_buzz_normal);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s  = fizzbuzz_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
