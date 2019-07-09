/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:31:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/09 07:51:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	ft_stat(char *path, t_stat *buff)
{
	if (!is_link_path(path))
		return (stat(path, buff));
	else
		return (lstat(path, buff));
}
