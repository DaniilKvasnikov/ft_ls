
#include "ft_ls.h"

int
	is_link(t_stat buff)
{
	return ((buff.st_mode & S_IFMT) == S_IFLNK);
}

int
	is_link_path(char *path)
{
	t_stat buff;
	
	stat(path, &buff);
	return (is_link(buff));
}
