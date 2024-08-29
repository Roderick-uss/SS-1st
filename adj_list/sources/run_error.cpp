#include <stdio.h>
#include <assert.h>

#include "commoner.h"
#include "run_error.h"

void run_memory_error(size_t size) {
    LOG_FATAL("MEMORY ERROR\n Can not assign memory: ");
    printf("%llu", size);
    LOG_FATAL(" b.");

    assert(0);

    return;
}
