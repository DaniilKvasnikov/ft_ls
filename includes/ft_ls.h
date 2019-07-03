
#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
// #include <stdio.h>
#include <sys/types.h>
#include <dirent.h>


char    **set_paths(int argc, char **argv);
char    *set_flags(int argc, char **argv);
void    ft_ls(char **path, char *flag);

#endif
