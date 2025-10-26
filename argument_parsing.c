/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:37:21 by antabord          #+#    #+#             */
/*   Updated: 2025/10/26 20:35:07 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "structs.h"

void	command_handler(int argc, int nb_cmd, char *argv[], t_comands **lst)
{
	int		i;
	int		j;
	char	**path;
	int		found;

	j = -1;
	i = argc - nb_cmd - 2;
	found = 0;
	while (++i < argc)
	{
		path = get_cmd_path(argv[i]);
		if (!path)
			return (ft_free_all(path));
		while (path[++j])
		{
			if (access(path[j], X_OK) == 0)
			{
				adding_to_lst(path[j], argv[i], lst);
				j = 0;
				found++;
				break;
			}
		}
		if (!found)
			return (perror("invalid cmd\n"), ft_free_all(path));
	}
}

void	adding_to_lst(char *path, char *argv, t_comands **lst)
{
	t_comands	*cmd;
	char		**splited;
	static int	idx = 0;
	int		i;

	i = 0;
	cmd = init_cmds();
	if (!cmd)
		return (free(path));
	splited = ft_split(argv, ' ');
	if (!splited)
	{
		free(cmd);
		return ;
	}
	cmd->name = path;
	cmd->args = splited;
	cmd->idx = idx;
	cmd->next = NULL;
	idx++;
	printf("name: %s\n", cmd->name);
	while (splited[i])
	{
		printf("args: %s\n", cmd->args[i]);
		i++;
	}
	printf("ids: %d\n", cmd->idx);
	ft_lstadd_back_cmd(lst, cmd);
}

char	**get_cmd_path(char *arg)
{
	int		i;
	int		j;
	char	*cmd;
	char	**res;

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

t_comands	*argument_parsing(int argc, char **argv)
{
	t_fd		*file_fd;
	t_comands	*lst;
	int			nb_cmd;

	lst = NULL;
	file_fd = get_fd();
	nb_cmd = infile_handler(argv, argc);
	if (!nb_cmd)
		return (0);
	printf("infile handled\n");
	command_handler(argc, nb_cmd, argv, &lst);
	outfile_handler(argv[argc - 1]);
	return (lst);
}


