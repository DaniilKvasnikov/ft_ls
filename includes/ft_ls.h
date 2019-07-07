
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
#include <time.h>

#define PER_DEN -1
#define NOT_FOUND -2
#define ITS_FILE 1

typedef struct  dirent	t_dirent;
typedef struct  stat	t_stat;
typedef struct  passwd	t_passwd;
typedef struct  group	t_group;

typedef struct	s_path_info
{
	char				*mode;
	char				*name;
	t_stat				buff;
	char				*time;
	t_passwd			*owner;
	t_group				*group;
	double				time_a;
	double				time_m;
	double				time_c;
	int					folder;
	int					link;
	char				*link_name;
}				t_path_info;

typedef struct	s_ls_block
{
	t_path_info	*info;
	int			error;
}				t_ls_block;

char			**set_paths(int argc, char **argv);
char			*set_flags(int argc, char **argv);
int				ft_ls(char **path, char *flag);
t_ls_block		ft_print_dir(char *path, char *flag, int *len);
void			ft_print_ls(t_ls_block block, int len, char *flag);

char			*get_print_str(t_path_info *info, int max);

int				is_flag_ls(char *flags, char flag);
int				check_flags_ls(char *flag);
void			ft_quicksort(t_path_info *arr, int low, int high, char *flag);

int				ft_ls_dop(char **path, char *flag, int is_recursion);
char			*ft_stradd_3(char *s1, char *s2, char *s3);

t_path_info		get_info(char *name, char *path, int is_link);

int				is_link(t_stat buff);
int				is_link_path(char *path);
int				is_folder(t_stat buff);
int				is_folder_path(char *path);

void			ft_path_sort(char	**paths);

void			start_recursion_ls(char *path, t_path_info *info, int len,
									char *flag);

int				get_info_st_nlink(t_path_info obj);
int				get_info_st_size(t_path_info obj);
int				get_info_mod(t_path_info obj);
int				get_info_pw_name(t_path_info obj);
int				get_info_gr_name(t_path_info obj);
int				get_info_time(t_path_info obj);
int				get_info_d_name(t_path_info obj);

void			ft_stat(char *path, t_stat *buff);
t_path_info		get_info(char *name, char *path, int is_link);
char			*get_link_name(char *name, char *path);
char			*get_mod(char *mod, t_stat buff);

void			free_path(char **paths);
void			ft_free_ls(t_path_info *info, int len);

int				ft_error_denied(char *path);

int				ft_count_dir_ls(char *path, char *flag);

#endif
