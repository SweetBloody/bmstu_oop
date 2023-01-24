#define _USE_MATH_DEFINES
#include <math.h>
#include "operations.h"
#include "error.h"
#include "figure.h"


// Change point coords for moving
void move_point(point_t& point, move_t coeff)
{
    point.x += coeff.dx;
    point.y += coeff.dy;
    point.z += coeff.dz;
}


// Change points array for moving
int move_points_array(points_data_t& points, move_t coeff)
{
    if(!points.arr)
        return NO_DATA;
    int err = OK;

    for(int i = 0; i < points.n; i++)
        move_point(points.arr[i], coeff);

    move_point(points.center, coeff);

    return err;
}


// Change point coords for scaling
void scale_point(point_t& point, scale_t coeff)
{
    point.x *= coeff.kx;
    point.y *= coeff.ky;
    point.z *= coeff.kz;
}


// Change point array for scaling
int scale_points_array(points_data_t points, scale_t coeff)
{
    if(!points.arr)
        return NO_DATA;
    int err = OK;

    move_points_to_center(points.arr, points.center, points.n);

    for(int i = 0; i < points.n; i++)
        scale_point(points.arr[i], coeff);

    move_points_from_center(points.arr, points.center, points.n);

    return err;
}


// Cos in degrees
double d_cos(double angle)
{
    return cos(angle * M_PI / 180);
}


// Sin in degrees
double d_sin(double angle)
{
    return sin(angle * M_PI / 180);
}


// Turning point around X
void x_turn_point(point_t& point, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);
    double temp_point_y = point.y;

    point.y = point.y * cos_ang - point.z * sin_ang;
    point.z = temp_point_y * sin_ang + point.z * cos_ang;
}


// Turning point around Y
void y_turn_point(point_t& point, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);
    double temp_point_x = point.x;

    point.x = point.x * cos_ang + point.z * sin_ang;
    point.z = -temp_point_x * sin_ang + point.z * cos_ang;
}


// Turning point around Z
void z_turn_point(point_t& point, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);
    double temp_point_x = point.x;

    point.x = point.x * cos_ang - point.y * sin_ang;
    point.y = temp_point_x * sin_ang + point.y * cos_ang;
}


// Move point to center
void move_point_to_center(point_t& point, point_t center)
{
    point.x -= center.x;
    point.y -= center.y;
    point.z -= center.z;
}


// Move points to the center
void move_points_to_center(point_t* points, point_t center, int len)
{
    for(int i = 0; i < len; i++)
        move_point_to_center(points[i], center);
}


// Move point from center
void move_point_from_center(point_t& point, point_t center)
{
    point.x += center.x;
    point.y += center.y;
    point.z += center.z;
}


// Move points from the center
void move_points_from_center(point_t* points, point_t center, int len)
{
    for(int i = 0; i < len; i++)
        move_point_from_center(points[i], center);
}


// Turn every point
void turn_points(point_t* points, turn_t coeff, int n)
{
    for(int i = 0; i < n; i++)
    {
        x_turn_point(points[i], coeff.ox);
        y_turn_point(points[i], coeff.oy);
        z_turn_point(points[i], coeff.oz);
    }
}


// Change point array for turning
int turn_points_array(points_data_t points, turn_t coeff)
{
    if(!points.arr)
        return NO_DATA;
    int err = OK;

    move_points_to_center(points.arr, points.center, points.n);
    turn_points(points.arr, coeff, points.n);
    move_points_from_center(points.arr, points.center, points.n);

    return err;
}
