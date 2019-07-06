
#include "ft_ls.h"

int
	num_len(int n)
{
	int i;
	int nbr;

	if (n == 0)
		return  (1);
	nbr = n;
	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

int
	get_info_st_nlink(t_path_info obj)
{
	return (num_len(obj.buff.st_nlink));
}

int
	get_info_st_size(t_path_info obj)
{
	return (num_len(obj.buff.st_size));
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

int
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

char
	*get_print_str(t_path_info *info, int min, int max)
{
	char *str;
	char *num;

	str = ft_strnew(200);
	ft_strcat(str, "%-");
	ft_strcat(str, (num = ft_itoa(1 + get_max_mode(info, max, &get_info_mod))));
	free(num);
	ft_strcat(str, "s%");
	ft_strcat(str, (num = ft_itoa(1 + get_max_mode(info, max, &get_info_st_nlink))));
	free(num);
	ft_strcat(str, "d%");
	ft_strcat(str, (num = ft_itoa(1 + get_max_mode(info, max, &get_info_pw_name))));
	free(num);
	ft_strcat(str, "s%");
	ft_strcat(str, (num = ft_itoa(2 + get_max_mode(info, max, &get_info_gr_name))));
	free(num);
	ft_strcat(str, "s%");
	ft_strcat(str, (num = ft_itoa(2 + get_max_mode(info, max, &get_info_st_size))));
	free(num);
	ft_strcat(str, "ld%");
	ft_strcat(str, (num = ft_itoa(1 + get_max_mode(info, max, &get_info_time))));
	free(num);
	ft_strcat(str, "s %-s\n");
	// ft_printf("[%s]\n", str);
	return (str);
}
