
#include "ft_ls.h"

static void
	change_mod(char *mod, int c)
{
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
