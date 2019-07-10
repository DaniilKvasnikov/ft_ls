/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:26:55 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:27:18 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	ft_error_denied(char *path, int path_len)
{
	if (path_len == 1)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else
	{
		ft_printf("%s:\n", path);
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	return (0);
}
