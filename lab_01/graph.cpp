#include "graph.h"
#include "error.h"


// Init graphics scene
int init_graph(graphics_t& a, draw_t arg)
{
    a.scene = new QGraphicsScene(arg.gV);
    if (!a.scene)
        return PTR_ALL_ERR;

    a.pen = QPen(Qt::black);

    return OK;
}


// Delete graphics scene
void delete_scene(graphics_t& a)
{
    delete a.scene;
}


// Set graphics scene
void set_scene(draw_t arg, graphics_t& a)
{
    a.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(arg.w, arg.h)));
    QGraphicsScene* prev = arg.gV->scene();
    delete prev;
    arg.gV->setScene(a.scene);
}
