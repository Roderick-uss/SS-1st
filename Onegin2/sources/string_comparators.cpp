#include <assert.h>
#include <ctype.h>
#include <stdio.h>

#include "string_comparators.h"
#include "commoner.h"
#include "loger.h"


static void print_compare_lines(const STRING_t a, const STRING_t b, const char * const cmp_type) {
    open_log_stream();
    FILE* log_stream = get_log_stream();

    assert(a.begin);
    assert(b.begin);

 //   LOG_CERR("STARTED PRINT LONG COMPARE\n");

    fprintf(log_stream, "%s compare a, b\r\n", cmp_type);
    fprintf(log_stream, "pa =  %p, pb =  %p\r\n", a.begin, b.begin);

    fputc('\"', log_stream);
    fwrite(a.begin, sizeof(char), a.size, log_stream);
    fputc('\"', log_stream);
    fprintf(log_stream, "\r\n");

    fputc('\"', log_stream);
    fwrite(b.begin, sizeof(char), b.size, log_stream);
    fputc('\"', log_stream);
    fprintf(log_stream, "\r\n");

//    LOG_CERR("ENDED PRINT LONG COMPARE\n");
    close_log_stream();
    return;
}

static void print_diff_chars(int a, int b) {
    open_log_stream();
    FILE* log_stream = get_log_stream();

    fprintf(log_stream, "ascii a = %-3d ascii b = %d\r\n",     a, b);
    fprintf(log_stream, "char  a = %-3c char  b = %c\r\n\r\n", a, b);

    close_log_stream();
    return;
}

static int go_alnum(const STRING_t a, int ind, int incr) {
    assert(a.begin);

    while (!isalnum(a.begin[ind]) && ind * incr < (int)a.size) ind += incr;

    return ind;
}

static int my_strcmp(const STRING_t a, const STRING_t b, int incr) {
    int i_a = 0, i_b = 0;
    int curr_cmp = 0;

    do {
        i_a = go_alnum(a, i_a, incr);
        i_b = go_alnum(b, i_b, incr);

        curr_cmp = tolower(a.begin[i_a]) - tolower(b.begin[i_b]);

        i_a += incr;
        i_b += incr;
//        LOG_CERR("%c, %c\n", a.begin[i_a], *b.begin[i_b]);
    } while(!curr_cmp && incr * i_a <= (int)a.size);

    print_diff_chars(tolower(a.begin[i_a - incr]), tolower(b.begin[i_b - incr]));

    return curr_cmp;
}


int compare_strings_front(const void* a, const void* b) {
    assert(a);
    assert(b);

    STRING_t a_ = *(const STRING_t*)a;
    STRING_t b_ = *(const STRING_t*)b;
    print_compare_lines(a_, b_, "Direct");

    return my_strcmp(a_, b_, +1);
}

int compare_strings_back(const void* a, const void* b) {
    assert(a);
    assert(b);

    STRING_t a_ = *(const STRING_t*)a;
    STRING_t b_ = *(const STRING_t*)b;

    print_compare_lines(a_, b_, "Reverse");

    a_.begin += a_.size - 1;
    b_.begin += b_.size - 1;

    return my_strcmp(a_, b_, -1);
}

int my_num_cmp(const void* a, const void* b) {
    const int* a_  =(const int*)a;
    const int* b_  =(const int*)b;

    assert(a_);
    assert(b_);

    return *(const int*)a - *(const int*)b;
}
