
#include "ft_ls.h"

static int
	get_max_mode(t_path_info *info, int max_l, int (*get)(t_path_info obj))
{
	int max;
	int	tmp;
	int i;

	max = get(info[0]);
	i = -1;
	while (++i <= max_l)
	{
		tmp = get(info[i]);
		if (tmp > max)
			max = tmp;
	}
	return (max);
}

static void
	ft_set_num(char *str, char *num)
{
	ft_strcat(str, num);
	free(num);
}

char
	*get_print_str(t_path_info *info, int max)
{
	char *str;

	str = ft_strnew(200);
	ft_strcat(str, "%-");
	ft_set_num(str, ft_itoa(1 + get_max_mode(info, max, &get_info_mod)));
	ft_strcat(str, "s%");
	ft_set_num(str, ft_itoa(1 + get_max_mode(info, max, &get_info_st_nlink)));
	ft_strcat(str, "d%");
	ft_set_num(str, ft_itoa(1 + get_max_mode(info, max, &get_info_pw_name)));
	ft_strcat(str, "s%");
	ft_set_num(str, ft_itoa(2 + get_max_mode(info, max, &get_info_gr_name)));
	ft_strcat(str, "s%");
	ft_set_num(str, ft_itoa(2 + get_max_mode(info, max, &get_info_st_size)));
	ft_strcat(str, "ld%");
	ft_set_num(str, ft_itoa(1 + get_max_mode(info, max, &get_info_time)));
	ft_strcat(str, "s %-s");
	return (str);
}
