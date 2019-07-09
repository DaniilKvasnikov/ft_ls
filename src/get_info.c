/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:33:53 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/09 07:51:29 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path_info
	get_info(char *name, char *path, int is_link)
{
	t_stat		buff1;
	t_path_info	res;
	char		*str;
	char		*name_path;
	int			res_stat;

	name_path = ft_stradd_3(path, "/", name);
	res_stat = ft_stat(name_path, &buff1);
	free(name_path);
	res.link = is_link;
	res.link_name = get_link_name(name, path);
	res.time = ft_strdup(ctime(&buff1.st_mtime) + 4);
	res.time[12] = '\0';
	res.time_a = buff1.st_atime;
	res.time_m = buff1.st_mtime;
	res.time_c = buff1.st_ctime;
	res.folder = is_folder(buff1);
	str = ft_rebase(buff1.st_mode, 8);
	res.mode = get_mod(str, buff1);
	free(str);
	res.name = ft_strdup(name);
	res.buff = buff1;
	res.owner = getpwuid(buff1.st_uid);
	res.group = getgrgid(buff1.st_gid);
	if (res_stat < 0)
		res.owner = NULL;
	return (res);
}
