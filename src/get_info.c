
#include "ft_ls.h"

t_path_info
	get_info(char *name, char *path, int is_link)
{
	t_stat		buff;
	t_path_info	res;
	char		*str;
	char		*name_path;

	name_path = ft_stradd_3(path, "/", name);
	ft_stat(name_path, &buff);
	res.link = is_link;
	res.link_name = get_link_name(name, path);
	free(name_path);
	res.time = ft_strdup(ctime(&buff.st_ctime) + 4);
	res.time[12] = '\0';
	res.time_a = buff.st_atime;
	res.time_m = buff.st_mtime;
	res.time_c = buff.st_ctime;
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
