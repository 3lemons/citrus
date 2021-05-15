#include <stdio.h>
#include "citrusConfig.h"

void printVersion() {
    printf("Citrus version %d.%d.%d\n", Citrus_VERSION_MAJOR, Citrus_VERSION_MINOR, Citrus_VERSION_PATCH);
    return;
}

int main() {
    printVersion();
    return 0;
}