#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// init & gets
void		env_init(char **environment);
t_fd		*get_fd(void);
char		**get_env(void *env);
t_comands	*init_cmds(void);
char		**get_path(void *arg);

// parsing
t_comands	*argument_parsing(int argc, char **argv);
int			infile_handler(char **argv, int argc);
void		outfile_handler(char *outfile);
char		**get_cmd_path(char *arg);
void		adding_to_lst(char *path, char *argv, t_comands **lst);
void		pipe_city(t_comands *lst/*, int argc, char *argv[]) */);

#endif