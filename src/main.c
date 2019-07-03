
#include "ft_ls.h"

static void
	free_flag_path(char *flags, char **paths)
{
	int	i;

	i = -1;
	while (paths[++i] != 0)
		free(paths[i]);
	free(paths);
	free(flags);
}

int
	main(int argc, char **argv)
{
	char	*flags;
	char	**paths;
	int		i;

	paths = set_paths(--argc, ++argv);
	flags = set_flags(argc, argv);
	ft_ls(paths, flags);
	free_flag_path(flags, paths);
	return (0);
}