#include <assert.h>
#include <stdio.h>

#include "loger.h"

static FILE* log_stream = NULL;
static const char* const LOG_TXT = "text_files/logs.txt";

FILE* get_log_stream() {
    assert(log_stream);

    return log_stream;
}

void open_log_stream() {
    log_stream = fopen(LOG_TXT, "ab");
    assert(log_stream);
}

void close_log_stream() {
    fclose(log_stream);
    log_stream = NULL;
}
