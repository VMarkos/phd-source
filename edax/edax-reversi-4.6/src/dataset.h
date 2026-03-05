#ifndef DATASET_H
#define DATASET_H

typedef struct Dataset {
    Row* rows; // Row objects
    int* depths; // Dephts used (i.e., column names)
    int n_rows;
    int n_depths;
} Dataset;

typedef struct Row {
    uint64_t player, opponent; // bitboard
    int* moves; // array of moves as integers
} Row;

Dataset* dataset_create(int*, int);
void dataset_destroy(Dataset**);

#endif
