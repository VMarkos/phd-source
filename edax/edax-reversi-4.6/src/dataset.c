#include <stdlib.h>
#include "dataset.h"
#include "agent.h"
#include "object.h"


Dataset* dataset_create(size_t* depths, size_t n_depths) {
    Dataset* dataset = ALLOCATE_OBJECT(Dataset);
    dataset->depths = depths;
    dataset->n_depths = n_depths;
    dataset->n_rows = 0;
    return dataset;
}

void dataset_destroy(Dataset** dataset_p) {
    if (dataset_p == NULL || *dataset_p == NULL) return;
    Dataset* dataset = *dataset_p;
    FREE_ARRAY(size_t, dataset->depths, dataset->n_depths);
    FREE_OBJECT_ARRAY(Row, dataset->rows, dataset->n_rows);
    dataset->n_depths = 0;
    dataset->n_rows = 0;
    free(dataset);
    dataset_p = NULL;
}

void dataset_add_row(Dataset* dataset, Row* row) {
    *(dataset->rows + (dataset->n_rows++)) = row;
}

void dataset_add_row(Dataset* dataset, uint64_t player, uint64_t opponent, int* moves) {
    Row* row = row_create(player, opponent, moves);
    dataset_add_row(dataset, row);
}

void dataset_write(Dataset* dataset, const char* file) {
    FILE* dataset_fp = fopen(file, "wb");
    if (dataset_fp == NULL) exit(1);
    /* Write first number of rows and columns as two integers
     * Then write the actual depths
     * Then write each row
     */
    safe_fwrite(&dataset->rows, sizeof(size_t), 1, dataset_fp);
    safe_fwrite(&dataset->n_depths, sizeof(size_t), 1, dataset_fp); 
    safe_fwrite(dataset->depths, sizeof(size_t), dataset->n_depths, dataset_fp);
    for (int i = 0; i < dataset->rows; i++)
        row_write(dataset->rows + i, dataset_fp);
    fclose(dataset_fp);
}

void dataset_read(Dataset* dataset, const char* file) {
    FILE* dataset_fp = fopen(file, "rb");
    if (dataset_fp == NULL) exit(1);
    rewind(dataset_fp);
    long offset = 0;
    safe_fread(&dataset->n_rows, sizeof(size_t), 1, dataset_fp);
    offset += sizeof(size_t);
    safe_offset_read(&dataset->n_depths, sizeof(size_t), 1, dataset_fp, offset);
    offset += sizeof(size_t);
    safe_offset_read(&dataset->depths, sizeof(int), dataset->n_depths, dataset_fp, offset);
    offset += sizeof(int) * dataset->n_depths;
    safe_offset_read(&dataset->rows, sizeof(Row), dataset->n_rows, dataset_fp, offset);
    fclose(dataset_fp);
}

// Rows

Row* row_create(uint64_t player, uint64_t opponent, int* moves) {
    Row* row = ALLOCATE_OBJECT(Row);
    row->player = player;
    row->opponent = opponent;
    row->moves = ALLOCATE_ARRAY(int, MAX_MOVES);
    return row;
}

void row_destroy(Row** row_p) {
    if (row_p == NULL || *row_p == NULL) return;
    Row* row = *row_p;
    row->player = 0;
    row->opponent = 0;
    FREE_ARRAY(int, row->moves, MAX_MOVES);
    free(row);
    row_p = NULL;
}

void row_write(Row* row, FILE* fp) {
    // Does not own fp
    safe_fwrite(row->player, sizeof(uint64_t), 1, fp);
    safe_fwrite(row->opponent, sizeof(uint64_t), 1, fp);
    safe_fwrite(row->moves, sizeof(int), MAX_MOVES, fp);
}
