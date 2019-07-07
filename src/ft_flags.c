
#include "ft_ls.h"

int	error_log(char *str, char c)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]", 2);
	ft_putstr_fd(" [file ...]\n", 2);
	return (0);
}

int	is_flag_ls(char *flags, char flag)
{
	int	i;

	i = -1;
	while (flags[++i] != '\0')
		if (flags[i] == flag)
			return (1);
	return (0);
}

int	check_flags_ls(char *flag)
{
	int	i;

	i = -1;
	while (flag[++i] != '\0')
		if (flag[i] != 'l' && flag[i] != 'R' && flag[i] != '1' &&
			flag[i] != 'a' && flag[i] != 'r' && flag[i] != 't')
			return (error_log("/bin/ls: illegal option -- ", flag[i]));
	return (1);
}
