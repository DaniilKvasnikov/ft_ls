
#include "ft_ls.h"


void
	change_mod(char *mod, int c)
{
	int		len;

	if ((c >> 2 & 1) == 0)
		mod[0] = '-';
	if ((c >> 1 & 1) == 0)
		mod[1] = '-';
	if ((c & 1) == 0)
		mod[2] = '-';
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
	change_mod(res + 4, mod[len - 2]);
	change_mod(res + 7, mod[len - 1]);
	return (res);
}
#include <time.h>
t_path_info
	get_info(t_dirent *entry)
{
	struct stat buff;
	t_path_info	res;
	char		*str;

	stat(entry->d_name, &buff);
	res.time = ft_strdup(ctime(&buff.st_mtime) + 4);
	res.time[12] = '\0';
	str = ft_rebase(buff.st_mode, 8);
	res.mode = get_mod(str);
	free(str);
	res.entry = entry;
	res.buff = buff;
	res.owner = getpwuid(buff.st_uid);
	res.group = getpwuid(buff.st_gid);
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
		info[i++] = get_info(entry);
	closedir(dir);
	
	i = -1;
	while (++i < len)
	{
		ft_printf("%s %d %s %s %8ld %s %s\n",
		info[i].mode,
		info[i].buff.st_nlink,
		info[i].owner->pw_name,
		info[i].group->pw_name,
		info[i].buff.st_size,
		info[i].time,
		info[i].entry->d_name);
		free(info[i].mode);
		free(info[i].time);
	}
	free(info);
	return ;
}

void    ft_ls(char **path, char *flag)
{
    int i;

    i = -1;
    while (path[++i] != 0)
        ft_print_dir(path[i]);
}
