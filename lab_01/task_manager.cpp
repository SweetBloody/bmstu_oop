#include "task_manager.h"
#include "error.h"
#include "operations.h"
#include "figure.h"


// Process of requests
int task_manager(request_t req)
{
    static figure_t fig = init();
    int err = OK;

    switch (req.t)
    {
    case INIT:
        break;
    case LOAD_FILE:
        err = load_figure_from_file(fig, req.load_f);
        break;
    case DRAW:
        err = draw_figure(fig, req.draw);
        break;
    case MOVE:
        err = move_figure(fig, req.move);
        break;
    case SCALE:
        err = scale_figure(fig, req.scale);
        break;
    case TURN:
        err = turn_figure(fig, req.turn);
        break;
    case QUIT:
        free_figure(fig);
        break;
    default:
        err = UNKNOWN_COMMAND;
    }

    return err;
}
