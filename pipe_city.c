/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_city.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:35:37 by andre             #+#    #+#             */
/*   Updated: 2025/10/29 18:07:58 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"


static void execute_n_sht(t_comands *head, t_comands *lst)
{
	execve(lst->name, lst->args, get_env(NULL));
	ft_free_struct(head);
	perror("exec\n");
	exit(EXIT_FAILURE);
}


static pid_t	child_factory_and_waiting_room(int pid)
{
	pid = fork();
    //printf("forked\n");
	if (pid== -1)
		return (perror("fork\n"), -1);
	return (pid);
}

static void	close_all(int fd1, int fd2, int fd3, int fd4)
{
	if (fd1 != -1 || fd1 > 2)
        close(fd1);
    if (fd2 != -1|| fd2 > 2)
		close(fd2);
	if (fd3 != -1|| fd3 > 2)
		close(fd3);
	if (fd4 != -1|| fd4 > 2)
		close(fd4);
}

void	pipe_city(t_comands *head, int n_cmds)
{
    int			pid[n_cmds];
    int			fds[2];
    int			tmp_fd;
    int			i;
    t_comands	*lst;

    lst = head;
    i = 0;
    tmp_fd = -1;
    while (i < n_cmds)
    {
        //printf("n_cmd: %d\n", n_cmds);
        if (i != n_cmds - 1)
        {
            if (pipe(fds) == -1)
                return (perror("pipe\n"));
           // printf("piped\n");
        }
        pid[i] = child_factory_and_waiting_room(pid[i]);
        if(pid[i] == 0)
        {
            if (i == 0)
            {
                dup2(get_fd()->infile_fd, STDIN_FILENO);
                dup2(fds[1], STDOUT_FILENO);
                close_all(fds[1], get_fd()->infile_fd, -1, -1);
            }
            if (i == n_cmds - 1)
            {
                dup2(tmp_fd, STDIN_FILENO);
                dup2(get_fd()->outfile_fd, STDOUT_FILENO);
                close_all(tmp_fd, get_fd()->outfile_fd, -1, -1);
            }
            else
            {
                dup2(tmp_fd, STDIN_FILENO);
                dup2(fds[1], STDOUT_FILENO);
                close_all(-1, tmp_fd, fds[0], -1);
            }
            execute_n_sht(head, lst);
        }
        if ( i != n_cmds - 1)
        {
            close_all(fds[1], tmp_fd, -1, -1);
            tmp_fd = fds[0];
        }
        i++;
        lst = lst->next;
    }
    i = 0;
    while (i < n_cmds)
    {
        waitpid(pid[i], NULL, 0);
        i++;
    }
    if (i == n_cmds)
        close_all(tmp_fd, get_fd()->infile_fd, get_fd()->outfile_fd, -1);
}