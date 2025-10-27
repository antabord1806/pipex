/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:55:07 by antabord          #+#    #+#             */
/*   Updated: 2025/10/27 17:10:00 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "structs.h"
#include <sys/wait.h>

void    pipenstuff(t_comands *lst)
{
    int pid1;
    int pid2;
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        return;
    }
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        return;
    }
    if (pid1 == 0)
    {
        dup2(get_fd()->infile_fd, STDIN_FILENO);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        close(get_fd()->infile_fd);
        close(get_fd()->outfile_fd);
        execve(lst->name, lst->args, get_env(NULL));
        perror("execve");
        exit(EXIT_FAILURE);
    }
    pid2 = fork();
    if (pid2 == -1)
    {
        perror("fork");
        return;
    }
    if (pid2 == 0)
    {
        dup2(pipe_fd[0], STDIN_FILENO);
        dup2(get_fd()->outfile_fd, STDOUT_FILENO);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        close(get_fd()->infile_fd);
        close(get_fd()->outfile_fd);
        execve(lst->next->name, lst->next->args, get_env(NULL));
        perror("execve");
        exit(EXIT_FAILURE);
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    close(get_fd()->infile_fd);
    close(get_fd()->outfile_fd);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}
