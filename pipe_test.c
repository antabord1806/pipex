/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:55:07 by antabord          #+#    #+#             */
/*   Updated: 2025/10/27 17:41:23 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "structs.h"

void	pipenstuff(t_comands *lst)
{
	int pid1;
	int pid2;
	int pipe_fd[2];
	// int pipe_tmp;

	if (pipe(pipe_fd) == -1)
		return (perror("pipe\n"));
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork\n"));
	if (pid1 == 0)
	{
		dup2(get_fd()->infile_fd, STDIN_FILENO);
		close(get_fd()->infile_fd);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		execve(lst->name, lst->args, get_env(NULL));
		printf("exec1\n");
		EXIT_FAILURE;
	}
	lst = lst->next;
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork\n"));
	if (pid2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		dup2(get_fd()->outfile_fd, STDOUT_FILENO);
		close(get_fd()->outfile_fd);
		execve(lst->name, lst->args, get_env(NULL));
		printf("exec2\n");
		EXIT_FAILURE;
	}
	else
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}