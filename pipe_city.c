/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_city.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:35:37 by andre             #+#    #+#             */
/*   Updated: 2025/10/28 18:11:42 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	pipe_city(t_comands *head, int n_cmds)
{
	int			pid[n_cmds];
	int			fds[2];
	int			tmp_fd;
	int			i;
	t_comands	*lst;

	lst = head;
	i = 0;
	while (pid[i])
	{
		if (i != n_cmds)
		{
			if (pipe(fds[0] == -1))
				perror("pipe\n");
		}
		pid[i] = child_factory_and_waiting_room(pid[i], true);
		if(pid[i] == 0)
		{
			if (i == 0)
			{
				dup2(get_fd()->infile_fd, STDIN_FILENO);
				dup2(fds[1], STDOUT_FILENO);
				close_all(fds[1], get_fd()->infile_fd, -1, -1);
				execute_n_sht(head, lst);
			}
			if (i > 0 && i < n_cmds)
			{
				dup2(tmp_fd, STDIN_FILENO);
				dup2(fds[1], STDOUT_FILENO);
				close_all(fds[1], tmp_fd, -1, -1);
				execute_n_sht(head, lst);
			}
			if (i == n_cmds)
			{
				dup2(tmp_fd, STDIN_FILENO);
				dup2(get_fd()->outfile_fd, STDOUT_FILENO);
				close_all(tmp_fd, get_fd()->outfile_fd, -1, -1);
				execute_n_sht(head, lst);
			}
		else
		{
			close_all(0, 1, -1, -1);
			child_factory_and_waiting_room(NULL, false);
			tmp_fd = fds[0];
			i++;
		}
		lst = lst->next;
		}
	}
}

void	execute_n_sht(t_comands *head, t_comands *lst)
{
	execve(lst->name, lst->args, get_env(NULL));
	ft_free_struct(head);
	perror("exec\n");
	exit(EXIT_FAILURE);
}


pid_t	child_factory_and_waiting_room(int pid, bool making_baby)
{
	int status;
	
	if (making_baby)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork\n");
			return (-1);
		}
		return (pid);
	}
	else
		waitpid(-1, &status, 0);
}

void	close_all(int fd1, int fd2, int fd3, int fd4)
{
	int	i;

	i = 0;
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
	if (fd3 != -1)
		close(fd3);
	if (fd4 != -1)
		close(fd4);
}
