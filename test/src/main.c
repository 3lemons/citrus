#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
/* A test case that does nothing and succeeds. */
static void placeholder_test(void **state) {
    int i = 4;
    assert_int_equal(4, i);
    (void) state; /* unused */
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(placeholder_test),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}