/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:30:51 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:39:42 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int
	ft_print_ls_l(t_path_info *info, char *flag, char *str)
{
	if (is_flag_ls(flag, 'l'))
	{
		if (info->name[0] != '.' || is_flag_ls(flag, 'a'))
		{
			ft_printf(str, info->mode, info->buff.st_nlink,
				info->owner->pw_name, info->group->gr_name,
				info->buff.st_size, info->time, info->name);
			if (info->link != 0)
				ft_printf(" -> %s", info->link_name);
			ft_printf("\n");
		}
		return (1);
	}
	return (0);
}

void
	ft_print_total(t_ls_block b, int len, char *flag)
{
	int			total;
	int			i;

	total = 0;
	i = -1;
	while (++i < len)
		total += b.info[i].buff.st_blocks *
			(b.info[i].name[0] != '.' || is_flag_ls(flag, 'a'));
	if (len > 0 && is_flag_ls(flag, 'l'))
		ft_printf("total %d\n", total);
}

void
	ft_print_ls(t_ls_block b, int len, char *flag)
{
	int			i;
	char		*str;

	ft_print_total(b, len, flag);
	if (len > 0)
		str = get_print_str(b.info, len - 1);
	i = -1;
	while (++i < len)
	{
		if (!ft_print_ls_l(&b.info[i], flag, str))
		{
			if (b.info[i].name[0] != '.' || is_flag_ls(flag, 'a'))
				ft_printf("%s", b.info[i].name);
			if ((b.info[i].name[0] != '.' || is_flag_ls(flag, 'a')) &&
					b.error != ITS_FILE)
				ft_putchar('\n');
		}
	}
	if (len > 0)
		free(str);
}
