
#include "ft_ls.h"

void
	free_path(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i] != 0)
		free(paths[i]);
	free(paths);
}

void
	ft_free_ls(t_path_info *info, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		free(info[i].mode);
		free(info[i].time);
	}
	if (len > 0)
	{
		free(info);
	}
}
