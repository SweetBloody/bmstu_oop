#include "drawing.h"
#include "graph.h"

// Get point coord for drawing
coord_point_t get_point(int x, int y)
{
    coord_point_t p = {x, y};
    return p;
}


// Get points' coords for drawing
void get_points_for_drawing(coord_point_t* p1, coord_point_t* p2, point_t* points, link_t link)
{
    int link_p1 = link.p1;
    int link_p2 = link.p2;

    *p1 = get_point(int(points[link_p1].x), int(points[link_p1].y));
    *p2 = get_point(int(points[link_p2].x), int(points[link_p2].y));
}


// Transform coords for drawing
coord_point_t point_transform_for_drawing(coord_point_t point, draw_t arg)
{
    coord_point_t tmp;

    tmp.x = point.x + arg.w/2;
    tmp.y = point.y + arg.h/2;

    return tmp;
}


// Getting and drawing lines between points
void draw_links(points_data_t points, links_data_t links, draw_t arg, graphics_t a)
{
    coord_point_t p1, p2;

    for (int i = 0; i < links.n; i++)
    {
        get_points_for_drawing(&p1, &p2, points.arr, links.arr[i]);
        draw_line(p1, p2, a, arg);
    }
}


// Transforming and drawing lines
void draw_line(coord_point_t p1, coord_point_t p2, graphics_t a, draw_t arg)
{
    p1 = point_transform_for_drawing(p1, arg);
    p2 = point_transform_for_drawing(p2, arg);

    my_addLine(a, p1, p2);
}


// Draw line
void my_addLine(graphics_t a, coord_point_t p1, coord_point_t p2)
{
    a.scene->addLine(p1.x, p1.y, p2.x, p2.y, a.pen);
}
