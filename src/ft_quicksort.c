

#include "ft_ls.h"

void
	swap_ls(t_path_info *a, t_path_info *b)
{
	t_path_info tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int
	get_cmp_str(char *s1, char *s2)
{
	char    *str1;
	char    *str2;
	int     cmp;

	str1 = ft_str_tolower(ft_strdup(s1));
	str2 = ft_str_tolower(ft_strdup(s2));
	cmp = ft_strcmp(str1, str2);
	free(str1);
	free(str2);
	return (cmp);
}

static int
	ft_cmp(t_path_info *obj1, t_path_info *obj2, char *flag)
{
	int		name;
	double	time_c;
	int		cmp;

	name = get_cmp_str(obj1->name, obj2->name);
	time_c = (obj2->time_c - obj1->time_c);
	if (!is_flag_ls(flag, 't'))
		cmp = name;
	else if (time_c == 0)
		cmp = name;
	else
		cmp = time_c;
	if (is_flag_ls(flag, 'r'))
		return (cmp >= 0);
	else
		return (cmp < 0);
}

static int
	partition(t_path_info *arr, int low, int high, char *flag)
{
	t_path_info pivot;
	int         i;
	int         j;

	pivot = arr[high];  
	i = (low - 1);
	j = low - 1;
	while (++j <= (high - 1))
	{
		if (ft_cmp(&arr[j], &pivot, flag))
		{
			i++;
			swap_ls(&arr[i], &arr[j]);
		}
	}
	swap_ls(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void
	ft_quicksort(t_path_info *arr, int low, int high, char *flag)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high, flag);
		ft_quicksort(arr, low, pi - 1, flag);
		ft_quicksort(arr, pi + 1, high, flag);
	}
}