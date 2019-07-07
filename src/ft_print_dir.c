
#include "ft_ls.h"

int
	is_link(char *file_path)
{
	t_stat	sb;

	stat(file_path, &sb);
	if(S_ISREG( sb.st_mode ) != 0)
		return (1);
	else
		return (0);
}

char
	*get_link_ls(char *name, char *path)
{
	char		buf[1024];
	int			len;
	t_path_info	*res;
	char		*name_path;

	name_path = ft_stradd_3(path, "/", name);
	len = readlink(name_path, buf, sizeof(buf)-1);
	free(name_path);
	if (len == -1)
		return (NULL);
	buf[len] = '\0';
	return (ft_strdup(buf));
}

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
	*get_mod(char *mod, t_stat buff)
{
	char	*res;
	int		len;

	res = ft_strdup("drwxrwxrwx");
	if ((buff.st_mode & S_IFMT) == S_IFDIR)
		res[0] = 'd';
	else if ((buff.st_mode & S_IFMT) == S_IFLNK)
		res[0] = 'l';
	else
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
	get_info(char *name, char *path, int is_link)
{
	t_stat		buff;
	t_path_info	res;
	char		*str;
	char		*name_path;

	name_path = ft_stradd_3(path, "/", name);
	if (!is_link)
		stat(name_path, &buff);
	else
		lstat(name_path, &buff);
	res.link = is_link;
	res.link_name = get_link_ls(name, path);
	free(name_path);
	res.time = ft_strdup(ctime(&buff.st_ctime) + 4);
	res.time[12] = '\0';
	res.time_all = buff.st_ctime;
	res.folder = is_folder(buff);
	str = ft_rebase(buff.st_mode, 8);
	res.mode = get_mod(str, buff);
	free(str);
	res.name = ft_strdup(name);
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

t_ls_block
	get_info_file(char *path, int *len)
{
	t_path_info	*info;

	*len = 1;
	info = (t_path_info *)malloc(sizeof(t_path_info) * (*len));
	*info = get_info(path, ".", is_link(path));
	if (info->owner == NULL || info->group == NULL || ft_strlen(path) == 0)
	{
		ft_putstr_fd("ls: ", 2);
		if (ft_strlen(path) > 0)
			ft_putstr_fd(path, 2);
		else
			ft_putstr_fd("fts_open", 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return ((t_ls_block){NULL, NOT_FOUND});
	}
	return ((t_ls_block){info, ITS_FILE});
}

t_ls_block
	get_infos(char *path, int *len, char *flag, int is_l)
{
	t_path_info	*info;
	DIR			*dir;
	int			i;
	t_dirent	*entry;
	t_stat		buff;

	*len = ft_count_dir(path, flag);
	if (*len == 0)
		return (get_info_file(path, len));
	if (*len == -1)
		*len = 0;
	info = (t_path_info *)malloc(sizeof(t_path_info) * (*len));
	dir = opendir(path);
	if (dir == NULL)
	{
		if (!is_link(path))
			stat(path, &buff);
		else
			lstat(path, &buff);
		if (is_folder(buff))
			return ((t_ls_block){NULL, PER_DEN});
		if (*len > 0)
			free(info);
		return (get_info_file(path, len));
	}
	i = 0;
	while ( (entry = readdir(dir)) != NULL)
		if (entry->d_name[0] != '.' || is_flag_ls(flag, 'a'))
			info[i++] = get_info(entry->d_name, path, entry->d_type == DT_LNK);
	closedir(dir);
	return ((t_ls_block){info, 0});
}

t_ls_block
    ft_print_dir(char *path, char *flag, int *len)
{
	t_ls_block	block;

	block = get_infos(path, len, flag, 0);
	if (block.info == NULL)
		return (block);
	ft_quicksort(block.info, 0, (*len) - 1, flag);
	return (block);
}
