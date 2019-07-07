/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:16:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 00:16:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_stradd_3(char *s1, char *s2, char *s3)
{
	char	*res;

	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	ft_bzero(res, ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	ft_strcat(res, s3);
	return (res);
}
