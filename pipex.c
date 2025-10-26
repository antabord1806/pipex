#include "functions.h"

int	main(int argc, char *argv[], char **env)
{
	t_comands *cmds;

	if (argc < 4)
	{
		printf("not enough args\n");
		return (0);
	}
	get_env(env);
	cmds = argument_parsing(argc, argv);
	if (!cmds)
		return (0);
	pipe_city(cmds, argc, argv);
	return (0);
}