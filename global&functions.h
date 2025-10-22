#ifndef GLOBAL &FUNCTIONS_H
# define GLOBAL &FUNCTIONS_H

# include <fcntl.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <structs.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void		env_init(char **environment);
t_fd		*get_fd(void);
char		**get_env(void *env);
t_comands	*cmd(void);
char		**get_path(void *arg);

#endif