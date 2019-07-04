
#include "ft_ls.h"

#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>

void
	change_mod(char *mod, int c)
{
	int		len;

	mod[0] = (c >> 2 & 1) + '0';
	mod[1] = (c >> 1 & 1) + '0';
	mod[2] = (c & 1) + '0';
}

char
	*get_mod(char *mod)
{
	char	*res;
	int		len;

	res = ft_strdup("drwxrwxrwx");
	if (mod[0] == '1')
		res[0] = '-';
	len = ft_strlen(mod);
	change_mod(res + 1, mod[len - 3]);
	// return (mod);
	return (res);
}

t_path_info
	get_info(char *path)
{
	struct stat buff;
	t_path_info	res;
	char		*str;

	stat(path, &buff);
	str = ft_rebase(buff.st_mode, 8);
	res.mode = get_mod(str);
	res.name = path;
	return (res);
}

static int
	ft_count_dir(char *path)
{
	DIR			*dir;
	t_dirent	*entry;
	int			i;
	int			len;

	dir = opendir(path);
	if (!dir)
		return (-1);
	i = 0;
	while ( (entry = readdir(dir)) != NULL)
		i++;
	closedir(dir);
	return (i);
}

void
    ft_print_dir(char *path)
{    
	DIR			*dir;
	t_dirent	*entry;
	int			i;
	int			len;
	t_path_info	*info;

	len = ft_count_dir(path);
	if (len < 0)
		return ;
	info = (t_path_info *)malloc(sizeof(t_path_info) * len);
	dir = opendir(path);
	i = 0;
	while ( (entry = readdir(dir)) != NULL)
		info[i++] = get_info(entry->d_name);
	closedir(dir);
	
	i = -1;
	while (++i < len)
	{
		ft_printf("%s %s\n", info[i].mode, info[i].name);
	}
	return ;
}

void    ft_ls(char **path, char *flag)
{
    int i;

    i = -1;
    while (path[++i] != 0)
        ft_print_dir(path[i]);
}
