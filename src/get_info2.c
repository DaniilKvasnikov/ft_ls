/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:34:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:34:26 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	get_info_time(t_path_info obj)
{
	return (ft_strlen(obj.time));
}

int
	get_info_d_name(t_path_info obj)
{
	return (ft_strlen(obj.name));
}
