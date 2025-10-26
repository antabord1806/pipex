/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_city.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:35:37 by andre             #+#    #+#             */
/*   Updated: 2025/10/26 20:35:43 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void    pipe_city(t_comands *lst, int argc, char *argv[])
{
    int i;
    int n_cmd;
    int **pipe_fd;
    int pid[lst_size_cmd(lst)];
    t_fd fd;

    fd = get_fd(NULL);
    n_cmds = ft_lstsize_cmd(lst);
    pipe_fd = pipe_factory(lst, n_cmds);
    pid = forking(lst, n_cmds);
    if (!pipe_fd || !pid)
        return (0);
    while (pid[i])
    {
        if (pid[i] == 0)
        {
            if (pid[0])
            {
                dup2(fd->infile_fd, STDIN);
                dup2(pipe_fd[0][1], STDOUT);
                close(fd->infile_fd);
                close(pipe_fd[0][1]);
            }
            else if (i > 0 && i < ft_lstsize_cmd(lst))
            {
                dup2(pipe_fd[i - 1][0], STDIN);
                dup2(pipe_fd[i][1], STDOUT);
                close(pipe_fd[i - 1][0]);
                close(pipe_fd[i][1]);
            }
            else if (pid[ft_lstsize_cmd(lst)])
            {
                dup2(pipe_fd[i - 1][0], STDIN);
                close(pipe_fd[i - 1]);
            }
            execve(lst->name, lst->args + 1, get_env(NULL));
        }
        else
            wait();
        i++;
        lst->next = lst;
    }
}

int **pipe_factory(t_comands *lst, int n_cmds)
{
    int pipe_fd[n_cmds - 1][2];
    int i;

    i = 0;
    if (!n_cmds || n_cmds < 0)
        return (0);
    while (pipe_fd[i++])
    {
        pipe(pipe_fd[i][0]);
        pipe(pipe_fd[i][1]);
    }
    return (pipe_fd);
}

int *forking(t_comands *lst, int n_cmds)
{
    int pid[n_cmds];
    int i;

    i = 0;
    if (!n_cmds)
        return (0);
    while (pid[i++])
        pid[i] = fork();
    return (pid);
}