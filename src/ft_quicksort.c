

#include "ft_ls.h"

void
	swap(t_path_info *a, t_path_info *b)
{
	t_path_info tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char
	*ft_str_lower(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
		str[i] = ft_tolower(str[i]);
	return (str);
}

static int
	get_cmp_str(char *s1, char *s2)
{
	char    *str1;
	char    *str2;
	int     cmp;

	str1 = ft_str_lower(ft_strdup(s1));
	str2 = ft_str_lower(ft_strdup(s2));
	cmp = ft_strcmp(str1, str2);
	free(str1);
	free(str2);
	return (cmp);
}

static int
	ft_cmp(t_path_info *obj1, t_path_info *obj2, char *flag, int i, int j)
{
	int		name;
	double	time_a;
	double	time_m;
	double	time_c;
	int		ino;
	int		cmp;

	name = get_cmp_str(obj1->name, obj2->name);
	time_a = (obj2->time_a - obj1->time_a);
	time_m = (obj2->time_m - obj1->time_m);
	time_c = (obj2->time_c - obj1->time_c);
	ino = (obj2->buff.st_ino - obj1->buff.st_ino);
	if (!is_flag_ls(flag, 't'))
		cmp = name;
	// else if (time_c == 0 && time_a!= 0)
	// 	cmp = time_a;
	// else if (time_c == 0 && time_m!= 0)
	// 	cmp = time_m;
	else if (time_c == 0)
	{
		cmp = cmp;
	}
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
		if (ft_cmp(&arr[j], &pivot, flag, j, high))
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
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