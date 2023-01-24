#ifndef DRAWING_H
#define DRAWING_H
#include "QGraphicsView"
#include "point.h"
#include "link.h"

struct draw_t
{
    QGraphicsView *gV;
    int w;
    int h;
};

struct coord_point_t
{
    int x;
    int y;
};

#include "graph.h"

void get_points_for_drawing(coord_point_t* p1, coord_point_t* p2, point_t* points, link_t link);
coord_point_t point_transform_for_drawing(coord_point_t point, draw_t arg);
void draw_links(points_data_t points, links_data_t links, draw_t arg, graphics_t a);
void draw_line(coord_point_t p1, coord_point_t p2, graphics_t a, draw_t arg);
void my_addLine(graphics_t a, coord_point_t p1, coord_point_t p2);

#endif // DRAWING_H
