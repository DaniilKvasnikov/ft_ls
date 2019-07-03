
#include "ft_ls.h"

void
    ft_print_dir(char *path)
{    
	DIR *dir;
	struct dirent *entry;
	int i;

	dir = opendir(path);
	if (!dir) {
		ft_printf("diropen");
		return ;
	};

	i = 0;
	while ( (entry = readdir(dir)) != NULL) {
		if (i != 0)
			ft_printf(" ");
		if (entry->d_name[0] != '.')
		{
			ft_printf("%s", entry->d_name);
			i++;
		}
	}
    ft_putchar('\n');

	closedir(dir);
	return ;
}

void    ft_ls(char **path, char *flag)
{
    int i;

    i = -1;
    while (path[++i] != 0)
        ft_print_dir(path[i]);
}
