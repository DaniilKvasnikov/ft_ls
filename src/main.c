
#include "ft_ls.h"

int
	main(int argc, char **argv)
{
	char	*flags;
	char	**paths;
	int		res;

	paths = set_paths(--argc, ++argv);
	flags = set_flags(argc, argv);
	if (is_flag_ls(flags, 'R'))
		ft_path_sort(paths);
	res = ft_ls(paths, flags);
	free_path(paths);
	free(flags);
	return (res);
}