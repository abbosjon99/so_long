/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:32:47 by akeldiya          #+#    #+#             */
/*   Updated: 2024/06/18 19:18:39 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_loader(t_data *data, char *filename)
{
	int	fd;

	data->map = NULL;
	data->mlx_ptr = NULL;
	fd = open(map_name_check(filename), O_RDONLY);
	if (fd < 0)
		map_error_open();
	data->map = map_opener(fd, data->map);
	close(fd);
	map_checker(data->map);
	data->x = mapwidth(data->map);
	data->y = mapheight(data->map);
}

// Loads the xpm image and if anything is wrong shows the error
static void	img_loader(t_data *data)
{
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/grass.xpm",
			&(int){64}, &(int){64});
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/wall.xpm",
			&(int){64}, &(int){64});
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/player.xpm",
			&(int){64}, &(int){64});
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/food.xpm",
			&(int){64}, &(int){64});
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/finish.xpm",
			&(int){64}, &(int){64});
	if (!((data->textures[0] && data->textures[1]) && (data->textures[2]
				&& (data->textures[3] && data->textures[4]))))
	{
		error_texture(data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_param();
	map_loader(&data, argv[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (free_nodes(data.map), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.x * 64, data.y * 64,
			"so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), free_nodes(data.map), 1);
	img_loader(&data);
	mlx_hook(data.win_ptr, 02, 1L << 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, &free_data, &data);
	mlx_loop(data.mlx_ptr);
	free_data(&data);
}
