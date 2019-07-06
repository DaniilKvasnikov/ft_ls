
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

char
	*ft_stradd_3(char *s1, char *s2, char *s3)
{
	char	*res;

	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	ft_bzero(res, ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	ft_strcat(res, s3);
	return (res);
}

t_path_info
	get_info(char *name, char *path)
{
	t_stat		buff;
	t_path_info	res;
	char		*str;
	char		*name_path;

	name_path = ft_stradd_3(path, "/", name);
	stat(name_path, &buff);
	free(name_path);
	res.time_all = buff.st_mtime;
	res.time = ft_strdup(ctime(&buff.st_mtime) + 4);
	res.time[12] = '\0';
	res.folder = is_folder(buff);
	str = ft_rebase(buff.st_mode, 8);
	res.mode = get_mod(str);
	free(str);
	res.name = name;
	res.buff = buff;
	res.owner = getpwuid(buff.st_uid);
	res.group = getgrgid(buff.st_gid);
	return (res);
}

static int
	ft_count_dir(char *path, char *flag)
{
	DIR			*dir;
	t_dirent	*entry;
	int			i;
	int			len;
	int			count;

	dir = opendir(path);
	if (!dir)
		return (-1);
	i = 0;
	count = 0;
	while ( (entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.' || is_flag_ls(flag, 'a'))
			i++;
		count++;
	}
	closedir(dir);
	if (count > 0 && i == 0)
		return (-1);
	return (i);
}

t_path_info
	*get_info_file(char *path, int *len)
{
	t_path_info	*info;

	*len = 1;
	info = (t_path_info *)malloc(sizeof(t_path_info) * (*len));
	*info = get_info(path, ".");
	if (info->owner == NULL || info->group == NULL)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (NULL);
	}
	return (info);
}

t_ls_block
	get_infos(char *path, int *len, char *flag)
{
	t_path_info	*info;
	DIR			*dir;
	int			i;
	t_dirent	*entry;
	t_stat		buff;

	*len = ft_count_dir(path, flag);
	if (*len == 0)
		return ((t_ls_block){get_info_file(path, len), 0});
	if (*len == -1)
		*len = 0;
	info = (t_path_info *)malloc(sizeof(t_path_info) * (*len));
	dir = opendir(path);
	if (dir == NULL)
	{
		stat(path, &buff);
		if (is_folder(buff))
			return ((t_ls_block){NULL, PER_DEN});
		if (*len > 0)
			free(info);
		return ((t_ls_block){get_info_file(path, len), ITS_FILE});
	}
	i = 0;
	while ( (entry = readdir(dir)) != NULL)
		if (entry->d_name[0] != '.' || is_flag_ls(flag, 'a'))
			info[i++] = get_info(entry->d_name, path);
	closedir(dir);
	return ((t_ls_block){info, 0});
}

t_ls_block
    ft_print_dir(char *path, char *flag, int *len)
{
	t_ls_block	block;

	block = get_infos(path, len, flag);
	if (block.info == NULL)
		return (block);
	ft_quicksort(block.info, 0, (*len) - 1, flag);
	return (block);
}
