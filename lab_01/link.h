#ifndef CONNECTION_H
#define CONNECTION_H
#include "point.h"

struct link_t
{
    int p1;
    int p2;
};

struct links_data_t
{
    int n;
    link_t *arr;
};

int links_alloc(links_data_t& connections, int len);
void links_free(links_data_t& connections);
int read_link(link_t* joints, FILE* f);
int read_links(links_data_t& connections, FILE* f);
int process_links_in_file(links_data_t& connections, FILE* f);

#endif // CONNECTION_H
