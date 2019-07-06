
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
	is_folder(t_stat buff)
{
	return ((buff.st_mode & S_IFMT) == S_IFDIR);
}

int
	is_folder_path(char *path)
{
	t_stat buff;
	
	stat(path, &buff);
	return (is_folder(buff));
}

void
	ft_path_sort(char	**paths)
{
	t_stat		buff1;
	t_stat		buff2;
	int			i;
	char		*tmp;

	i = -1;
	while (paths[++i] != 0)
	{
		if (paths[i + 1] == 0)
			return ;
		stat(paths[i], &buff1);
		stat(paths[i + 1], &buff2);
		if (is_folder(buff1) && !is_folder(buff2))
		{
			tmp = paths[i];
			paths[i] = paths[i + 1];
			paths[i + 1] = tmp;
			i = -1;
		}
	}
}

int
	main(int argc, char **argv)
{
	char	*flags;
	char	**paths;
	int		i;

	paths = set_paths(--argc, ++argv);
	flags = set_flags(argc, argv);
	if (is_flag_ls(flags, 'R'))
		ft_path_sort(paths);
	ft_ls(paths, flags);
	free_flag_path(flags, paths);
	return (0);
}