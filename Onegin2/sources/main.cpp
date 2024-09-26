#include <ctype.h>
#include <math.h>
#include <stdio.h>

#include "onegin_text.h"
#include "string_comparators.h"
#include "sorter.h"
#include "loger.h"
#include "commoner.h"

static const char* const LOG_TXT = "text_files/logs.txt";
static const char* const ONEGIN_WRITE = "text_files/ency_onegin.txt";

/**
 * @brief main function
 * @param argc - n of cli args
 * @param 
 *
 * @return int
 */
int main() {
    fclose(fopen(ONEGIN_WRITE, "w"));
    fclose(fopen(LOG_TXT, "w"));

    /*int a[10] = {18, 2, 7, 9, 45, 1, 2, 13, 11};
    for(int i = 0 ; i < 10; ++i) printf("%d ", a[i]);
    printf("\n");

    quic_sort(a, 10, sizeof(int), my_num_cmp);

    for(int i = 0 ; i < 10; ++i) printf("%d ", a[i]);
    printf("\n");

    return 0;*/

    Text Onegin = {};
    if (read_onegin(&Onegin)) {
        LOG_FATAL("NO PREPROCESSED FILE\n");
        free_onegin(&Onegin);
        return 1;
    }

//    print_onegin(&Onegin);

    LOG_CERR("READ ONEGIN ENDED\n\n");

    quic_sort(Onegin.lines, Onegin.n_lines, sizeof(STRING_t), compare_strings_front);
    print_onegin(&Onegin);

    LOG_CERR("FRONT SORT ENDED\n\n");

    quic_sort(Onegin.lines, Onegin.n_lines, sizeof(STRING_t), compare_strings_back);
    print_onegin(&Onegin);

    LOG_CERR("BACK  SORT ENDED\n\n");

    print_clean_onegin(&Onegin);

    free_onegin(&Onegin);

    return 0;
}
