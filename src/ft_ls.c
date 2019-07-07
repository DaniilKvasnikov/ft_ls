
#include "ft_ls.h"

static void
	ft_print_body(char **path, char *flag, int is_recursion, int i, int path_len)
{
	t_ls_block	block;
	int			len;

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
			start_recursion_ls(path[i], block.info, len, flag);
		ft_free_ls(block.info, len);
	}
	else if (block.error == PER_DEN)
		ft_error_denied(path[i]);
	else if (block.error == ITS_FILE)
	{
		ft_print_ls(block, len, flag);
		ft_free_ls(block.info, len);
	}
}

int
	ft_ls_dop(char **path, char *flag, int is_recursion)
{
	int			i;
	int			path_len;

	if (!check_flags_ls(flag))
		return (2);
	i = -1;
	path_len = 0;
	while (path[++i] != 0)
		++path_len;
	i = -1;
	while (path[++i] != 0)
		ft_print_body(path, flag, is_recursion, i, path_len);
	return (0);
}

int
	ft_ls(char **path, char *flag)
{
	return (ft_ls_dop(path, flag, 0));
}