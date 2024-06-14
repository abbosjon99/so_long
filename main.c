/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:32:47 by akeldiya          #+#    #+#             */
/*   Updated: 2024/06/14 21:25:05 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

static void	map_loader(t_data *data, char *filename)
{
	int	fd;

	data->map = NULL;
	data->mlx_ptr = NULL;
	fd = open(map_name_check(filename), O_RDONLY);
	data->map = map_opener(fd, data->map);
	close(fd);
	map_checker(data->map);
	data->x = mapwidth(data->map);
	data->y = mapheight(data->map);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	if (argc != 2)
		error_param();
	map_loader(&data, argv[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.x * 64, data.y * 64, "so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &free_data,
		&data);
	mlx_loop(data.mlx_ptr);
	free_data(&data);
}
