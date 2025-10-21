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
	infile_reader(file_fd->infile_fd, get_comand());
	command_handler();
}
void	infile_reader(int fd, t_comands **cmd)
{
	int			bytes_read;
	static char	buffer[BUFFER_SIZE + 1];
	char		*tmp;
	char		*old_tmp;
	int			i;

	i = 0;
	tmp = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		old_tmp = tmp;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(tmp));
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		free(old_tmp);
		if (ft_strchr_modded(tmp, '\n'))
		{
			(*cmd)->args[i++] = tmp;
			break;
		}
	}
	if (!tmp || !(*tmp))
		return (free(tmp));
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
