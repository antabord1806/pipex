#include "global&functions.h"
#include "structs.h"

char **get_env(void *env)
{
    static char **global_env = NULL;

    if (env != NULL)
    {
        global_env = (char **)env;
    }
    return global_env;
}

t_fd  *get_fd(void)
{
    static t_fd fd;
    static int  init = 0;

    if (!init)
    {
        ft_memset(&fd, 0, sizeof(t_fd));
        init++;
    }
    return (&fd);
}

t_comand  *get_comand(void)
{
    static t_comand comand;
    static int  init = 0;

    if (!init)
    {
        ft_memset(comand, 0, sizeof(t_comand));
        init++;
    }
    return (comand);
}
