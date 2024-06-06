#include <stdio.h>
#include "record.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

int randint(int low, int high) {
    if (low == high)
        return low;
    return low + rand() % (high - low);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("User generator [file name] [size].\n");
        return 0xDEAD;
    }

    uint64_t size;

    if (sscanf(argv[2], "%lu", &size) != 1) {
        printf("Size should be a positive decimal.\n");
    }

    srand(time(NULL));

    FILE *file = fopen(argv[1], "w");
    

    for (uint64_t i = 0; i < size; i++) {
        struct record_s record = {0};

        record.semester = randint(1, 8);
        sprintf(record.name, "Dzimka Lemiashonak %lu", i);
        sprintf(record.address, "Vulica Pushkina Dom Kolotushkina %lu", i);

            
        fwrite(&record, sizeof(record), 1, file);
    }

    fclose(file);
}