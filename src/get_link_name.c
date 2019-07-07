
#include "ft_ls.h"

char
	*get_link_name(char *name, char *path)
{
	char		buf[1024];
	int			len;
	char		*name_path;

	name_path = ft_stradd_3(path, "/", name);
	len = readlink(name_path, buf, sizeof(buf)-1);
	free(name_path);
	if (len == -1)
		return (NULL);
	buf[len] = '\0';
	return (ft_strdup(buf));
}
