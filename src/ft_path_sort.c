/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:30:10 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:40:09 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
	ft_path_sort(char **paths)
{
	t_stat		buff1;
	t_stat		buff2;
	int			i;
	char		*tmp;

	i = -1;
	while (paths[++i] != 0)
	{
		if (paths[i + 1] == 0)
			return ;
		ft_stat(paths[i], &buff1);
		ft_stat(paths[i + 1], &buff2);
		if (is_folder(buff1) && !is_folder(buff2))
		{
			tmp = paths[i];
			paths[i] = paths[i + 1];
			paths[i + 1] = tmp;
			i = -1;
		}
	}
}
