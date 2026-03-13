#ifndef DATASET_H
#define DATASET_H

#define MΑΧ_MOVES 60

typedef struct Dataset {
    Row* rows; // Row objects
    size_t* depths; // Dephts used (i.e., column names)
    size_t n_rows;
    size_t n_depths;
} Dataset;

typedef struct Row {
    uint64_t player, opponent; // bitboard
    int* moves; // array of moves as integers
} Row;

Dataset* dataset_create(size_t*, size_t);
void dataset_destroy(Dataset**);
void dataset_add_row(Dataseet*, Row*);
void dataset_write(Dataset*, const char*);

Row* row_create(uint64_t, uint64_t, int*);
void row_destroy(Row**);
void row_write(Row*, FILE*);

#endif
