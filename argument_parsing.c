/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:37:21 by antabord          #+#    #+#             */
/*   Updated: 2025/10/23 19:30:30 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "structs.h"


int	command_handler(int argc, int nb_cmd, char *argv[])
{
	int		i;
	int		j;
	char	**path;
	char	**split_args;
	
	j = 0;
	i = argc - nb_cmd - 1;
	printf("about to process comands\n");
	while (i < argc)
	{
		path = get_cmd_path(argv[i]);
		if (!path)
		{
			printf("invalid path\n");
			return (0);
		}
		printf("valid cmd: %s\n", path[j]);
		if (access(path[j], X_OK) == 0)
		{
			split_args = ft_split(argv[i], ' ');
			if (!split_args)
				return (0);
			cmds = init_cmds();
			if (!cmds)
				return (0);
			cmds->name = path[j];
			cmds->args = split_args;
			cmds->in_fd = get_fd()->infile_fd;
			cmds->out_fd = get_fd()->outfile_fd;
			cmds->idx = i;
			printf("command %d: %s\n", cmds->idx, cmds->name);
		}
	}
	return (1);
}

void	split_args(char *arg)
{
	char	**split;

	split = ft_split(arg, ' ');
}

char	**get_cmd_path(char *arg)
{
	int		i;
	int		j;
	char	*cmd;
	char	**res;
	char	**args;
	
	i = 0;
	j = 0;
	while (arg[i] == ' ')
		i++;
	while (arg[i + j] != ' ' && arg[i + j] != '\0')
		j++;
	cmd = ft_calloc(j + 2, sizeof(char));
	if (!cmd)
		return (NULL);
	cmd[0] = '/';
	if (j > 0)
		ft_strlcpy(cmd + 1, &arg[i], j + 1);
	else
		cmd[1] = '\0';
	res = get_path(cmd);
	args = ft_split(arg, ' ');
	
	free(cmd);
	return (res);
}

int	infile_handler(char **argv, int argc)
{
	t_fd	*file_fd;
	int		nb_cmd;
	int		fd;
	
	fd = 0;
	file_fd = get_fd();
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		nb_cmd = argc - 4;
		perror("herdoc detected\n");
/* 		heredoc_handler(argv[2]); */
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (perror("Cannot access infile\n"), 0);
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
		perror("Cannot access outfile\n");
		EXIT_FAILURE;
	}
	file_fd->outfile_fd = fd;
}

int	argument_parsing(int argc, char **argv)
{
	t_fd		*file_fd;
	int			nb_cmd;

	file_fd = get_fd();
	nb_cmd = infile_handler(argv, argc);
	if (!nb_cmd)
		return (0);
	printf("infie handled\n");
	command_handler(argc, nb_cmd, argv);
	//outfile_handler(argv[argc - 1]);
	
	return (1);
}
