#ifndef COLOR_H
#define COLOR_H

#define GREEN "\033[32m"
#define WHITE "\033[37m"
#define RED "\033[31m"

#define LOG_FATAL(str, ...) printf(RED str WHITE __VA_OPT__(,) __VA_ARGS__)
#define LOG_INFO(str, ...) printf(GREEN str WHITE __VA_OPT__(,) __VA_ARGS__)

#endif // COLOR_H
