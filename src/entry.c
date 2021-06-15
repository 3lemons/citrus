#include <stdio.h>
#include "citrusConfig.h"
#include "entry.h"

void printVersion() {
    printf("Citrus version %d.%d.%d\n", Citrus_VERSION_MAJOR, Citrus_VERSION_MINOR, Citrus_VERSION_PATCH);
    return;
}
