#include "global&functions.h"

int	main(int argc, char *argv[], char **env)
{
	if (argc < 4)
		return (0);
	get_env(env);
	if (!argument_parsing(argc, argv))
		return (0);
	
}