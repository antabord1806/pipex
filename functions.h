/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:39:25 by antabord          #+#    #+#             */
/*   Updated: 2025/10/31 17:10:27 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "libft/libft.h"
# include "structs.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

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
void		ft_lstadd_back_cmd(t_comands **lst, t_comands *new);
int			ft_lstsize_cmd(t_comands *lst);

int			heredoc_handler(char *limiter);
void		pipe_city(t_comands *lst, t_fd *fds);
void		pipenstuff(t_comands *lst);
void		ft_free_struct(t_comands *cmd);
void		close_all(t_fd *fd);

#endif