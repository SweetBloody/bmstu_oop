#ifndef POINT_H
#define POINT_H

#include <cstdio>

struct point_t
{
    double x;
    double y;
    double z;
};

struct points_data_t
{
    int n;
    point_t* arr;
    point_t center;
};

int points_alloc(points_data_t& pts, int len);
void points_free(points_data_t& pts);

int read_point(point_t* dot, FILE* f);
int read_points(points_data_t& pts, FILE* f);
int process_points_in_file(points_data_t& pts, FILE* f);

#endif // POINT_H
