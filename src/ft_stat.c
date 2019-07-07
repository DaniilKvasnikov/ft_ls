/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:31:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:54:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
	ft_stat(char *path, t_stat *buff)
{
	if (!is_link_path(path))
		stat(path, buff);
	else
		lstat(path, buff);
}
