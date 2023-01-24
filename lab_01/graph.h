#ifndef GRAPH_H
#define GRAPH_H

#include "QGraphicsView"

struct graphics_t
{
    QGraphicsScene *scene;
    QPen pen;
};

#include "drawing.h"

int init_graph(graphics_t& a, draw_t arg);
void delete_scene(graphics_t& a);
void set_scene(draw_t arg, graphics_t& a);

#endif // GRAPH_H
