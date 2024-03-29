/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:30:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 21:18:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_block
	get_info_file(char *path, int *len)
{
	t_path_info	*info;

	*len = 1;
	info = (t_path_info *)malloc(sizeof(t_path_info) * (*len));
	*info = get_info(path, ".", is_link_path(path));
	if (info->owner == NULL || info->group == NULL || ft_strlen(path) == 0)
	{
		ft_putstr_fd("ls: ", 2);
		if (ft_strlen(path) > 0)
			ft_putstr_fd(path, 2);
		else
			ft_putstr_fd("fts_open", 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		ft_free_ls(info, 1);
		return ((t_ls_block){NULL, NOT_FOUND});
	}
	return ((t_ls_block){info, ITS_FILE});
}

t_ls_block
	get_infos(char *path, int *len, char *flag)
{
	t_path_info	*info;
	DIR			*dir;
	int			i;
	t_dirent	*entry;
	t_stat		buff;

	if ((*len = ft_count_dir_ls(path, flag)) == 0)
		return (get_info_file(path, len));
	*len = (*len) * (*len >= 0);
	if ((dir = opendir(path)) == NULL)
	{
		ft_stat(path, &buff);
		if (is_folder(buff))
			return ((t_ls_block){NULL, PER_DEN});
		return (get_info_file(path, len));
	}
	if (*len > 0)
		info = (t_path_info *)malloc(sizeof(t_path_info) * (*len));
	i = 0;
	while ((entry = readdir(dir)) != NULL)
		if (entry->d_name[0] != '.' || is_flag_ls(flag, 'a'))
			info[i++] = get_info(entry->d_name, path, entry->d_type == DT_LNK);
	closedir(dir);
	return ((t_ls_block){info, 0});
}

t_ls_block
	ft_print_dir(char *path, char *flag, int *len)
{
	t_ls_block	block;

	block = get_infos(path, len, flag);
	if (block.info == NULL)
		return (block);
	ft_quicksort(block.info, 0, (*len) - 1, flag);
	return (block);
}
