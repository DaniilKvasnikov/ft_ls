
#include "ft_ls.h"

int
	ft_error_denied(char *path)
{
	ft_printf("%s:\n", path);
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	return (0);
}
