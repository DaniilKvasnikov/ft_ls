
#include "ft_ls.h"

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
