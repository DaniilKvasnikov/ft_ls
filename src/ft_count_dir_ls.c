/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_dir_ls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:26:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:37:42 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	ft_count_dir_ls(char *path, char *flag)
{
	DIR			*dir;
	t_dirent	*entry;
	int			i;
	int			count;

	dir = opendir(path);
	if (!dir)
		return (-1);
	i = 0;
	count = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.' || is_flag_ls(flag, 'a'))
			i++;
		count++;
	}
	closedir(dir);
	if (count > 0 && i == 0)
		return (-1);
	return (i);
}
