#include "dataset.h"
#include "agent.h"
#include "object.h"


Dataset* dataset_create(int* depths, int n_depths) {
    Dataset* dataset = ALLOCATE_OBJECT(Dataset);
    dataset->depths = depths;
    dataset->n_depths = n_depths;
    dataset->n_rows = 0;
    return dataset;
}

void dataset_destroy(Dataset** dataset_p) {
    if (dataset_p == NULL || *dataset_p == NULL) return;
    Dataset* dataset = *dataset_p;
    FREE_ARRAY(int, dataset->dephts, dataset->n_depths);
    dataset->n_depths = 0;
    dataset->n_rows = 0;
    
}
