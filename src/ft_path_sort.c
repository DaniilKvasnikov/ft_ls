/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:30:10 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/12 14:44:27 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	swap_ls(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int
	ft_cmp(char *obj1, char *obj2, char *flag)
{
	int		name;
	t_stat	buff1;
	t_stat	buff2;
	double	time_c;
	int		cmp;

	ft_stat(obj1, &buff1);
	ft_stat(obj2, &buff2);
	name = ft_strcmp(obj2, obj1);
	time_c = (buff1.st_mtime - buff2.st_mtime);
	if (!is_flag_ls(flag, 't'))
		cmp = name;
	else if (time_c == 0)
		cmp = name;
	else
		cmp = time_c;
	if (is_flag_ls(flag, 'r'))
		return (cmp <= 0);
	else
		return (cmp > 0);
}

static int
	partition(char **paths, int low, int high, char *flag)
{
	char		*pivot;
	int			i;
	int			j;

	pivot = paths[high];
	i = (low - 1);
	j = low - 1;
	while (++j <= (high - 1))
	{
		if (ft_cmp(paths[j], pivot, flag))
		{
			i++;
			swap_ls(&paths[i], &paths[j]);
		}
	}
	swap_ls(&paths[i + 1], &paths[high]);
	return (i + 1);
}

static void
	ft_quicksort_path(char **paths, int low, int high, char *flag)
{
	int pi;

	if (low < high)
	{
		pi = partition(paths, low, high, flag);
		ft_quicksort_path(paths, low, pi - 1, flag);
		ft_quicksort_path(paths, pi + 1, high, flag);
	}
}

void
	ft_path_sort(char **paths, char *flag)
{
	int			i;
	int			len;
	char		*tmp;

	len = -1;
	while (paths[++len] != 0)
		;
	i = -1;
	while (++i < len)
	{
		if (i == (len - 1))
			break ;
		if (is_folder_path(paths[i]) && !is_folder_path(paths[i + 1]))
		{
			swap_ls(&paths[i], &paths[i + 1]);
			i = -1;
		}
	}
	i = -1;
	while (paths[++i] != 0 && !is_folder_path(paths[i]))
		;
	if (i > 0)
		ft_quicksort_path(paths, 0, i - 1, flag);
	if (i < len)
		ft_quicksort_path(paths, i, len - 1, flag);
}
