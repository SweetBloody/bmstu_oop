#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "point.h"

struct move_t
{
    int dx;
    int dy;
    int dz;
};

struct scale_t
{
    double kx;
    double ky;
    double kz;
};

struct turn_t
{
    int ox;
    int oy;
    int oz;
};
void move_points_to_center(point_t* points, point_t center, int len);
void move_points_from_center(point_t* points, point_t center, int len);
void move_point(point_t& point, move_t coeff);
int move_points_array(points_data_t& points, move_t coeff);

void scale_point(point_t& point, scale_t coeff);
int scale_points_array(points_data_t points, scale_t coeff);

double d_cos(double angle);
double d_sin(double angle);

void x_turn_point(point_t& point, double angle);
void y_turn_point(point_t& point, double angle);
void z_turn_point(point_t& point, double angle);
int turn_points_array(points_data_t points, turn_t coeff);

#endif // OPERATIONS_H
