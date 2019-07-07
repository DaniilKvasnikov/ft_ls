/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:34:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:39:50 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char
	*get_link_name(char *name, char *path)
{
	char		buf[1024];
	int			len;
	char		*name_path;

	name_path = ft_stradd_3(path, "/", name);
	len = readlink(name_path, buf, sizeof(buf) - 1);
	free(name_path);
	if (len == -1)
		return (NULL);
	buf[len] = '\0';
	return (ft_strdup(buf));
}
