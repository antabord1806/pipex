#include "global&functions.h"
#include "structs.h"

int	argument_parsing(int argc, char *infile, char *limiter, char *outfile)
{
	t_fd	*file_fd;
	t_comands **comands;
	int		nb_cmd;

	file_fd = get_fd();

	nb_cmd = infile_handler(infile, limiter, argc);
	if (!nb_cmd)
		return (0);
	
	init_comand(nb_cmd);
	outfile_handler(outfile);
	command_handler();
}

static int	infile_handler(char *infile, char *limiter, int argc)
{
	t_fd	*file_fd;
	int		nb_cmd;
	int		fd;
	int		i;

	file_fd = get_fd();
	i = ft_strncmp(infile, "here_doc", 8);
	if (i == 0)
	{
		nb_cmd = argc - 4;
		heredoc_handler(limiter);
	}
	else
	{
		fd = open(infile, O_RDONLY);
		if (fd != 0)
		{
			perror("Cannot access infile");
			EXIT_FAILURE;
		}
		nb_cmd = argc - 3;
	}
	file_fd->infile_fd = fd;
	return (nb_cmd);
}

void	outfile_handler(char *outfile)
{
	int		fd;
	t_fd	*file_fd;

	file_fd = get_fd();
	fd = open(outfile, O_WRONLY);
	if (fd != 1)
	{
		perror("Cannot access outfile");
		EXIT_FAILURE;
	}
	file_fd->outfile_fd = fd;
}
