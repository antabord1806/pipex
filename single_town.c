#include "global&functions.h"
#include "structs.h"

char	**get_env(void *env)
{
	static char **global_env = NULL;

	if (env != NULL)
		global_env = (char **)env;
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

char	**get_path(void *arg)
{
	static char **arr = NULL;
	static int	find = 0;
	char 	**env;
	char	*str;
	int		i;

	str = 0;
	i = 0;
	env = get_env(NULL);
	if (!find)
	{
		while (env[i])
		{
			if (!ft_strncmp(env[i], "PATH=", 5))
			{
				str = ft_strnstr_modded(env[i], "PATH=");
				arr = ft_split_modded(str, ":", arg);
			}
			i++;
		}
	}
	return (arr);
}
