/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:36:42 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:38:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char
	**this_pos(void)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (2));
	res[0] = ft_strdup(".");
	res[1] = 0;
	return (res);
}

static int
	ft_get_len_path(int argc, char **argv)
{
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (++i < argc)
		if (!(argv[i][0] == '-' && ft_strlen(argv[i]) > 1))
			len++;
	return (len);
}

char
	**set_paths(int argc, char **argv)
{
	int		i;
	int		j;
	int		len;
	char	**res;

	len = ft_get_len_path(argc, argv);
	if (len > 0)
		res = (char **)malloc(sizeof(char *) * (len + 1));
	else
		return (this_pos());
	i = -1;
	j = -1;
	while (++i < argc)
		if (!(argv[i][0] == '-' && ft_strlen(argv[i]) > 1))
			res[++j] = ft_strdup(argv[i]);
	res[len] = 0;
	return (res);
}
