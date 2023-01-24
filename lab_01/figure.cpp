#include "cstdio"
#include <cstdlib>
#include "figure.h"
#include "error.h"
#include "point.h"
#include "link.h"
#include "drawing.h"
#include "graph.h"
#include "operations.h"


// Init figure center
void init_fig_center(point_t& center)
{
    center.x = 0;
    center.y = 0;
    center.z = 0;
}


// Init figure points
void init_fig_points(points_data_t& points)
{
    points.n = 0;
    points.arr = NULL;
    init_fig_center(points.center);
}


// Init figure links
void init_fig_links(links_data_t& links)
{
    links.n = 0;
    links.arr = NULL;
}


// Figure init
figure_t& init()
{
    static figure_t fig;

    init_fig_points(fig.points);
    init_fig_links(fig.links);

    return fig;
}


// Free figure
void free_figure(figure_t& fig)
{
    points_free(fig.points);
    links_free(fig.links);
}


// Copy figure poins
void copy_fig_points(points_data_t& dst, points_data_t& src)
{
    dst.n = src.n;
    dst.arr = src.arr;
    dst.center = src.center;
}


// Copy figure links
void copy_fig_links(links_data_t& dst, links_data_t& src)
{
    dst.n = src.n;
    dst.arr = src.arr;
}


// Copy figure
void copy_figure(figure_t& dst, figure_t& src)
{
    copy_fig_points(dst.points, src.points);
    copy_fig_links(dst.links, src.links);
}


// Reading figure rom file
int read_figure_from_file(figure_t& fig_tmp, FILE* f)
{
    int err = process_points_in_file(fig_tmp.points, f);
    if (!err)
    {
        err = process_links_in_file(fig_tmp.links, f);
        if (err != OK)
            points_free(fig_tmp.points);
    }

    return err;
}


// Loading figure coordinates and links from file
int load_figure_from_file(figure_t& fig, load_file_t load_file)
{
    FILE *f = fopen(load_file.filename, "r");
    if (!f)
        return NO_FILE;
    figure_t fig_tmp = init();

    int err = read_figure_from_file(fig_tmp, f);
    fclose(f);

    if (!err)
    {
        free_figure(fig);
        copy_figure(fig, fig_tmp);
    }

    return err;
}


// Drawing a figure
int draw_figure(figure_t fig, draw_t arg)
{
    graphics_t a;

    int err = init_graph(a, arg);
    if (err)
        return err;

    draw_links(fig.points, fig.links, arg, a);
    set_scene(arg, a);

    return err;
}


// Figure moving
int move_figure(figure_t& fig, move_t coeff)
{
    return move_points_array(fig.points, coeff);
}


// Figure scaling
int scale_figure(figure_t& fig, scale_t coeff)
{
    return scale_points_array(fig.points, coeff);
}


// Figure turning
int turn_figure(figure_t& fig, turn_t coeff)
{
    return turn_points_array(fig.points, coeff);
}
