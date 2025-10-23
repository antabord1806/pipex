#ifndef STRUCTS_H
#define STRUCTS_H

#include "functions.h"
typedef struct s_fd
{
    int infile_fd;
    int outfile_fd;
}   t_fd;

typedef struct s_comands
{
    char    *name;
    char    **args;
    int     idx;
    int     in_fd;
    int     out_fd;
    t_comands  *next;
}   t_comands;

#endif