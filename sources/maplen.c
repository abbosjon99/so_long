/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maplen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:05:55 by akeldiya          #+#    #+#             */
/*   Updated: 2024/06/14 21:24:34 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mapwidth(t_map *map)
{
	return (ft_strlen(map->mtxt));
}

int	mapheight(t_map *map)
{
	int	i;

	i = 1;
	while (map->nxt != NULL)
	{
		map = map->nxt;
		i++;
	}
	return (i);
}
