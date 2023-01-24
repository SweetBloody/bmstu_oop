#ifndef FIGURE_H
#define FIGURE_H
#include "point.h"
#include "link.h"
#include "drawing.h"
#include "operations.h"
#include "task_manager.h"

struct figure_t
{
    points_data_t points;
    links_data_t links;
};

void init_fig_points(points_data_t& points);
void init_fig_links(links_data_t& links);
figure_t& init();
void free_figure(figure_t& fig);
void copy_fig_points(points_data_t& dst, points_data_t& src);
void copy_fig_links(links_data_t& dst, links_data_t& src);
void copy_figure(figure_t& fig, figure_t& tmp);
int read_figure_from_file(figure_t& fig_tmp, FILE* f);
int load_figure_from_file(figure_t& fig, load_file_t load_file);

int draw_figure(figure_t fig, draw_t arg);

int move_figure(figure_t& fig, move_t coeff);
int scale_figure(figure_t& fig, scale_t coeff);
int turn_figure(figure_t& fig, turn_t coeff);

#endif // FIGURE_H
