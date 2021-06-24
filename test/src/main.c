#include <check.h>
#include <stdio.h>

START_TEST (test_name)
{
  printf("%s\n", test_name->name);/* unit test code */
}
END_TEST


int main(void) {
	return 0;
}
