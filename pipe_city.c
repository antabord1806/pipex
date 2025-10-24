#include "functions.h"

void    pipe_city(t_comands *lst/* , int argc, char *argv[] */)
{
    int pid1;
    int pid2;
    int pipefd[2];
    t_fd *fd;

    fd = get_fd();
    if (pipe(pipefd) < 0)
        return ;
    pid1 = fork();
    if (pid1 < 0)
        return ;
    if (pid1 == 0)
    {
        dup2(fd->infile_fd, STDIN_FILENO);
        close(pipefd[1]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(fd->infile_fd);
        execve(lst->name, lst->args + 1, get_env(NULL));
    }
    pid2 = fork();
    if (pid2 < 0)
        return ;
    if (pid2 == 0)
    {
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        dup2(fd->outfile_fd, STDOUT_FILENO);
        close(pipefd[1]);
        close(fd->outfile_fd);
        execve(lst->next->name, lst->next->args + 1, get_env(NULL));
    }
}
