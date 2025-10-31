/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:39:33 by antabord          #+#    #+#             */
/*   Updated: 2025/10/31 17:14:09 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "functions.h"

typedef struct s_fd
{
	int					infile_fd;
	int					outfile_fd;
	int					fd[2];
}						t_fd;

typedef struct s_comands
{
	char				*name;
	char				**args;
	int					idx;
	struct s_comands	*next;
}						t_comands;

typedef struct s_ncmd
{
	int					n_cmds;
}						t_ncmd;

#endif