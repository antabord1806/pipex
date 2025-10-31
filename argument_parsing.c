/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:37:21 by antabord          #+#    #+#             */
/*   Updated: 2025/10/31 17:23:05 by antabord         ###   ########.fr       */
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

	i = argc - nb_cmd - 2;
	while (++i < argc - 1)
	{
		j = -1;
		found = 0;
		path = get_cmd_path(argv[i]);
		while (path[++j])
		{
			if (access(path[j], X_OK) == 0)
			{
				adding_to_lst(path[j], argv[i], lst);
				j = -1;
				found++;
				break ;
			}
		}
		if (!found)
			adding_to_lst(argv[i], argv[i], lst);
		ft_free_all(path);
	}
}

void	adding_to_lst(char *path, char *argv, t_comands **lst)
{
	t_comands	*cmd;
	char		**splited;
	static int	idx;

	cmd = init_cmds();
	if (!cmd)
		return (free(path));
	splited = ft_split(argv, ' ');
	if (!splited)
	{
		ft_free_all(&path);
		return ;
	}
	cmd->name = ft_strdup(path);
	cmd->args = splited;
	cmd->idx = idx;
	cmd->next = NULL;
	idx++;
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

void	outfile_handler(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Cannot access outfile\n");
		exit(-1);
	}
	get_fd()->outfile_fd = fd;
}

t_comands	*argument_parsing(int argc, char **argv)
{
	t_comands	*lst;
	int			nb_cmd;

	lst = NULL;
	nb_cmd = infile_handler(argv, argc);
	if (!nb_cmd)
		return (0);
	command_handler(argc, nb_cmd, argv, &lst);
	outfile_handler(argv[argc - 1]);
	return (lst);
}
