#include "functions.h"
#include "structs.h"

t_comands *init_cmds(void)
{
	t_comands *cmds;

	cmds = malloc(sizeof(t_comands));
	if (!cmds)
		return (NULL);
	cmds->name = NULL;
	cmds->args = NULL;
	cmds->in_fd = 0;
	cmds->out_fd = 0;
	cmds->idx = 0;
	return (cmds);
}

char	**get_env(void *env)
{
	static char **global_env = NULL;

	if (env != NULL)
		global_env = (char **)env;
	printf("got env\n");
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
	int		j;

	str = 0;
	i = 0;
	j = 0;
	env = get_env(NULL);
	if (!find)
	{
		while (env[i])
		{
			if (!ft_strncmp(env[i], "PATH=", 5))
			{
				str = ft_strnstr_modded(env[i], "PATH=");
				printf("to concatenate: %s\n", (char *)arg);
				arr = ft_split_modded(str, ':', arg);
				while (arr[j])
				{
					printf("%s\n", arr[j]);
					j++;
				}
			}
			i++;
		}
	}
	return (arr);
}
