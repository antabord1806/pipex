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
	cmds->idx = 0;
	return (cmds);
}

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

	return (&fd);
}

char	**get_path(void *arg)
{
	static char **arr;
	static int	find;
	char 	**env;
	char	*str;
	int		i;
	int		j;

	(void)arg;
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
				arr = ft_split_modded(str, ':', arg);
				/* printf("to concatenate: %s\n", (char *)arg);
				while (arr[j])
				{
					printf("%s\n", arr[j]);
					j++;
				} */
			}
			i++;
		}
	}
	return (arr);
}
