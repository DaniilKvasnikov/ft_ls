/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 03:58:41 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 03:58:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_str_tolower(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
		str[i] = ft_tolower(str[i]);
	return (str);
}
