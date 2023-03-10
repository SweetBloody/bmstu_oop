#include <cstdio>
#include "error.h"


// Reading amount of points in figure
int read_amount(int* n, FILE* f)
{
    int err = OK;

    if (fscanf(f, "%d", n) != 1)
        err = FILE_FORMAT_ERR;

    if (*n <= 0)
        err = FILE_CONTENT_ERR;

    return err;
}
