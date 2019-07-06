
#include "ft_ls.h"

void
	ft_free_ls(t_path_info *info, int len, char *flag)
{
	int			i;

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

static int
	skeep_folder(char *name)
{
	if (ft_strcmp(name, ".") == 0)
		return (1);
	if (ft_strcmp(name, "..") == 0)
		return (1);
	return (0);
}

static void
	free_path(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i] != 0)
		free(paths[i]);
	free(paths);
}

void
	start_recursion(char *path, t_path_info *info, int len, char *flag)
{
	char	**paths;
	int		len_p;
	int		i;

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

void
	ft_error(char *path)
{
	ft_printf("%s:\n", path);
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}

void
	ft_ls_dop(char **path, char *flag, int is_recursion)
{
	int			i;
	int			len;
	t_ls_block	block;
	int			path_len;

	if (!check_flags_ls(flag))
		return ;
	i = -1;
	path_len = 0;
	while (path[++i] != 0)
		++path_len;
	i = -1;
	while (path[++i] != 0)
	{
		block = ft_print_dir(path[i], flag, &len);
		if (i > 0 || is_recursion)
			ft_printf("\n");
		if (i > 0 && is_folder_path(path[i]) && !is_folder_path(path[i - 1]))
			ft_printf("\n");
		if (block.error == 0)
		{
			if (path_len > 1 || is_recursion)
				ft_printf("%s:\n", path[i]);
			ft_print_ls(block, len, flag);
			if (is_flag_ls(flag, 'R'))
				start_recursion(path[i], block.info, len, flag);
			ft_free_ls(block.info, len, flag);
		}
		else if (block.error == PER_DEN)
			ft_error(path[i]);
		else if (block.error == ITS_FILE)
		{
			ft_print_ls(block, len, flag);
			ft_free_ls(block.info, len, flag);
		}
	}
}

void
	ft_ls(char **path, char *flag)
{
	ft_ls_dop(path, flag, 0);
}