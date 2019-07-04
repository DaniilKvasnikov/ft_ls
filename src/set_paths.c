
#include "ft_ls.h"

static char
	**this_pos()
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (2));
	res[0] = ft_strdup(".");
	res[1] = 0;
	return (res);
}

char
	**set_paths(int argc, char **argv)
{
	int		i;
	int		j;
	int		len;
	char	**res;

	len = 0;
	i = -1;
	while (++i < argc)
		if (!(argv[i][0] == '-' && ft_strlen(argv[i]) > 1))
			len++;
	if (len > 0)
		res = (char **)malloc(sizeof(char *) * (len + 1));
	else
		return (this_pos());
	i = -1;
	j = -1;
	while (++i < argc)
		if (!(argv[i][0] == '-' && ft_strlen(argv[i]) > 1))
			res[++j] = ft_strdup(argv[i]);
	res[len] = 0;
	return (res);
}