#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>
#include <stdarg.h>

namespace Log {

    static void info(const char *format, ...) {
        va_list args;
        fprintf(stdout, "[INFO] ");
        va_start(args, format);
        vfprintf(stdout, format, args);
        va_end(args);
        fprintf(stdout, "\n");
    }

    static void warn(const char *format, ...) {
        va_list args;
        fprintf(stdout, "[WARN] ");
        va_start(args, format);
        vfprintf(stdout, format, args);
        va_end(args);
        fprintf(stdout, "\n");
    }

    static void error(const char *format, ...) {
        va_list args;
        fprintf(stderr, "[ERROR] ");
        va_start(args, format);
        vfprintf(stderr, format, args);
        va_end(args);
        fprintf(stderr, "\n");
    }

}

#endif // !_LOG_H
