#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
#include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//#define NULL ((void *)0)

// init & gets
void		env_init(char **environment);
t_fd		*get_fd(void);
t_ncmd		*get_ncmd(void);
char		**get_env(void *env);
t_comands	*init_cmds(void);
char		**get_path(void *arg);
int			ft_lstsize_cmd(t_comands *lst);

// parsing
t_comands	*argument_parsing(int argc, char **argv);
int			infile_handler(char **argv, int argc);
void		outfile_handler(char *outfile);
char		**get_cmd_path(char *arg);
void		adding_to_lst(char *path, char *argv, t_comands **lst);
void		pipe_city(t_comands *lst, int n_cmds);
void		ft_lstadd_back_cmd(t_comands **lst, t_comands *new);
int			ft_lstsize_cmd(t_comands *lst);

void		pipenstuff(t_comands *lst);
void		ft_free_struct(t_comands *cmd);

#endif