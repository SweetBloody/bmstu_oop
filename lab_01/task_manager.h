#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "drawing.h"
#include "operations.h"

enum task
{
    INIT,
    LOAD_FILE,
    DRAW,
    MOVE,
    SCALE,
    TURN,
    QUIT
};

struct load_file_t
{
    const char* filename;
};

struct request_t
{
    task t;
    union
    {
        struct load_file_t load_f;
        struct draw_t draw;
        struct move_t move;
        struct scale_t scale;
        struct turn_t turn;
    };
};

int task_manager(request_t args);

#endif // TASK_MANAGER_H
