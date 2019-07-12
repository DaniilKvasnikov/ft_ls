/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:27:47 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/12 12:59:42 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void
	ft_print_body(char *path, char *flag, int is_recursion, int path_len, int i)
{
	t_ls_block	block;
	int			len;

	block = ft_print_dir(path, flag, &len);
	if (block.error == 0)
	{
		if (is_recursion)
			ft_printf("\n%s:\n", path);
		else if ((is_folder_path(path) && (path_len > 1)))
		{
			if (i > 0)
				ft_printf("\n%s:\n", path);
			else
				ft_printf("%s:\n", path);
		}
		ft_print_ls(block, len, flag);
		if (is_flag_ls(flag, 'R'))
			start_recursion_ls(path, block.info, len, flag);
		ft_free_ls(block.info, len);
	}
	else if (block.error == PER_DEN)
		ft_error_denied(path, path_len);
	else if (block.error == ITS_FILE)
	{
		ft_print_ls(block, len, flag);
		ft_free_ls(block.info, len);
	}
}

int
	ft_ls_dop(char **path, char *flag, int is_recursion)
{
	int			i;
	int			path_len;

	if (!check_flags_ls(flag))
		return (1);
	i = -1;
	path_len = 0;
	while (path[++i] != 0)
		++path_len;
	i = -1;
	while (path[++i] != 0)
		ft_print_body(path[i], flag, is_recursion, path_len, i);
	return (0);
}

int
	ft_ls(char **path, char *flag)
{
	return (ft_ls_dop(path, flag, 0));
}
