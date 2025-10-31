/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:46:07 by antabord          #+#    #+#             */
/*   Updated: 2025/10/31 19:36:45 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char *argv[], char **env)
{
	t_comands	*cmds;
	char	**environment;

	environment = get_env(env);
	if (argc < 4)
	{
		printf("not enough args\n");
		return (0);
	}
	if (!environment[0] || !environment)
		return (write(2, "env\n", 4), exit(EXIT_FAILURE), 0);
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
