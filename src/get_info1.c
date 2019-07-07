
#include "ft_ls.h"

int
	get_info_st_nlink(t_path_info obj)
{
	return (ft_num_len(obj.buff.st_nlink));
}

int
	get_info_st_size(t_path_info obj)
{
	return (ft_num_len(obj.buff.st_size));
}

int
	get_info_mod(t_path_info obj)
{
	return (ft_strlen(obj.mode));
}

int
	get_info_pw_name(t_path_info obj)
{
	return (ft_strlen(obj.owner->pw_name));
}

int
	get_info_gr_name(t_path_info obj)
{
	return (ft_strlen(obj.group->gr_name));
}
