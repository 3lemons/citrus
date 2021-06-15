#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

typedef enum {
	FATAL_LOG_LEVEL = 0,
	ERROR_LOG_LEVEL = 1,
	WARN_LOG_LEVEL = 2,
	INFO_LOG_LEVEL = 3,
	DEBUG_LOG_LEVEL = 4,
	TRACE_LOG_LEVEL = 5
} level;

#define WARN_ENABLED 1
#define INFO_ENABLED 1
#define DEBUG_ENABLED 1
#define TRACE_ENABLED 1

#ifndef DEBUG_ON
#undef DEBUG_ENABLED
#undef TRACE_ENABLED
#define DEBUG_ENABLED 0
#define TRACE_ENABLED 0
#endif

void log_output(level log_level, const char *func, int line, char *fmt, ...);

#define LOG_FATAL(fmt, ...) log_output(FATAL_LOG_LEVEL, __FUNCTION__, __LINE__, fmt,  __VA_ARGS__)
#define LOG_ERROR(fmt, ...) log_output(ERROR_LOG_LEVEL, __FUNCTION__, __LINE__, fmt,  __VA_ARGS__)

#if WARN_ENABLED == 1
#define LOG_WARN(fmt, ...) log_output(WARN_LOG_LEVEL, __FUNCTION__, __LINE__, fmt,  __VA_ARGS__)
#else
#define LOG_WARN(fmt, ...)
#endif

#if INFO_ENABLED == 1
#define LOG_INFO(fmt, ...) log_output(INFO_LOG_LEVEL, __FUNCTION__, __LINE__, fmt,  __VA_ARGS__)
#else
#define LOG_INFO(fmt, ...)
#endif

#if DEBUG_ENABLED == 1
#define LOG_DEBUG(fmt, ...) log_output(DEBUG_LOG_LEVEL, __FUNCTION__, __LINE__, fmt,  __VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...)
#endif

#if TRACE_ENABLED == 1
#define LOG_TRACE(fmt, ...) log_output(TRACE_LOG_LEVEL, __FUNCTION__, __LINE__, fmt,  __VA_ARGS__)
#else
#define LOG_TRACE(fmt, ...)
#endif

#endif // LOG_H_INCLUDED
