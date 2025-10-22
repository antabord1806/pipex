/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:37:21 by antabord          #+#    #+#             */
/*   Updated: 2025/10/22 17:17:36 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global&functions.h"
#include "structs.h"

int	argument_parsing(int argc, char **argv)
{
	t_fd		*file_fd;
	int			nb_cmd;

	file_fd = get_fd();
	nb_cmd = infile_handler(argv, argc);
	if (!nb_cmd)
		return (0);
	if (!command_handler(argc, nb_cmd, argv))
		return (0);
	outfile_handler(argv[argc - 1]);
}

static int	command_handler(int argc, int nb_cmd, char *argv[])
{
	int		i;
	int		j;
	char	**path;

	j = 0;
	i = argc - nb_cmd;
	while (i < argc)
	{
		path = get_cmd_path(argv[i]);
		if (!path)
			return (0);
		if (access(path[j], X_OK) < 0)
			return (perror("invalid comand"), ft_free_all(path), 0);
		i++;
	}
}

static char	**get_cmd_path(char *arg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arg[i] == ' ')
		i++;
	while (arg[i] != ' ')
		j++;
	arg[j + i] = '\0';
	return (get_path(arg[j]));

}

static int	infile_handler(char **argv, int argc)
{
	t_fd	*file_fd;
	int		nb_cmd;
	int		fd;
	int		i;

	file_fd = get_fd();
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		nb_cmd = argc - 4;
		heredoc_handler(argv[2]);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != 0)
			return (perror("Cannot access infile"), 0);
		nb_cmd = argc - 3;
	}
	file_fd->infile_fd = fd;
	return (nb_cmd);
}

void	outfile_handler(char *outfile)
{
	int		fd;
	t_fd	*file_fd;

	file_fd = get_fd();
	fd = open(outfile, O_WRONLY);
	if (fd != 1)
	{
		perror("Cannot access outfile");
		EXIT_FAILURE;
	}
	file_fd->outfile_fd = fd;
}
