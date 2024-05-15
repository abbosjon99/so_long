/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:32:47 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/15 12:49:10 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		fd;
	t_map	*map;

	map = NULL;
	fd = open("map.ber", O_RDONLY);
	map = map_opener(fd, map);
	close(fd);
	map_checker(map);
	free_nodes(&map);
	return (0);
}
