/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:29:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 21:03:25 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
	free_path(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i] != 0)
		free(paths[i]);
	free(paths);
}

void
	ft_free_ls(t_path_info *info, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		free(info[i].mode);
		free(info[i].time);
		free(info[i].name);
		free(info[i].link_name);
	}
	if (len > 0)
	{
		free(info);
	}
}
