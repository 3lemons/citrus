#include <check.h>
#include <stdio.h>

START_TEST (test_name)
{
  printf("%d\n", test_name->line);
  ck_assert_int_eq(5, 5);
}
END_TEST


int main(void) {
	return 0;
}
