
#include "ft_ls.h"

int
	get_info_time(t_path_info obj)
{
	return (ft_strlen(obj.time));
}

int
	get_info_d_name(t_path_info obj)
{
	return (ft_strlen(obj.name));
}
