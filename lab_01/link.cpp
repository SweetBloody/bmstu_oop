#include "cstdio"
#include <cstdlib>
#include "link.h"
#include "figure.h"
#include "error.h"
#include "io.h"


// Allocate memory for figure links
int links_alloc(links_data_t& links, int len)
{
    links.n = len;

    links.arr = (link_t*) calloc(len, sizeof(link_t));
    if (!links.arr)
        return PTR_ALL_ERR;

    return OK;
}


// Free memory for figure links
void links_free(links_data_t& links)
{
    links.n = 0;
    if (links.arr)
        free(links.arr);
}


// Read figure link from file
int read_link(link_t* link, FILE* f)
{
    if (fscanf(f, "%d%d", &link->p1, &link->p2) != 2)
        return FILE_FORMAT_ERR;

    return OK;
}


// Read figure links from file
int read_links(links_data_t& links, FILE* f)
{
    int err = OK;
    for (int i = 0; !err && i < links.n; i++)
    {
        if (read_link(&links.arr[i], f))
            err = FILE_FORMAT_ERR;
    }

    return err;
}


// Read part with links in file
int process_links_in_file(links_data_t& links, FILE* f)
{
    int n;
    int err = OK;

    err = read_amount(&n, f);
    if (!err)
    {
        if (n)
            err = links_alloc(links, n);
        else
            err = NO_LINKS;

        if (!err)
        {
            if ((err = read_links(links, f)) == FILE_FORMAT_ERR)
                links_free(links);
        }
    }
    return err;
}
