#include "functions.h"

int	main(int argc, char *argv[], char **env)
{
	if (argc < 4)
	{
		printf("not enough args\n");
		return (0);
	}
	get_env(env);
	if (!argument_parsing(argc, argc))
		return (0);
	return (0);
}