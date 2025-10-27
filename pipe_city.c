/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_city.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:35:37 by andre             #+#    #+#             */
/*   Updated: 2025/10/27 12:56:18 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static int	**laying_pipe(int n_cmds)
{
	int	pipe_fd[n_cmds - 1][2];
	int	i;

	i = 0;
	if (!n_cmds || n_cmds < 0)
		return (0);
	while (pipe_fd[i++])
	{
		pipe(pipe_fd[i]);
        if (pipe(pipe_fd[i]) == -1)
            return (perror("pipe\n"), NULL);
	}
	return (pipe_fd);
}

static int	*child_factory(int n_cmds)
{
	int	pid[n_cmds];
	int	i;

	i = 0;
	if (!n_cmds)
		return (0);
	while (pid[i++])
    {
		pid[i] = fork();
        if (pid[i] == -1)
            return (perror("fork\n"), NULL);
    }
	return (pid);
}
static void	child_processing(t_comands *lst, int **pipe_fd, int i)
{
    t_fd *fd;
    int i;

    j = 0;
    fd = get_fd();
	if (i == 0)
	{
		dup2(fd->infile_fd, STDIN_FILENO);
		dup2(pipe_fd[0][1], STDOUT_FILENO);
        closing_dungeon(pipe_fd[0], fd->infile_fd, i);
		close(fd->infile_fd);
		close(pipe_fd[0][1]);
	}
	else if (i > 0 && i < ft_lstsize_cmd(lst))
	{
		dup2(pipe_fd[i - 1][0], STDIN_FILENO);
		dup2(pipe_fd[i][1], STDOUT_FILENO);
		close(pipe_fd[i - 1][0]);
		close(pipe_fd[i][1]);
	}
	else if (i == ft_lstsize_cmd(lst))
	{
		dup2(pipe_fd[i - 1][0], STDIN_FILENO);
		close(pipe_fd[i - 1]);
	}
	execve(lst->name, lst->args + 1, get_env(NULL));
}

void    closing_dungeon(int *pipe_fd, int fd, int i)
{
    close(pipe_fd[i][0]);
    close(pipe_fd[i][1]);
}

int	pipe_city(t_comands *lst, int argc, char *argv[])
{
	int i;
	int n_cmd;
	int **pipe_fd;
	int *pid;
	t_fd *fd;

	fd = get_fd();
	n_cmd = ft_lstsize_cmd(lst);
	pipe_fd = laying_pipe(n_cmd);
    if (!pipe_fd)
        return ;
	pid = child_factory(n_cmd);
	if (!pid)
		return;
	while (pid[i])
	{
		if (pid[i] == 0)
            child_processing(lst, pipe_fd, i);
		else
			wait();
		i++;
		lst->next = lst;
	}
}
