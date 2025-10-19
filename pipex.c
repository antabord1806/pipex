#include "global&functions.h"

int	main(int argc, char *argv[], char **env)
{
	if (argc < 4)
		return (0);
	get_env(env);
	argument_parsing(argc, argv[1], argv[2], argv[argc - 1]);
}