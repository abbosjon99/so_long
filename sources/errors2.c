/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:00:30 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/15 12:18:55 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_notreachable(t_map **nodes)
{
	error_main(nodes, 0);
	ft_printf("The collectible, exit and start should be reachable!\n");
	exit(1);
}

void	map_error_wrong_char(t_map **map)
{
	error_main(map, 0);
	ft_printf("There are not allowed characters in a map!\n");
	exit(1);
}

void	map_error_collectives(t_map **map)
{
	error_main(map, 0);
	ft_printf("There should be one P, one E and C's a map!\n");
	exit(1);
}
