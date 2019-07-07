
#include "ft_ls.h"

void
	ft_stat(char *path, t_stat *buff)
{
	if (!is_link_path(path))
		stat(path, buff);
	else
		lstat(path, buff);
}