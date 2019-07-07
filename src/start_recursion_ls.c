
#include "ft_ls.h"

static int
	skeep_folder(char *name)
{
	if (ft_strcmp(name, ".") == 0)
		return (1);
	if (ft_strcmp(name, "..") == 0)
		return (1);
	return (0);
}

void start_recursion_ls(char *path, t_path_info *info, int len, char *flag)
{
	char **paths;
	int len_p;
	int i;

	len_p = 0;
	i = -1;
	while (++i < len)
		if (info[i].folder)
			len_p++;
	paths = (char **)malloc(sizeof(char *) * (len_p + 1));
	i = -1;
	len_p = -1;
	while (++i < len)
		if (info[i].folder && !skeep_folder(info[i].name))
			paths[++len_p] = ft_stradd_3(path, "/", info[i].name);
	paths[len_p + 1] = 0;
	if (is_flag_ls(flag, 'R'))
		ft_path_sort(paths);
	ft_ls_dop(paths, flag, 1);
	free_path(paths);
}
