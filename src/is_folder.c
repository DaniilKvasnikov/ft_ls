/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_folder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:35:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:38:36 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	is_folder(t_stat buff)
{
	return ((buff.st_mode & S_IFMT) == S_IFDIR);
}

int
	is_folder_path(char *path)
{
	t_stat buff;

	stat(path, &buff);
	return (is_folder(buff));
}
