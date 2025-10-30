/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_city.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:35:37 by andre             #+#    #+#             */
/*   Updated: 2025/10/30 19:16:55 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"


static void execute_cmd(t_comands *cmd, int in, int out)
{
	// printf("args: %s in: %i out: %i\n", cmd->args[0], in, out);
	int pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(out, STDOUT_FILENO);
		close(out);
		dup2(in, STDIN_FILENO);
		close(in);
		execve(cmd->name, cmd->args, get_env(NULL));
		perror("exec\n");
		exit(EXIT_FAILURE);
	}
	close(in);
	close(out);
}


pid_t	child_factory_and_waiting_room(int pid)
{
	pid = fork();
    //printf("forked\n");
	if (pid== -1)
		return (perror("fork\n"), -1);
	return (pid);
}

/* void	close_all(void)
{
	if (get_fd()->infile_fd != -1 )
        close(get_fd()->infile_fd);
    if (get_fd()->outfile_fd != -1)
		close(get_fd()->outfile_fd);
	// if (fd3 != -1 &&fd3 > 2)
	// 	close(fd3);
	// if (fd4 != -1 && fd4 > 2)
	// 	close(fd4);
} */

int close_fd(int oldfd, int fd)
{
	close(oldfd);
	return (fd);
}

void wait_all(t_comands *cmd)
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
	int in = fds->infile_fd;
	int out;

    cmd = head;
	printf("fin: %i\n", fds->infile_fd);
    while (cmd)
    {
		out = dup(1);
		if (cmd->next)
		{	
			pipe(fds->fd);
			out = close_fd(out, fds->fd[1]);
		} else
			out = close_fd(out, fds->outfile_fd);
		execute_cmd(cmd, in, out);
		in = close_fd(in, fds->fd[0]);
        cmd = cmd->next;
    }
   wait_all(head);
}
