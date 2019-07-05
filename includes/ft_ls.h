
#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
#include <sys/types.h>
#include <dirent.h>

#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

typedef struct  dirent  t_dirent;
typedef struct  stat    t_stat;
typedef struct  passwd  t_passwd;
typedef struct  group   t_group;

typedef struct	s_path_info
{
	char        *mode;
	t_dirent    *entry;
	t_stat      buff;
	char        *time;
	t_passwd    *owner;
	t_group     *group;
}				t_path_info;

char    **set_paths(int argc, char **argv);
char    *set_flags(int argc, char **argv);
void    ft_ls(char **path, char *flag);

void    ft_quicksort(t_path_info *arr, int low, int high);

#endif
