/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:55:07 by antabord          #+#    #+#             */
/*   Updated: 2025/10/28 16:09:16 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "structs.h"

void	pipenstuff(t_comands *head)
{
	int pid1;
	int pid2;
	int pipe_fd[2];
	// int pipe_tmp;
	t_comands *lst;
	
	lst = head;
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
		close(get_fd()->outfile_fd);
		ft_free_struct(head);
		perror("exec1\n");
		exit(EXIT_FAILURE);
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
		close(get_fd()->infile_fd);
		ft_free_struct(head);
		perror("exec2\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		close(get_fd()->infile_fd);
		close(get_fd()->outfile_fd);
	}
}