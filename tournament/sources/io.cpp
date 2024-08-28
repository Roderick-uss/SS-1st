#include <stdio.h>
#include <malloc.h>

#include "commoner.h"
#include "io.h"
#include "list_base.h"
#include "tournament.h"

enum IO_MAXES{
    MAX_LINE = 100
};

static void b_fflush() {
    for(int curr_ch = NULL; curr_ch != '\n' && curr_ch != EOF; curr_ch = getchar());
    return;
}

static FILE* enter_file_name(const char* const file_content) {
    LOG_INFO("\nEnter the name of file with %s\nIt must be with ", file_content);
    printf(".txt");
    LOG_INFO(" extension\n");

    FILE* fp = NULL;
    char* file_name = (char*)calloc((size_t)MAX_LINE, sizeof(char));

    while (fp == NULL){
        scanf("%s", file_name);
        b_fflush();
        fp = fopen(file_name, "r");

        if (fp == NULL) {
            LOG_FATAL("Incorrect input\n No such txt file(");
            printf("%s", file_name);
            LOG_FATAL(") in directory\n");
            LOG_INFO("Please try again\n");
        }
    }

    LOG_INFO("\nFile opened: ");
    printf("%s\n\n", file_name);

    FREE(file_name);

    return fp;
}

void endl() {
    printf("\n");

    return;
}

void print_cell_num(int num) {
    if      (num >  0) LOG_INFO(" %d|", num);

    else if (num == 0) LOG_INFO("  |");

    else               LOG_INFO("___");

    return;
}

void print_cell(TOURNAMENT res) {
    if (res == SPACE) printf(" X ");
    else              printf("%2d ", (int)res);

    return;
}

void run_game_error(int game_num, size_t p, const char* const error) {
    LOG_FATAL("\nGAME ");
    printf(" %d", game_num);
    LOG_FATAL(" ERROR\n%s", error);
    printf(": %3d\n", (int)p);

    return;
}

int enter_one_number(const char* const intro) {
    int num = 0;

    LOG_INFO("%s\n", intro);

    while (scanf("%d", &num) == EOF) {
        b_fflush();

        LOG_FATAL("\nIncorrect input, you can enter only a number\n");
        LOG_INFO("Please try again:\n");
    }

    return num;
}

void print_line(void* data, size_t size) {
    for(size_t i = 0; i < size; ++i) printf("%d ", *((int*)data + i));
    endl();

    return;
}

game* enter_games_file(size_t* x_size, size_t* game_num) {
    FILE* fp = enter_file_name("tournament data");

    fscanf(fp, "%llu %llu", x_size, game_num);

    game* g = (game*)calloc(*game_num, sizeof(game));

    game* game_now = NULL;

    for (size_t curr_game = 0; curr_game < *game_num; ++curr_game) {
        game_now = (game*)get_1d((void*)g, curr_game, *game_num, sizeof(game));

        fscanf(fp, "%llu %llu %d",
            &(game_now->p1),
            &(game_now->p2),
            (int*)&(game_now->res));
    }

    fclose(fp);

    return g;
}
