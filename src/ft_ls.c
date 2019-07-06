
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
	res.group = getgrgid(buff.st_gid);
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

int
	get_max_mode(t_path_info *info, int max_l, int (*get)(t_path_info obj))
{
	int max;
	int	tmp;
	int i;

	max = get(info[0]);
	i = -1;
	while (++i <= max_l)
	{
		tmp = get(info[i]);
		if (tmp > max)
			max = tmp;
	}
	return (max);
}

int
	num_len(int n)
{
	int i;
	int nbr;

	nbr = n;
	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

int
	get_info_st_nlink(t_path_info obj)
{
	return (num_len(obj.buff.st_nlink));
}

int
	get_info_st_size(t_path_info obj)
{
	return (num_len(obj.buff.st_size));
}

int
	get_info_mod(t_path_info obj)
{
	return (ft_strlen(obj.mode));
}

int
	get_info_pw_name(t_path_info obj)
{
	return (ft_strlen(obj.owner->pw_name));
}

int
	get_info_gr_name(t_path_info obj)
{
	return (ft_strlen(obj.group->gr_name));
}

int
	get_info_time(t_path_info obj)
{
	return (ft_strlen(obj.time));
}

int
	get_info_d_name(t_path_info obj)
{
	return (ft_strlen(obj.entry->d_name));
}

char
	*ft_stradd(char *dest, char *source)
{
	char	*res;

	res = ft_strnew(ft_strlen(dest) + ft_strlen(source) + 1);
	ft_bzero(res, ft_strlen(dest) + ft_strlen(source) + 1);
	res = ft_strcpy(res, dest);
	// res = ft_strcat(res, source);
	free(dest);
	return (res);
}

char
	*get_print_str(t_path_info *info, int min, int max)
{
	char *str;
	char *num;

	// str = (char *)malloc(sizeof(char) * 1);
	str = ft_strdup("%s %d %s %s %ld %s %s\n");
	ft_printf("[%s]\n", str);
	// ft_stradd(str, "%-");
	// ft_stradd(str, (num = ft_itoa(1 + get_max_mode(info, max, &get_info_mod))));
	// free(num);
	// ft_stradd(str, "s%");
	// ft_stradd(str, (num = ft_itoa(1 + get_max_mode(info, max, &get_info_st_nlink))));
	// free(num);
	// ft_stradd(str, "d%");
	// ft_stradd(str, (num = ft_itoa(1 + get_max_mode(info, max, &get_info_pw_name))));
	// free(num);
	// ft_stradd(str, "s%");
	// ft_stradd(str, (num = ft_itoa(2 + get_max_mode(info, max, &get_info_gr_name))));
	// free(num);
	// ft_stradd(str, "s%");
	// ft_stradd(str, (num = ft_itoa(2 + get_max_mode(info, max, &get_info_st_size))));
	// free(num);
	// ft_stradd(str, "ld%");
	// ft_stradd(str, (num = ft_itoa(1 + get_max_mode(info, max, &get_info_time))));
	// free(num);
	// ft_stradd(str, "s %-");
	// ft_stradd(str, (num = ft_itoa(1 + get_max_mode(info, max, &get_info_d_name))));
	// free(num);
	// ft_stradd(str, "s\n");
	// ft_printf("[%s]\n", str);
	return (str);
}

void
    ft_print_dir(char *path)
{    
	DIR			*dir;
	t_dirent	*entry;
	int			i;
	int			len;
	t_path_info	*info;
	char		*str;

	len = ft_count_dir(path);
	if (len < 0)
		return ;
	info = (t_path_info *)malloc(sizeof(t_path_info) * len);
	dir = opendir(path);
	i = 0;
	while ( (entry = readdir(dir)) != NULL)
	{
		ft_printf("%s\n", entry->d_name);
		info[i++] = get_info(entry);
	}
	closedir(dir);
	// ft_quicksort(info, 0, len - 1);
	i = -1;
	str = get_print_str(info, 0, len - 1);
	while (++i < len)
	{
		// ft_printf("%s\n", info[i].entry->d_name);//"%s %d %s %s %ld %s %s\n"
		ft_printf(str,
		info[i].mode,
		info[i].buff.st_nlink,
		info[i].owner->pw_name,
		info[i].group->gr_name,
		info[i].buff.st_size,
		info[i].time,
		info[i].entry->d_name);
		free(info[i].mode);
		free(info[i].time);
	}
	// free(str);
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
