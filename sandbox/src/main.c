#include <stdio.h>
#include <entry.h>
#include <log.h>

int main(int argc, char *argv[]) {
	printVersion();
	LOG_INFO("Hello %s", "world");
	return 0;
}
