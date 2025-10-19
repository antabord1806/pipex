#include "global&functions.h"
#include "structs.h"

int	argument_parsing(int argc, char *infile, char *limiter, char *outfile)
{
	infile_handler(infile, limiter);
	outfile_handler(outfile);
	command_handler();
}

int	infile_handler(char *infile, char *limiter)
{
	t_fd *file_fd;
	int	fd;
	int	i;

	file_fd = get_fd();
	i = ft_strncmp(infile, "here_doc", 8);
	if (i == 0)
		heredoc_handler(limiter);
	else
	{
		fd = open(infile, O_RDONLY);
		if (fd != 0)
		{
			perror("Cannot access infile");
			EXIT_FAILURE;
		}
	}
	file_fd->infile_fd = fd;
}

void	outfile_handler(char *outfile)
{
	int	fd;
	t_fd *file_fd;

	file_fd = get_fd();
	fd = open(outfile, O_WRONLY);
	if (fd != 1)
	{
		perror("Cannot access outfile");
		EXIT_FAILURE;
	}
	file_fd->outfile_fd = fd;
}