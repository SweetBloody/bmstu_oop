#include "cstdio"
#include <cstdlib>
#include "point.h"
#include "figure.h"
#include "error.h"
#include "io.h"


// Allocate memory for figure points
int points_alloc(points_data_t& points, int len)
{
    points.n = len;
    points.arr = (point_t*) calloc(len, sizeof(point_t));

    if (!points.arr)
        return PTR_ALL_ERR;

    return OK;
}


// Free center
void center_free(point_t* center)
{
    center->x = 0;
    center->y = 0;
    center->z = 0;
}


// Free memory for figure points
void points_free(points_data_t& points)
{
    points.n = 0;
    center_free(&points.center);
    if (points.arr)
        free(points.arr);
}


// Read figure point from file
int read_point(point_t* point, FILE* f)
{
    if (fscanf(f, "%lf%lf%lf", &point->x, &point->y, &point->z) != 3)
        return FILE_FORMAT_ERR;

    return OK;
}


// Read figure points from file
int read_points(points_data_t& points, FILE* f)
{
    int err = OK;

    if (read_point(&points.center, f))
        err = FILE_FORMAT_ERR;

    for (int i = 0; !err && i < points.n; i++)
    {
        if (read_point(&points.arr[i], f))
            err = FILE_FORMAT_ERR;
    }
    return err;
}


// Read part with points in file
int process_points_in_file(points_data_t& points, FILE* f)
{
    int n;
    int err = OK;

    err = read_amount(&n, f);
    if (!err)
    {
        if (n)
            err = points_alloc(points, n);
        else
            err = NO_DATA;

        if (!err)
        {
            if ((err = read_points(points, f)) == FILE_FORMAT_ERR)
                points_free(points);
        }
    }
    return err;
}
