/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:46:07 by antabord          #+#    #+#             */
/*   Updated: 2025/10/29 17:28:54 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "functions.h"

int	main(int argc, char *argv[], char **env)
{
	t_comands *cmds;

 	if (argc < 4)
	{
		printf("not enough args\n");
		return (0);
	} 
	get_env(env);
	cmds = argument_parsing(argc, argv);
	if (!cmds)
		return (0);
	//printf("going to pipe city\n");
	pipe_city(cmds, get_ncmd()->n_cmds);
    ft_free_struct(cmds);
	return (0);
}