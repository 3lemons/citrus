#include "log.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

static const char *log_levels[] = {
	"FATAL",
	"ERROR",
	"WARN",
	"INFO",
	"DEBUG",
	"TRACE"
};

void log_output(level log_level, const char *func, int line, char *fmt, ...) {
	// Log message limited to 500 characters. But this is quicker than dynamic memory allocation
	size_t buffSize = 500;
	char buff[buffSize];
	char *buffPtr = (char *) memset(buff, 0, buffSize);
	va_list argptr;
	va_start(argptr, fmt);
	if(vsnprintf(buffPtr, buffSize, fmt, argptr) > 0) {
		printf("[%s] %s:%d - %s\n", log_levels[log_level], func, line, buffPtr);
	} else {
		printf("[%s] LOGGING FAILED", log_levels[0]);
	}
	va_end(argptr);
}

