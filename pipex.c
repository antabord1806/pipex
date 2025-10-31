/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:46:07 by antabord          #+#    #+#             */
/*   Updated: 2025/10/31 17:13:58 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char *argv[], char **env)
{
	t_comands	*cmds;

	if (argc < 4)
	{
		printf("not enough args\n");
		return (0);
	}
	get_env(env);
	get_fd()->infile_fd = -1;
	get_fd()->outfile_fd = -1;
	get_fd()->fd[0] = -1;
	get_fd()->fd[1] = -1;
	cmds = argument_parsing(argc, argv);
	if (!cmds)
		return (0);
	pipe_city(cmds, get_fd());
	ft_free_struct(cmds);
	return (0);
}
