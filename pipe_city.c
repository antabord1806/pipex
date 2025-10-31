/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_city.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:35:37 by andre             #+#    #+#             */
/*   Updated: 2025/10/31 16:23:03 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static void	execute_cmd(t_comands *cmd, int in, int out, t_fd *fds)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(out, STDOUT_FILENO);
		close(out);
		dup2(in, STDIN_FILENO);
		close(in);
		if (cmd->next)
		{
			close(fds->outfile_fd);
			close(fds->fd[0]);
		}
		execve(cmd->name, cmd->args, get_env(NULL));
		perror("exec\n");
		exit(EXIT_FAILURE);
	}
	close(in);
	close(out);
}

int	close_fd(int oldfd, int fd)
{
	close(oldfd);
	return (fd);
}

void	wait_all(t_comands *cmd)
{
	while (cmd)
	{
		wait(NULL);
		cmd = cmd->next;
	}
}

void	pipe_city(t_comands *head, t_fd *fds)
{
	t_comands	*cmd;
	int			in;
	int			out;

	in = fds->infile_fd;
	cmd = head;
	while (cmd)
	{
		out = dup(1);
		if (cmd->next)
		{
			pipe(fds->fd);
			out = close_fd(out, fds->fd[1]);
		}
		else
			out = close_fd(out, fds->outfile_fd);
		execute_cmd(cmd, in, out, fds);
		in = close_fd(in, fds->fd[0]);
		cmd = cmd->next;
	}
	wait_all(head);
}
