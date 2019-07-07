/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:35:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:55:22 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	is_link(t_stat buff)
{
	return ((buff.st_mode & S_IFMT) == S_IFLNK);
}

int
	is_link_path(char *path)
{
	t_stat buff;

	lstat(path, &buff);
	return (is_link(buff));
}
