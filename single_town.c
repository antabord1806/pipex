#include "global&functions.h"
#include "structs.h"


static t_comands	*comand = NULL;
static size_t		comand_size = 0;

char	**get_env(void *env)
{
	static char **global_env = NULL;

	if (env != NULL)
	{
		global_env = (char **)env;
	}
	return (global_env);
}

t_fd	*get_fd(void)
{
	static t_fd fd;
	static int init = 0;

	if (!init)
	{
		ft_memset(&fd, 0, sizeof(t_fd));
		init++;
	}
	return (&fd);
}

void	init_comand(size_t n)
{
	if (comand != NULL)
		free(comand);
	comand = (t_comands *)ft_calloc(n, sizeof(t_comands));
	if (!comand)
		return ;
	comand_size = n;
}

t_comands	**get_comand(void)
{
	return (&comand);
}
