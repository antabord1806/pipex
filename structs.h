#ifndef STRUCTS_H
#define STRUCTS_H

#include <global&functions.h>
typedef struct s_fd
{
    int infile_fd;
    int outfile_fd;
}   t_fd;

typedef struct s_comands
{
    char    *name;
    char    **args;
    int     read_fd;
    int     out_fd;
}   t_comands;

#endif