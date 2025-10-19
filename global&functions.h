#ifndef GLOBAL&FUNCTIONS_H
#define GLOBAL&FUNCTIONS_H

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <structs.h>

void    env_init(char **environment);
t_fd    *get_fd(void);
char    **get_env(void *env);

#endif